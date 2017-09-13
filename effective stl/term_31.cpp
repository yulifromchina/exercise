#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


int main()
{
	vector<int> vec{1,4,9,2,13,0,8,3,19,14,7,4,6,65,2,5,43};
	partial_sort(vec.begin(), vec.begin()+4, vec.end(), greater<int>());
	cout << "partial_sort 4:" << endl;
	for_each(vec.begin(), vec.end(), [](int i) {cout << i <<" "; });
	cout << endl;


	vector<int> vec1{ 1,4,9,2,13,0,8,3,19,14,7,4,6,65,2,5,43 };
	nth_element(vec1.begin(), vec1.begin() + 4, vec1.end(), greater<int>());
	cout << "nth_element 4:" << endl;
	for_each(vec1.begin(), vec1.end(), [](int i) {cout << i << " "; });
	cout << endl;
	return 0;
}