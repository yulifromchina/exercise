#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


int main()
{
	using namespace std;
	vector<char * >v1{"Open", "up" ,"the" , "opalescent", "gates"};
	vector<char *>::iterator Iter1, Iter2;

	cout << "Original vector: ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); ++Iter1)
		cout << *Iter1 << " ";
	cout << endl;

	Iter2 = find_if(v1.begin(), v1.end(), not1(bind2nd(ptr_fun(strcmp), "opalescent")));
	if (Iter2 != v1.end())
		cout << "Found " << *Iter2 << endl;
	return 0;
}