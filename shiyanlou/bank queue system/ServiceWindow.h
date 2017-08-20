#pragma once

//窗口只有两种状态，空闲或者忙
enum window_status {idle, busy};

//服务窗口类
class ServiceWindow
{
public:

	//创建窗口时，默认窗口时空闲的
	ServiceWindow(window_status ws = idle) :window_status_(ws) {}

	~ServiceWindow();

	//设置窗口状态为空闲
	void set_window_idle();

	//设置窗口状态为忙
	void set_window_busy();

	//获取当前窗口状态
	window_status get_window_status();

private:

	//窗口当前状态
	window_status window_status_;
};

