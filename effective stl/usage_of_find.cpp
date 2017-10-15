#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//Print
template <typename S>
void print(const S& s)
{
	for (const auto & p : s)
		cout << "(" << p << ")";
	cout << endl;
}

//Test std::find()
template <class InputIterator, class T>
void find_print_result(InputIterator first, InputIterator last, const T& value)
{
	//call: algorithm find()
	auto p = find(first, last, value);
	
	cout << "value " << value;
	if (p == last)
		cout << " not found." << endl;
	else
		cout << " found." << endl;
}

int main()
{
	//Testing use a plain old array
	const int x[] = {1,2,3,4,5,6,7,8,9,10};
	cout << "array x contains:";
	print(x);

	cout << "Test algorithm find: ";
	find_print_result(begin(x), end(x), 10);
	find_print_result(begin(x), end(x), 20);

	//Testing use a vector
	vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
	cout << "vector vi contains:";
	print(vi);

	find_print_result(vi.begin(), vi.end(), 10);
	find_print_result(vi.begin(), vi.end(), 20);

	return 0;
}