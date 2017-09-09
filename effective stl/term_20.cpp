#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>


class Dereference
{
public:
	template <typename T>
	const T &operator()(const T * ptr)const
	{
		return *ptr;
	}
};


class StringPtrLess
{
public:
	bool operator()(const std::string * p1, const std::string * p2) const
	{
		return *p1 < *p2;
	}
};

int main()
{
	using namespace std;
	typedef set<string *, StringPtrLess> SetStr;
	SetStr ssp;
	ssp.insert(new string("Triger"));
	ssp.insert(new string("Penguin"));
	ssp.insert(new string("Panda"));
	ssp.insert(new string("Monkey"));
	SetStr::const_iterator i = ssp.begin();
	

	//在将ssp的每个元素应用在Dereference之前，解引用一次；在Dereference()中再解引用一次
	transform(ssp.begin(), ssp.end(), ostream_iterator<string>(cout, "\n"), Dereference());

	return 0;
}