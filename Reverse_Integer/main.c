#include <stdio.h>
#include <string.h>
#include <math.h>

#define MIN	(-(int)(pow(2,31)))
#define MAX ((int)(pow(2,31)-1))


int reverse(int x)
{
	long long int tmp = 0;

	while(x)
	{
		tmp = tmp * 10 + x % 10;
		x /= 10;
	}

	return (tmp < MIN || tmp > MAX)? 0:tmp;
}


int main(int argc, char *argv[])
{

	int ret = reverse(-2147483602);

	printf("%d\n", ret);

	return 0;
}
