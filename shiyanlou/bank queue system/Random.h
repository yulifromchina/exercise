#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>


//�������������
class Random
{
public:
	Random();

	~Random();

	//����һ��[0, max)���ȷֲ��������
	static double uniform(int max = 1);
};

