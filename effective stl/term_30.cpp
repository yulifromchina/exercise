#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>


using namespace std;

template <typename Type>
class MulValue
{
private:
	Type factor;
public:
	MulValue(const Type &_value) :factor(_value)
	{

	}
	Type operator()(Type &elem) const
	{
		return elem * factor;
	}
};

int main()
{
	//insert in back  (vector, string ,deque, list)
	vector<int> values{1,2,3,4,5,6};
	vector<int> result{7,8,9};
	result.reserve(values.size()+result.size());
	transform(values.begin(), values.end(), back_inserter(result), MulValue<int>(1));
	cout << "insert in back" << endl;
	for_each(result.begin(), result.end(), [](int i) {cout << i << " "; });
	cout << endl;

	//insert in front (deque, list)
	list<int> result1{ 7,8,9 };
	transform(values.begin(), values.end(), front_inserter(result1), MulValue<int>(1));
	cout << "insert in front" << endl;
	for_each(result1.begin(), result1.end(), [](int i) {cout << i << " "; });
	cout << endl;

	list<int> result2{ 7,8,9 };
	transform(values.rbegin(), values.rend(), front_inserter(result2), MulValue<int>(1));
	for_each(result2.begin(), result2.end(), [](int i) {cout << i << " "; });
	cout << endl;


	//insert in middle
	vector<int> result4{ 7,8,9 };
	transform(values.rbegin(), values.rend(), inserter(result4,(result4.begin()+result4.size()/2)), MulValue<int>(1));
	cout << "insert in middle" << endl;
	for_each(result4.begin(), result4.end(), [](int i) {cout << i << " "; });
	cout << endl;


	//resize dst, or it will collapse
	vector<int> result3{ 7,8,9 };
	if (result3.size() < values.size())
		result3.resize(values.size());
	transform(values.begin(), values.end(), result3.begin(), MulValue<int>(1));
	cout << "resize " << endl;
	for_each(result3.begin(), result3.end(), [](int i) {cout << i << " "; });
	cout << endl;
	
}