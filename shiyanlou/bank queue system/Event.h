#pragma once
#include <iostream>
#include <memory>
#include <assert.h>
#include "Customer.h"


//�¼������ͣ��˿͵�����뿪
enum event_type {arrive, leave};


//�¼���
class Event
{

public:
	//���캯����Ĭ���¼�����
	Event(event_type type = arrive) :type_(type), time_(0){}

	//�����¼�����ʱ��
	void set_time(double occur_time);

	//��ȡ�¼�����ʱ��
	double get_time();

	//�����¼���Ӧ�˿�
	//void set_customer(std::shared_ptr<Customer>);

	//��ȡ�¼���Ӧ�Ĺ˿�
	//std::shared_ptr<Customer> get_customer();

	//��ȡ�¼�����
	event_type get_event_type();

	//����ʱ���Ӧ�Ĵ��ں�
	void set_window_num(int num);

	//��ȡ�¼���Ӧ�Ĵ��ں�
	int get_window_num();


	~Event();


private:

	//�¼�����
	event_type type_;

	//�¼�������ʱ��
	double time_;

	////���¼���Ӧ�Ĺ˿�
	//std::shared_ptr<Customer> event_customer_;

	//�¼�ʹ�õĴ��ں�
	int window_num;
};

