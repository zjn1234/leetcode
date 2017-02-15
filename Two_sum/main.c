#include <stdio.h>
#include <stdlib.h>


/*
 *Give an array of integers, return indices of the two numbers such that they add
 *up to specific target. assume that each input would have exactly one solution ,
 *you may not use the same element twice.
 * */

int* twoSum(int* nums, int numsSize, int target) 
{
    if(NULL == nums)
    {
	return NULL;
    }
    int *ret = malloc(sizeof(int)*2);
    int i = 0, j = 0;
    if(NULL == ret)
    {
        return NULL;   
    }
    
    for(i = 0; i <= numsSize - 2; ++i)
        for(j = i + 1; j <= numsSize - 1; ++j)
        {
            if((*(nums+i) + *(nums+j)) == target)
            {
                *ret = i;
                *(ret+1) = j;
                return ret;
            }
        }
        
    return NULL;
}

int main(int argc, char *argv[])
{
	int arr[4] = {3,2,4,6};

	int *a = NULL;

	a = twoSum(arr, 4, 10);

	printf("%d %d\n", a[0],a[1]);

	free(a);

	return 0;
}
