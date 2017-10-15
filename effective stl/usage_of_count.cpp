#include<algorithm>
#include<iostream>
#include<vector>

//count的比较方式是operator==
int main()
{
	using namespace std;
	vector<int>  v1;
	vector<int>::iterator Iter;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(10);
	v1.push_back(10);

	cout << "v1=(";
	for (Iter = v1.begin(); Iter != v1.end(); ++Iter)
	{
		cout << *Iter <<" ";
	}
	cout << ")" << endl;

	//difference_type:The types of a signed distance between two elements.
	//in vector, it is: typedef int difference_type
	vector<int>::iterator::difference_type result;
	result = count(v1.begin(), v1.end(), 10);
	cout << "The number 10 in vector v1 is " << result << endl;

	return 0;
}