#pragma once
#include "ServiceWindow.h"


//�˿���
class Customer
{
public:
	Customer(double arrive_time) :arrive_time_(arrive_time), duration_(0){}

	//���ù˿͵ķ���ʱ��
	void set_duration(double duration);

	//��ȡ�˿͵ķ���ʱ��
	double get_duration_time();

	//��ȡ�˿͵ĵ���ʱ��
	double get_arrive_time();

	//���÷���˿͵Ĵ��ں�
	//void set_window_num(int num);

	////��ȡ����˿͵Ĵ��ں�
	//int get_window_num();

	~Customer();

private:

	//�˿͵����ʱ��
	double arrive_time_;

	//�˿ͷ����ʱ��
	double duration_;

	////����д��ڷ���Ļ��������Ӧ�Ĵ��ں�
	//int window_num_;

};

