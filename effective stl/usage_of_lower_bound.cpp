//lower_bound,在有序容器中找到第一个大于或等于指定值的元素
#include<vector>
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	using namespace std;
	vector<int> v1 = {-1,0,1,2,3,4,-3,-2,-1,0};
	cout << "startint vector v1 = ";
	for (const auto &Iter : v1)
		cout << Iter << " ";
	cout << endl;

	//排序和lower_bound使用的谓语要一致，这里都是greater<int>()
	sort(v1.begin(), v1.end(), greater<int>());
	cout << "after sorting vector v1 = ";
	for (const auto &Iter : v1)
		cout << Iter << " ";
	cout << endl;

	vector<int>::iterator result = lower_bound(v1.begin(), v1.end(), 3, greater<int>());
	if (result != v1.end())
		cout << "The lower bound in v1 with value 3 is: " << *result << endl;
	else
		cout << "cannot find." << endl;
	return 0;
}