#include <stdio.h>
#include <string.h>


/*
 * FUNCTION: find the longest palindrome substring in string s
 * NOTICE: The longestPalindrome will change the content of the string s 
 * 
 * */

char* longestPalindrome(char *s)
{
	int left = -1;
	int right = -1;
	int index = 0;
	int i,j;

	int length = strlen(s);

	int last = strlen(s);
	while(index != length - 1)
	{
		while(s[index] != s[last] && last > index)
			last--;

		if(s[index] == s[last])
		{
			for(i = index + 1,j = last - 1; (j - i) >= 0;  ++i,--j)
			{
				if(s[i] != s[j])
					break;
			}
			if(j - i < 0)
			{
				if((right - left) < (last - index))
				{
					left = index;
					right = last;
				}
			}
			
		}
		
		index++;
		last = strlen(s);
	}	

	if((right - left) < 0)
		return NULL;

	if(right < last - 1)
		s[right + 1] = '\0';

	return s+left;
}


int main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		printf("please excute like ./a.out \"abba\" \n");
		return -1;
	}	

	char *s = longestPalindrome(argv[1]);

	if(NULL == s)
		printf("There is no palindrome in %s\n", argv[1]);
	else
		printf("The Longest Palindrome is %s\n", s);

	return 0;
}
