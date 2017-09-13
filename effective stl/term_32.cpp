#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool greater6(int value)
{
	return value > 6;
}

int main()
{
	vector<int> vec;
	vec.reserve(10);
	for (int i = 1; i <= 10; ++i)
		vec.push_back(i);
	vec.erase(remove(vec.begin(), vec.end(), 5), vec.end());
	for_each(vec.begin(), vec.end(), [](int i) {cout << i << " "; });
	cout <<  endl;

	vector<int> vec1;
	vec1.reserve(10);
	for (int i = 1; i <= 10; ++i)
		vec1.push_back(i);
	vec1.erase(remove_if(vec1.begin(), vec1.end(), greater6), vec1.end());
	for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << " "; });
	cout << endl;

	vector<int> vec2;
	vec2.reserve(10);
	for (int i = 1; i <= 10; ++i)
	{
		vec2.push_back(i);
		vec2.push_back(i);
	}
	vec2.erase(unique(vec2.begin(), vec2.end(), [](int i, int j) {return i == j; }), vec2.end());
	for_each(vec2.begin(), vec2.end(), [](int i) {cout << i << " "; });
	cout << endl;
	return 0;
}