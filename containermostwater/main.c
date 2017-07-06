#include <stdio.h>
#include <stdlib.h>

int MaxWater(int *arr, int size)
{
	int i,j;
	int area = 0, tmp;
	for(i = 0; i < size - 1; i++)
		for(j = i + 1; j < size; j++)
		{
			tmp = (j - i) * (arr[i] > arr[j]? arr[j]:arr[i]);
			area = area > tmp? area:tmp;
		}

	return area;
}

int main(void)
{
	int arr[] = {1,2,3,4,5};
	int max = MaxWater(arr, sizeof(arr)/sizeof(int));

	printf("%d\n", max);

	exit(0);
}
