#include "QueueSystem.h"

QueueSystem::~QueueSystem()
{

}


void QueueSystem::event_sort()
{
	//ʱ��С�����ڶ���β��������pop_back()
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
	//����ʱ��������
	std::srand((unsigned)std::time(0));

	simulate_time_ = simulate_times;

	for (int i = 0; i < simulate_times; i++)
	{
		run();
	}

	//ƽ��ÿ���˿͵ķ���ʱ�� = �ܵķ���ʱ�� / ������Ĺ˿���
	avg_customer_duration_ = all_customer_duartion_ / all_customer_num;

	//ƽ��ÿ���ӵ���Ĺ˿� = �ܵĹ˿��� / (����Ӫҵʱ�� * ģ�����)
	avg_customer_num_ = all_customer_num / (open_time_ * simulate_time_);

}


std::shared_ptr<Event> QueueSystem::get_current_event_()
{
	return current_event_;
}


void QueueSystem::init()
{
	//����һ�������¼�
	current_event_= std::make_shared<Event>(arrive);

	//�¼�����ʱ��Ϊfirst_arrive_time������
	double occur_time = Random::uniform(first_arrive_time);
	current_event_->set_time(occur_time);
}



void QueueSystem::end()
{
	//���д�������Ϊ����
	for (int i = 0; i < v_server_window.size(); i++)
	{
		v_server_window[i]->set_window_idle();
	}

	//�˿͵ȴ��������
	v_customer_wait.clear();

	//�¼��������
	v_event.clear();

}


void QueueSystem::run()
{
	init();

	while (current_event_)
	{
		//�����ǰ�¼��ǹ˿͵���
		if (current_event_->get_event_type() == arrive)
		{
			customer_arrive();
		}
		//�����ǰ�¼��ǹ˿��뿪
		else
		{
			customer_leave();
		}

		//���������Ҳ��������¼�
		create_event();

		//����¼����зǿգ����¼�����
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
	//�˿���+1
	all_customer_num++;

	//�ڴ���˿��¼������У�Ҳ��������¼�
	//create_event();

	//�ж��Ƿ��п��з��񴰿�
	int idle_window = get_idle_window();

	//û�п��д��������˿͵ȴ�����
	if (idle_window == -1)
	{

		//���˿Ͳ���ȴ�������
		v_customer_wait.push_back(std::make_shared<Customer>(current_event_->get_time()));

		
	}
	else
	//�п��д�����ֱ�Ӵ���
	{

		//�����max_served_time���ӷ�����
		double duration_time = Random::uniform(max_served_time);

		//���������й���ǰ������
		if (current_event_->get_time() + duration_time > open_time_)
		{
			duration_time = open_time_ - current_event_->get_time();
		}

		//�ܷ���ʱ���ۼ�
		all_customer_duartion_ += duration_time;

		//��������Ϊæ
		v_server_window[idle_window]->set_window_busy();

		//���뿪�¼��������
		std::shared_ptr<Event> new_event = std::make_shared<Event>(leave);
		new_event->set_time(current_event_->get_time() + duration_time);
		new_event->set_window_num(idle_window);

		v_event.push_back(new_event);
		event_sort();
	}
	
}


void QueueSystem::customer_leave()
{
	//�ڴ���˿��¼������У�Ҳ��������¼�
	//create_event();

	//�뿪�Ĵ�������Ϊ����
	int window_num = current_event_->get_window_num();
	v_server_window[window_num]->set_window_idle();

	//�Ӷ����е���һ���˿ͣ����ɹ˿͵����¼�������У��������¼�����Ϊ����
	if (!v_customer_wait.empty())
	{
		v_customer_wait.pop_back();
		
		std::shared_ptr<Event> new_event = std::make_shared<Event>(arrive);
		new_event->set_time(current_event_->get_time());
		v_event.push_back(new_event);
		event_sort();

		//����arrive�¼������ܹ˿���++�������ѵĹ˿���֮ǰ�Ѿ�������ģ������ȼ�1��
		all_customer_num--;

	}
	
}


void QueueSystem::create_event()
{
	//�����µĹ˿͵����¼�
	std::shared_ptr<Event> new_event = std::make_shared<Event>(arrive);

	//����¼������йر�֮ǰ����������ӽ��¼�����
	double time_gap = Random::uniform(max_next_arrive_time);
	if (current_event_->get_time() + time_gap < open_time_)
	{
		new_event->set_time(current_event_->get_time() + time_gap);
		v_event.push_back(new_event);

		//������¼��󣬶��¼����н�������
		event_sort();
	}

	//������
	{
		//ʲôҲ����
	}

	
}


int QueueSystem::get_idle_window()
{
	//ÿ�δ��ϴν�����λ�ÿ�ʼ��ѯ
	static int last_visit = -1;

	for (int i = ((last_visit+1) % server_window_num_); i < server_window_num_; i++)
	{
		if (v_server_window[i]->get_window_status() == idle)
		{
			last_visit = i;
			return i;
		}
	}

	//û�п��д��ڣ�����-1
	return -1;
}