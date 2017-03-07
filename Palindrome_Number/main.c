#include <stdio.h>

int isPalindrome(int x)
{
	if(x < 0)
	{
		return 0;
	}

	int  len = 0;
	int tmp = x;
	int i = 0;
	int ret = 0;


	//first caculate the length of the number
	while(tmp != 0)
	{
		tmp = tmp / 10;
		len ++;
	}

	printf("%d\n", len);

	//number divided by 10 for len / 2 times 
	//use ret = ret * 10 + remainder to these remainders
	//if len is odd (1234321) x = x / 10 for take out number 4
	//finally if ret == x it's palindrome
	for(i = 0; i < (len / 2); ++i)
	{
		ret = ret * 10 + x % 10;
		x = x / 10;
	}

	if(len % 2 != 0)
	{
		x /= 10;
	}

	printf("ret = %d\n", ret);

	if(ret != x)
	{
		return 0;
	}

	return 1;
}


int main(int argc, char *argv[])
{

	int ret = 0;
	ret = isPalindrome(123321);

	if(0 == ret)
	{
		printf("the number is not palindrome\n");
	}else if(1 == ret)
	{
		printf("the number is palindrome\n");
	}

	return 0;
}
