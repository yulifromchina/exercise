#include "QueueSystem.h"

QueueSystem::~QueueSystem()
{

}


void QueueSystem::event_sort()
{
	//时间小的排在队列尾部，便于pop_back()
	std::sort(v_event.begin(), v_event.end(), [](const std::shared_ptr<Event> & e1, const std::
		shared_ptr<Event> & e2) {return e1->get_time() > e2->get_time(); });
}


double QueueSystem::get_avg_customer_duration()
{
	return avg_customer_duration_;
}


double QueueSystem::get_avg_customer_num()
{
	return avg_customer_num_;
}


void QueueSystem::simulate(int simulate_times)
{
	//设置时间数种子
	std::srand((unsigned)std::time(0));

	simulate_time_ = simulate_times;

	for (int i = 0; i < simulate_times; i++)
	{
		run();
	}

	//平均每个顾客的服务时间 = 总的服务时间 / 服务过的顾客数
	avg_customer_duration_ = all_customer_duartion_ / all_customer_num;

	//平均每分钟到达的顾客 = 总的顾客数 / (银行营业时间 * 模拟次数)
	avg_customer_num_ = all_customer_num / (open_time_ * simulate_time_);

}


std::shared_ptr<Event> QueueSystem::get_current_event_()
{
	return current_event_;
}


void QueueSystem::init()
{
	//生成一个到达事件
	current_event_= std::make_shared<Event>(arrive);

	//事件发生时间为first_arrive_time分钟内
	double occur_time = Random::uniform(first_arrive_time);
	current_event_->set_time(occur_time);
}



void QueueSystem::end()
{
	//所有窗口设置为空闲
	for (int i = 0; i < v_server_window.size(); i++)
	{
		v_server_window[i]->set_window_idle();
	}

	//顾客等待队列清空
	v_customer_wait.clear();

	//事件队列清空
	v_event.clear();

}


void QueueSystem::run()
{
	init();

	while (current_event_)
	{
		//如果当前事件是顾客到达
		if (current_event_->get_event_type() == arrive)
		{
			customer_arrive();
		}
		//如果当前事件是顾客离开
		else
		{
			customer_leave();
		}

		//处理过程中也会产生新事件
		create_event();

		//如果事件队列非空，则事件出队
		if (!v_event.empty())
		{
			current_event_ = v_event[v_event.size()-1];
			v_event.pop_back();
		}
		else
		{
			current_event_ = NULL;
		}
	}

	end();
}


void QueueSystem::customer_arrive()
{
	//顾客数+1
	all_customer_num++;

	//在处理顾客事件过程中，也会产生新事件
	//create_event();

	//判断是否有空闲服务窗口
	int idle_window = get_idle_window();

	//没有空闲窗口则插入顾客等待队列
	if (idle_window == -1)
	{

		//将顾客插入等待队列中
		v_customer_wait.push_back(std::make_shared<Customer>(current_event_->get_time()));

		
	}
	else
	//有空闲窗口则直接处理
	{

		//假设最长max_served_time分钟服务完
		double duration_time = Random::uniform(max_served_time);

		//必须在银行关门前服务完
		if (current_event_->get_time() + duration_time > open_time_)
		{
			duration_time = open_time_ - current_event_->get_time();
		}

		//总服务时间累加
		all_customer_duartion_ += duration_time;

		//窗口设置为忙
		v_server_window[idle_window]->set_window_busy();

		//将离开事件插入队列
		std::shared_ptr<Event> new_event = std::make_shared<Event>(leave);
		new_event->set_time(current_event_->get_time() + duration_time);
		new_event->set_window_num(idle_window);

		v_event.push_back(new_event);
		event_sort();
	}
	
}


void QueueSystem::customer_leave()
{
	//在处理顾客事件过程中，也会产生新事件
	//create_event();

	//离开的窗口设置为空闲
	int window_num = current_event_->get_window_num();
	v_server_window[window_num]->set_window_idle();

	//从队列中弹出一个顾客，生成顾客到达事件插入队列，但到达事件更改为现在
	if (!v_customer_wait.empty())
	{
		v_customer_wait.pop_back();
		
		std::shared_ptr<Event> new_event = std::make_shared<Event>(arrive);
		new_event->set_time(current_event_->get_time());
		v_event.push_back(new_event);
		event_sort();

		//生成arrive事件会让总顾客数++，而唤醒的顾客是之前已经到达过的，所以先减1，
		all_customer_num--;

	}
	
}


void QueueSystem::create_event()
{
	//创建新的顾客到达事件
	std::shared_ptr<Event> new_event = std::make_shared<Event>(arrive);

	//如果事件在银行关闭之前发生，则添加进事件队列
	double time_gap = Random::uniform(max_next_arrive_time);
	if (current_event_->get_time() + time_gap < open_time_)
	{
		new_event->set_time(current_event_->get_time() + time_gap);
		v_event.push_back(new_event);

		//添加新事件后，对事件队列进行排序
		event_sort();
	}

	//否则丢弃
	{
		//什么也不做
	}

	
}


int QueueSystem::get_idle_window()
{
	//每次从上次结束的位置开始查询
	static int last_visit = -1;

	for (int i = ((last_visit+1) % server_window_num_); i < server_window_num_; i++)
	{
		if (v_server_window[i]->get_window_status() == idle)
		{
			last_visit = i;
			return i;
		}
	}

	//没有空闲窗口，返回-1
	return -1;
}