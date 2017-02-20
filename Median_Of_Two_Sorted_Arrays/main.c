#include <stdio.h>
#include <stdlib.h>




/*
 *using merge sort method
 *the time complexity is O(m + n)
 * */
double findMediaSortedArrays(int *nums1, int num1Size, int *nums2, int num2Size)
{
	if(NULL ==  nums1 || NULL == nums2)
	{
		return 0.0;
	}
	if(num1Size <= 0 || num2Size <= 0)
	{	
		return 0.0;
	}

	int median_indices = (num1Size + num2Size) / 2;
	double median_value = 0.0;	
	int *arr = malloc(sizeof(int) * (num1Size + num2Size));
	if(NULL == arr)
	{
		return 0.0;
	}

	int i = 0, j = 0, k = 0;

	while(j < num1Size && k < num2Size)
	{
		if(nums1[j] < nums2[k])
		{
			arr[i++] = nums1[j++];
		}
		else
		{
			arr[i++] = nums2[k++];
		}
	}
	while(j < num1Size)
	{
			arr[i++] = nums1[j++];
	}
	while(k < num2Size)
	{
			arr[i++] = nums2[k++];
	}

	//the time complexity is O(m+n)

	if( (num1Size + num2Size) % 2 == 0)
	{
		return (arr[median_indices-1] + arr[median_indices]) / 2.0;
	}else
	{
		return arr[median_indices];
	}
}



int main(int argc, char *argv[])
{
	double ret = 0.0;
	int arr1[4] = {1,3,5,6};
	int arr2[3] = {2,4};

	ret = findMediaSortedArrays(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int));

	printf("the median is %.2lf\n", ret);


	return 0;
}
