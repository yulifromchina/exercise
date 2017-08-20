#pragma once
#include <iostream>
#include <memory>
#include <assert.h>
#include "Customer.h"


//事件的类型，顾客到达和离开
enum event_type {arrive, leave};


//事件类
class Event
{

public:
	//构造函数，默认事件到达
	Event(event_type type = arrive) :type_(type), time_(0){}

	//设置事件发生时间
	void set_time(double occur_time);

	//获取事件发生时间
	double get_time();

	//设置事件对应顾客
	//void set_customer(std::shared_ptr<Customer>);

	//获取事件对应的顾客
	//std::shared_ptr<Customer> get_customer();

	//获取事件类型
	event_type get_event_type();

	//设置时间对应的窗口号
	void set_window_num(int num);

	//获取事件对应的窗口号
	int get_window_num();


	~Event();


private:

	//事件类型
	event_type type_;

	//事件发生的时间
	double time_;

	////该事件对应的顾客
	//std::shared_ptr<Customer> event_customer_;

	//事件使用的窗口号
	int window_num;
};

