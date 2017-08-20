#include "hash_table.h"
#define ARR_LEN 20


int main()
{
	int arr[ARR_LEN] = {67,34,23,6,78,45,9,98,45,77,
	1,2,41,5,79,54,75,33,59,43};

	linear_probing(arr, ARR_LEN);
	quadratic_probing(arr, ARR_LEN);
	double_hashing(arr, ARR_LEN);
	separate_chain(arr, ARR_LEN);

	return 0;
}