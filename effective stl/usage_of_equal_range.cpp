#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;


//print vector with range delimited by [ and ]
template <class T>
void dump_vector(const vector<T> & v, pair<typename vector<T>::iterator, typename vector<T>::iterator>range)
{
	//模板函数中，嵌套从属名称需要加上typename
	//从属名称：template中出现的名称依赖于某个template参数
	//嵌套从属：从属名称在class类中呈嵌套状
	for (typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i)
	{
		if (i == range.first)
			cout << "[";
		if (i == range.second)
			cout << "]";
		cout << *i <<" ";
	}
	cout << endl;
}

template<class T>
void equal_range_demo(const vector<T>&original_vector, T val)
{
	vector<T> v(original_vector);
	sort(v.begin(), v.end());
	cout << "vector sorted by the default binary predicate:";
	for (typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl << endl;

	pair<typename vector<T>::iterator, typename vector<T>::iterator> result = equal_range(v.begin(), v.end(), val);
	cout << "Result of equal_range with val= " << val << ":" << endl;
	dump_vector(v, result);
	cout << endl;
}

template<class T, class F>
void equal_range_demo(const vector<T>& original_vector, T val, F pred, string prename)
{
	vector<T> v(original_vector);
	sort(v.begin(), v.end(), pred);
	cout << "vector sorted by the binary predicate :" << prename << endl;
	for (typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl << endl;

	pair<typename vector<T>::iterator, typename vector<T>::iterator> result = equal_range(v.begin(), v.end(), val, pred);
	cout << "Result of equal_range with val= " << val << ":" << endl;
	dump_vector(v, result);
	cout << endl;
}

bool abs_lesser(int ele1, int ele2)
{
	return abs(ele1) < abs(ele2);
}


bool shorter_than(const string &l, const string &r)
{
	return l.size() < r.size();
}

int main()
{
	vector<int> v1 = {-1,0,1,2,3,4,-3,-2,-1,0};
	equal_range_demo(v1, 3);
	equal_range_demo(v1, 3, abs_lesser, "abs_lesser");

	vector<string> s2;
	s2.push_back("cute");
	s2.push_back("fluffy");
	s2.push_back("kittens");
	s2.push_back("fun");
	s2.push_back("fluffy");
	s2.push_back("meowmeowmeow");
	s2.push_back("blah");

	//这里不能进行自动类型推断，所以加<string>
	equal_range_demo<string>(s2,"fred", shorter_than, "shorter_than");
	return 0;
}