//�����������в���
//�Ƚϻ��ڵȼ۶��������
//����true��false

#include <algorithm>
#include <iostream>
#include <list>
#include <functional>

int main()
{
	using namespace std;
	list<int> List1;

	List1.push_back(50);
	List1.push_back(10);
	List1.push_back(50);
	List1.push_back(30);
	List1.push_back(20);
	List1.push_back(25);
	List1.push_back(1);

	List1.sort();
	cout << "List1 = (";
	for (auto & Iter : List1)
		cout << Iter<<" ";
	cout << ")" << endl;

	if (binary_search(List1.begin(), List1.end(), 25))
	{
		cout << "Find 25." << endl;
	}
	else
		cout << "No Find 25." << endl;
	return 0;
}


