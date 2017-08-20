#include "FormatDate.h"



FormatDate::FormatDate(std::string sdate)
{
	std::regex e1("\\s*(\\w+)\\s+(\\d+)\\s*[,]\\s*(\\d{4})\\s*");
	//test:"January 1, 1900"

	std::regex e2("\\s*(\\d+)[\/](\\d+)[\/](\\d{4})\\s*");
	//test:"1/1/1900"

	std::regex e3("\\s*(\\w+)\\s+(\\d+)\\s+(\\d{4})\\s*");
	//test:"Jan 1 1900"

	std::smatch sm;
	std::string temp_year, temp_month, temp_day;
	if (regex_match(sdate, e1))
	{
		regex_match(sdate, sm, e1);
		assert(sm.size()!=0);
		temp_month = sm[1];
		temp_day = sm[2];
		temp_year = sm[3];
	}
	else if (regex_match(sdate, e2))
	{
		regex_match(sdate, sm, e2);
		assert(sm.size() != 0);
		temp_day = sm[1];
		temp_month = sm[2];
		temp_year = sm[3];
	}
	else if(regex_match(sdate, e3))
	{ 
		regex_match(sdate, sm, e3);
		assert(sm.size() != 0);
		temp_month = sm[1];
		temp_day = sm[2];
		temp_year = sm[3];
	}
	else
	{
		//cerr error
		MyOutput(std::cerr, "Error format in construct fuc!");
		exit(1);
	}

	this->day = stoi(temp_day);
	this->year = stoi(temp_year);
	this->month = GetMonthFromStr(temp_month);

}

FormatDate::~FormatDate()
{
}

void FormatDate::GetCurDate()
{
	std::cout << "year:" << year << ", month:" << month << ", day:"<<day << std::endl;
}


