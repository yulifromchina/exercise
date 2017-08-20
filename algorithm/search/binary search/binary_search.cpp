#include <iostream>

//’€∞Î≤È’“

int binary_search(int arr[], int arr_len, int key, int &count)
{
	count = 0;
	int low = 0, high = arr_len - 1, mid;
	while (low <= high)
	{
		count++;

		mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

int main()
{
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	int key = 10, result, count;

	result = binary_search(arr, arr_len, key, count);

	if (result != -1)
		std::cout << "find it, index: " << result << std::endl;
	else
		std::cout << "didn't find!" << std::endl;

	std::cout << "find times£∫" << count << std::endl << std::endl;

	return 0;
}