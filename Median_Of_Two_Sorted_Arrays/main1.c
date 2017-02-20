#include <stdio.h>
#include <stdlib.h>


/*
 *using binary search method 
 *the time complexity is O(logmin(m, n))
 * */
double findMediaSortedArrays(int *nums1, int num1Size, int *nums2, int num2Size)
{
	if(NULL ==  nums1 || NULL == nums2)
	{
		return 0.0;
	}

	if(num1Size > num2Size)
		return findMediaSortedArrays(nums2, num2Size, nums1, num1Size);

	int i,j;

	int imin = 0;
	int imax = num1Size;
	int left_max,right_min;

	//i + j = m + n  - i - j;
	//i = 0 ~ m
	//j = (m + n)/2 -i

	while(imin <= imax)
	{
		i = (imin + imax) / 2;
		j = (num1Size + num2Size + 1) / 2 - i;
		
		if(i > 0 && nums1[i-1] > nums2[j])
		{
			imax = i - 1;
		}
		else if(i < num1Size && nums2[j-1] > nums2[i])
		{
			imin = i + 1;
		}
		else
		{
			if(i == 0)
				left_max = nums2[j - 1];
			else if(j == 0)
				left_max = nums1[i - 1];
			else
				left_max = nums1[i - 1] > nums2[j-1] ? nums1[i - 1] : nums2[j - 1];


			if((num1Size + num2Size) % 2 == 1)
				return left_max;

			if(i == num1Size)
				right_min = nums2[j];
			else if(j == num2Size)
				right_min = nums1[i];
			else
				right_min = nums1[i] < nums2[j] ? nums1[i]:nums2[j];

			return (left_max + right_min) / 2;
		}
	}
	

}



int main(int argc, char *argv[])
{
	double ret = 0.0;
	int arr1[4] = {1,3,5,6};
	int arr2[2] = {2,4};

	ret = findMediaSortedArrays(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int));

	printf("the median is %.2lf\n", ret);


	return 0;
}
