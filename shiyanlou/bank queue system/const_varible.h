#pragma once

const int simulate_times = 100;//模拟次数
const int window_num = 4;     //银行的窗口数目
const double  open_time = 240; //单位为分钟，银行营业时间，题目中为8点至12点
const int  max_served_time = 30;//单个顾客的服务时间最多为20分钟
const int  max_next_arrive_time = 60;//至少60分钟内产生一个新顾客
const int  first_arrive_time = 10;//开始运行1分钟内产生第一个事件