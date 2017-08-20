#pragma once
#include <vector>
#include <memory>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <functional>
#include "Customer.h"
#include "ServiceWindow.h"
#include "Event.h"
#include "Random.h"
#include "const_varible.h"


//排队系统类，运行整个模拟过程
class QueueSystem
{
	//用于测试的函数
	friend  void test_print_event(QueueSystem & qs);

public:
	QueueSystem(double open_time, int server_window_num) :open_time_(open_time), server_window_num_(server_window_num)
	{
		//窗口全部初始化为idle
		for (int i = 0; i < server_window_num; i++)
		{
			v_server_window.push_back(std::make_shared<ServiceWindow>(idle));
		}

		//变量全部初始化为0
		simulate_time_ = 0;
		all_customer_duartion_ = 0;
		avg_customer_duration_ = 0;
		all_customer_num = 0;
		avg_customer_num_ = 0;
	}

	~QueueSystem();

	//排序函数,把事件按照时间先后顺序排列
	void event_sort();

	//获取平均每顾客服务时间
	double get_avg_customer_duration();

	//获取每分钟平均顾客达到数
	double get_avg_customer_num();

	//运行指定次数的模拟
	void simulate(int simulate_times);

	//运行单次模拟
	void run();

	//单次运行前的工作
	void init();

	//单次运行后的工作
	void end();

	//获取当前正在发生的事件
	std::shared_ptr<Event> get_current_event_();

	//顾客到达事件的处理
	void customer_arrive();

	//顾客离开时间的处理
	void customer_leave();

	//产生新的事件
	void create_event();

	//查找空闲服务窗口
	int get_idle_window();

private:
	//窗口队列
	std::vector<std::shared_ptr<ServiceWindow>> v_server_window;

	//事件队列
	std::vector<std::shared_ptr<Event>> v_event;

	//顾客等待队列
	std::vector<std::shared_ptr<Customer>> v_customer_wait;

	//银行营业时间
	double open_time_;

	//银行窗口数
	int server_window_num_;

	//模拟次数
	int simulate_time_;

	//总服务时间
	double all_customer_duartion_;

	//平均每顾客服务时间
	double avg_customer_duration_;

	//总顾客数
	int all_customer_num;

	//平均每分钟顾客达到数
	double avg_customer_num_;

	//当前事件
	std::shared_ptr<Event> current_event_;



};