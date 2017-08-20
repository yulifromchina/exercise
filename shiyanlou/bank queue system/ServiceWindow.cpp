#include "ServiceWindow.h"

ServiceWindow::~ServiceWindow()
{

}


void ServiceWindow::set_window_idle()
{
	window_status_ = idle;
}


void ServiceWindow::set_window_busy()
{
	window_status_ = busy;
}


window_status ServiceWindow::get_window_status()
{
	return window_status_;
}