#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT		((int)pow(2,(sizeof(int)*8-1)))
#define MIN_INT	(-(int)pow(2,(sizeof(int)*8)))


int myAtoi(char *str)
{
	if(NULL == str)
	{
		return 0;
	}

	int len = strlen(str);
	
	long long int ret = 0;
	int i = 0, j = 0;

	char *str_copy = malloc(len+1);
	if(NULL == str_copy)
	{
		return 0;
	}
	//find the first '0'-'9' character if
	//not return 0
	while(str[i] < '0' || str[i] > '9')
	{
		if(str[i] == ' ')
		{
			++i;
			continue;
		}
		else
		{
			return 0;
		}
	}

	while(str[i] >= '0' && str[i] <= '9')
	{
		str_copy[j++] = str[i];
		++i;
	}

	for(i = 0; i <= j - 1; ++i)
	{
		putchar(str_copy[j]);
		ret = ret * 10 + str_copy[i] - '0';
	}
	
	//judge overflow case
	if(ret > MAX_INT || ret < MIN_INT)
	{
		return 0;
	}
	return ret;
}


int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("input ./a.out parameter1\n");
		return 0;
	}
	printf("%d\n", myAtoi(argv[1]));

	return 0;
}
