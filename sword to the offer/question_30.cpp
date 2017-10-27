//最小的K个数字
//输入n个数字，找出其中最小的k个数字，例如输入：4,5,1,6,2,7,3,8；最小的4个数字是1,2,3,4

#include <iostream>
#include <set>
#include <vector>
#include <functional>

using namespace std;

void GetLeastNumber(const vector<int> & data, multiset<int, greater<int>> &leastNumbers, int k)
{
	leastNumbers.clear();

	if (k < 1 || data.size() < k)
		return;

	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter)
	{
		if (leastNumbers.size() < k)
			leastNumbers.insert(*iter);
		else
		{
			multiset<int, greater<int>>::iterator it = leastNumbers.begin();
			if (*iter < *it)
			{
				leastNumbers.erase(it);
				leastNumbers.insert(*iter);
			}
		}
	}
}

int main()
{
	vector<int> data = {4,5,1,6,2,7,3,8};
	multiset<int, greater<int>> leastNumber;
	GetLeastNumber(data, leastNumber, 4);
	for (const auto & it : leastNumber)
		cout << it << " ,";
	cout << endl;
	return 0;
}