#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>


//随机数发生器类
class Random
{
public:
	Random();

	~Random();

	//产生一个[0, max)均匀分布的随机数
	static double uniform(int max = 1);
};

