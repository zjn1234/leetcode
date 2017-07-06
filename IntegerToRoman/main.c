#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
char *X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
char *C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "DM", "M"};
char *M[] = {"", "M", "MM", "MMM"};

void IntToRoman(int num)
{
	if(num <= 0 || num > 3999)
		return;

	char buf[20] = {0};
	strcat(buf, M[num/1000]);
	num %= 1000;
	strcat(buf, C[num/100]);
	num %= 100;
	strcat(buf, X[num/10]);
	num %= 10;
	strcat(buf, I[num]);

	puts(buf);	
}

int main(void)
{
	IntToRoman(124);
	exit(0);
}
