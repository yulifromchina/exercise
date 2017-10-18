#include <iostream>
#include <random>

void swap(int * a, int * b)
{
	if(*a == *b)
		return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int partition(int * arr, int low, int high)
{
	if (arr == NULL || high <= low || low <0 || high < 0)
		return -1;
	int index = low + rand() % (high-low + 1);
	swap(&arr[low], &arr[index]);

	int pivot = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] > pivot) --high;
		arr[low] = arr[high];
		while (low < high && arr[low] < pivot) ++low;
		arr[high] = arr[low];
	}
	arr[high] = pivot;
	return high;
}

void QuickSort(int * arr, int low, int high)
{
	if (arr == NULL || high <= low || low <0 || high < 0)
		return;

	int pivotpos = partition(arr, low, high);
	QuickSort(arr, low, pivotpos-1);
	QuickSort(arr, pivotpos+1, high);
}

int main()
{
	using namespace std;
	int arr[] = {3,6,9,2,5,8,1,4,7};
	cout << "Initial arr (";
	for (auto const & ele : arr)
		cout << ele << " ";
	cout <<")"<< endl;

	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	cout << "Sorted arr (";
	for (auto const & ele : arr)
		cout << ele << " ";
	cout << ")" << endl;
	return 0;
}