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


//�Ŷ�ϵͳ�࣬��������ģ�����
class QueueSystem
{
	//���ڲ��Եĺ���
	friend  void test_print_event(QueueSystem & qs);

public:
	QueueSystem(double open_time, int server_window_num) :open_time_(open_time), server_window_num_(server_window_num)
	{
		//����ȫ����ʼ��Ϊidle
		for (int i = 0; i < server_window_num; i++)
		{
			v_server_window.push_back(std::make_shared<ServiceWindow>(idle));
		}

		//����ȫ����ʼ��Ϊ0
		simulate_time_ = 0;
		all_customer_duartion_ = 0;
		avg_customer_duration_ = 0;
		all_customer_num = 0;
		avg_customer_num_ = 0;
	}

	~QueueSystem();

	//������,���¼�����ʱ���Ⱥ�˳������
	void event_sort();

	//��ȡƽ��ÿ�˿ͷ���ʱ��
	double get_avg_customer_duration();

	//��ȡÿ����ƽ���˿ʹﵽ��
	double get_avg_customer_num();

	//����ָ��������ģ��
	void simulate(int simulate_times);

	//���е���ģ��
	void run();

	//��������ǰ�Ĺ���
	void init();

	//�������к�Ĺ���
	void end();

	//��ȡ��ǰ���ڷ������¼�
	std::shared_ptr<Event> get_current_event_();

	//�˿͵����¼��Ĵ���
	void customer_arrive();

	//�˿��뿪ʱ��Ĵ���
	void customer_leave();

	//�����µ��¼�
	void create_event();

	//���ҿ��з��񴰿�
	int get_idle_window();

private:
	//���ڶ���
	std::vector<std::shared_ptr<ServiceWindow>> v_server_window;

	//�¼�����
	std::vector<std::shared_ptr<Event>> v_event;

	//�˿͵ȴ�����
	std::vector<std::shared_ptr<Customer>> v_customer_wait;

	//����Ӫҵʱ��
	double open_time_;

	//���д�����
	int server_window_num_;

	//ģ�����
	int simulate_time_;

	//�ܷ���ʱ��
	double all_customer_duartion_;

	//ƽ��ÿ�˿ͷ���ʱ��
	double avg_customer_duration_;

	//�ܹ˿���
	int all_customer_num;

	//ƽ��ÿ���ӹ˿ʹﵽ��
	double avg_customer_num_;

	//��ǰ�¼�
	std::shared_ptr<Event> current_event_;



};