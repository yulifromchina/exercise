#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;
	vector<int> vi;
	vi.reserve(5);
	for (int i = 0; i < 5; i++)
		vi.push_back(i);

	vector<int>::reverse_iterator ri = find(vi.rbegin(), vi.rend(), 3);
	cout << *ri << endl;//point 3
	vector<int>::iterator ii(ri.base());
	cout << *ii << endl;//point 4

	vi.erase(--(ri.base()));//delete 3
	for_each(vi.begin(), vi.end(), [](int i) {cout << i << " "; });
	return 0;
}