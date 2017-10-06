//两个排序的数组，A数组末尾有足够的空间，把B数组的数插入到A中，使得所有数字有序

#include <stdio.h>
#define MAX 128

void Sort(int a[], int b[], int a_length, int b_length)
{
	int new_length = a_length + b_length;
	if (new_length > (MAX))
		return;
	while (a_length > 0 && b_length >0)
	{
		if (a[a_length - 1] >= b[b_length - 1])
		{
			a[new_length - 1] = a[a_length - 1];
			--a_length;
		}
		else
		{
			a[new_length - 1] = b[b_length - 1];
			--b_length;
		}
		--new_length;
	}
	while(a_length > 0)
	{
		a[new_length - 1] = a[a_length - 1];
		--new_length;
		--a_length;
	}
	while (b_length > 0)
	{
		a[new_length - 1] = b[b_length - 1];
		--new_length;
		--b_length;
	}
}

int main()
{
	int a[MAX] = {1,3,5,7,9};
	int b[] = {2,4,6,8};
	Sort(a, b, 5, 4);
	for (int i = 0; i < 9; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}