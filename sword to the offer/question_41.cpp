////和为s的两个数字
////输入递增排序的数组和一个数字s，要求找出一对数字满足和为s
//
//#include <iostream>
//
//bool GetTwoNum(int * arr, int len, int s, int & index1, int & index2)
//{
//	if (arr == NULL || len < 2)
//		return false;
//
//	index1 = 0;
//	index2 = len - 1;
//	while (index1 < index2)
//	{
//		if (arr[index1] + arr[index2] == s)
//			return true;
//		else if (arr[index1] + arr[index2] > s)
//			--index2;
//		else
//			++index1;
//	}
//	return false;
//}
//
//
//int main()
//{
//	using namespace std;
//	int arr[] = {1,2,4,7,11,15};
//	int index1, index2;
//	if (GetTwoNum(arr, sizeof(arr) / sizeof(arr[0]), 15,index1, index2))
//		cout << "arr[" << index1 << "]:" << arr[index1] << ",arr[" << index2 << "]:" << arr[index2] << endl;
//
//	if (GetTwoNum(arr, sizeof(arr) / sizeof(arr[0]), 50, index1, index2))
//		cout << "arr[" << index1 << "]:" << arr[index1] << ",arr[" << index2 << "]:" << arr[index2] << endl;
//	return 0;
//}