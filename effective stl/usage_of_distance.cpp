#include <iostream>
#include <algorithm>
#include <list>

int main()
{
	using namespace std;
	list<int> l1 = {-2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
	list<int>::iterator Iter = l1.begin(), Iter2 = l1.begin();
	advance(Iter, 1);
	cout << "Iter2: "<<*Iter << endl;
	advance(Iter2, 8);
	cout << "Iter2 :" << *Iter2 << endl;
	
	list<int>::difference_type Ldiff;
	Ldiff = distance(Iter, Iter2);//ÏÂ±êµÄ²î

	cout << "Distance between " << *Iter << " and " << *Iter2 << " is " << Ldiff << endl;
	return 0;
}