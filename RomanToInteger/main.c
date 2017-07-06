#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *I[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char *X[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char *C[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "DM"};
char *M[] = {"M", "MM", "MMM"};

int RomanTointeger(char *s)
{
	if(s == NULL)
		return 0;

	
}

int main(void)
{
	int ret = RomanTointeger("IV");
	printf("%d\n", ret);
	exit(0);
}
