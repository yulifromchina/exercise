#include <iostream>

//Ë³Ğò²éÕÒ

int sequential_search(int arr[], int arr_len, int key, int& count)
{
	count = 0;
	for (int i = 0; i < arr_len; i++)
	{
		count++;
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

int main()
{
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	int key = 10, result, count;

	result = sequential_search(arr, arr_len, key, count);

	if (result != -1)
		std::cout << "find it, index: " << result << std::endl; 
	else 
		std::cout << "didn't find!" << std::endl; 

	std::cout << "find times£º" << count << std::endl << std::endl;

	return 0;
}