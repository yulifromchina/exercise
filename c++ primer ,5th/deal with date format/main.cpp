#include "FormatDate.h"

void MyOutput(std::ostream & os, std::string content)
{
	os << content <<std::endl;
}

unsigned GetMonthFromStr(std::string smonth)
{
	std::transform(smonth.begin(), smonth.end(), smonth.begin(), ::tolower);
	std::vector<std::string> months;
	std::vector<std::string>::iterator it;
	months.reserve(24);
	//
	months.push_back("january");
	months.push_back("jan");
	months.push_back("1");

	months.push_back("february");
	months.push_back("feb");
	months.push_back("2");

	months.push_back("march");
	months.push_back("mar");
	months.push_back("3");

	months.push_back("april");
	months.push_back("apr");
	months.push_back("4");

	months.push_back("may");
	months.push_back("may");
	months.push_back("5");

	months.push_back("june");
	months.push_back("jun");
	months.push_back("6");

	months.push_back("july");
	months.push_back("jul");
	months.push_back("7");

	months.push_back("august");
	months.push_back("aug");
	months.push_back("8");

	months.push_back("september");
	months.push_back("sep");
	months.push_back("9");

	months.push_back("october");
	months.push_back("oct");
	months.push_back("10");

	months.push_back("november");
	months.push_back("nov");
	months.push_back("11");

	months.push_back("december");
	months.push_back("dec");
	months.push_back("12");
	//
	unsigned imonth;
	for (it = months.begin(),imonth = 1;it!=months.end();++it, ++imonth)
	{
		if (smonth == *it || smonth == *(++it) || smonth == *(++it))
		{
			return imonth;
		}
	}
	return 13;

}

int main()
{
	FormatDate date1("January 1, 1900");
	date1.GetCurDate();

	FormatDate date2("1/1/1900");
	date2.GetCurDate();

	FormatDate date3("Jan 1 1900");
	date3.GetCurDate();

	return 0;
}