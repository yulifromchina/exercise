//在一个序列中找到第一个大于指定值的元素
//比较的标准可以用一个二元谓语来指定

#include <iostream>
#include <algorithm>
#include <vector>

bool mod_lesser(int ele1, int ele2)
{
	if (ele1 < 0)
		ele1 = -ele1;
	if (ele2 < 0)
		ele2 = -ele2;
	return ele1 < ele2;
}

int main()
{
	using namespace std;
	vector<int> v1 = {-1,0,1,2,3,4,-3,-2,-1,0};
	cout << "Starting v1=(";
	for (const auto &Iter : v1)
		cout << Iter << " ";
	cout << ")" << endl;

	sort(v1.begin(), v1.end(), mod_lesser);
	cout << "Sorting v1=(";
	for (const auto &Iter : v1)
		cout << Iter << " ";
	cout << ")" << endl;

	vector<int>::iterator result = upper_bound(v1.begin(), v1.end(), 3, mod_lesser);
	if (result != v1.end())
		cout << "There upper_bound in v3 with element 3 is "<<*result;
	else
		cout << "No upper_bound in v3 with element 3 " << endl;
	return 0;

}