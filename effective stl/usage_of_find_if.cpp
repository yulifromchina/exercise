#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Print
template <typename S>
void print(const S& s)
{
	for (const auto & p : s)
		cout << "(" << p << ")";
	cout << endl;
}

//Test std::find_if()
template <class InputIterator, class Predicate>
void find_if_print_result(InputIterator first, InputIterator last, Predicate Pred, const string & Str)
{
	//call: algorithm find()
	auto p = find_if(first, last, Pred);

	if (p == last)
		cout << Str<< " not found." << endl;
	else
		cout << Str<< " found." << endl;
}

bool is_odd_int(int odd)
{
	return(odd%2!=0);
}

int main()
{
		//Testing use a plain old array
		const int x[] = {1,2,3,4,5,6,7,8,9,10};
		cout << "array x contains:";
		print(x);
	
		cout << "Test algorithm find_if: ";
		find_if_print_result(begin(x), end(x), is_odd_int, "Odd number");

	
		//Testing use a vector
		vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
		cout << "vector vi contains:";
		print(vi);
	
		find_if_print_result(vi.begin(), vi.end(), is_odd_int , "Odd number");


	return 0;
}