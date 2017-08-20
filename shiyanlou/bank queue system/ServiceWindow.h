#pragma once

//����ֻ������״̬�����л���æ
enum window_status {idle, busy};

//���񴰿���
class ServiceWindow
{
public:

	//��������ʱ��Ĭ�ϴ���ʱ���е�
	ServiceWindow(window_status ws = idle) :window_status_(ws) {}

	~ServiceWindow();

	//���ô���״̬Ϊ����
	void set_window_idle();

	//���ô���״̬Ϊæ
	void set_window_busy();

	//��ȡ��ǰ����״̬
	window_status get_window_status();

private:

	//���ڵ�ǰ״̬
	window_status window_status_;
};

