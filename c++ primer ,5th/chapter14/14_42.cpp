#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

int main()
{
	vector<int> vi{1024, 1025, 1026, 1027};
	int result = count_if(vi.begin(), vi.end(), bind2nd(greater<int>(), 1024));
	std::cout << "greater than 1024:" <<result<< std::endl;

	vector<string> vs{"pooh", "pooh", "hello","world"};
	vector<string>::iterator result1 = find_if(vs.begin(), vs.end(), bind2nd(not_equal_to<string>(), "pooh"));
	std::cout << "find the first string which not equal to 'pooh':"<<*result1<<endl;

	transform(vi.begin(), vi.end(), vi.begin(), bind2nd(multiplies<int>(), 2));
	for_each(vi.begin(), vi.end(), [](int i) {std::cout << i << std::endl; });
	return 0;
}