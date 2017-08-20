#pragma once
#include "head.h"
class FormatDate
{
public:
	FormatDate() = default;
	FormatDate(std::string sdate);
	~FormatDate();
	void GetCurDate();
private:
	unsigned year;
	unsigned month;
	unsigned day;
};




