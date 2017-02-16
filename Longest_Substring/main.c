#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *Given a string, find the length of the longest substring without 
 *repeating characte
 *Examples:
 *Given "abcabcbb", the answer is "abc", which the length is 3.
 *Given "bbbbb", the answer is "b", with the length of 1.
 *Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer mus *      t be a substring, "pwke" is a subsequence and not a substring.
 * */


int lengthOfLongestSubstring(char *s)
{
	if(NULL == s)
	{
		return 0;
	}
	int length = strlen(s);
	int i,j,k;
	int max = 0, sum = 1;
	if(1 == length)
	{
		return 1;
	}
	
	for(i = 0; i < length - 1; ++i)
	{
		sum = 1;
		for(j = i+1; j < length; ++j)
		{
			for(k = i; k < j; ++k)
			{
				if(*(s+j) == *(s+k))
					break;
			}
			if(k == j)
				sum++;
			else
				break;
		}
		
		max = (max > sum ? max:sum);

	}	

	return max;
}


int main(int argc, char *argv[])
{
	int len = lengthOfLongestSubstring(argv[1]);
	printf("len = %d\n", len);	

	return 0;
}
