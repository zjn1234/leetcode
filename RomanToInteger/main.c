#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int RomanTointeger(char *s)
{
    int sum = 0;
    while(*s != '\0')
    {
        switch(*s)
        {
            case 'I':
                if(*(s+1) != 'I' && (*(s+1)) != '\0')
                   sum -= 1;
                else
                    sum += 1;
                break;
            case 'V':
                sum += 5;
                break;
            case 'X':
                if((*(s+1) == 'M') && (*(s+1) == 'L') && (*(s+1) == 'D'))
                {
                    sum -= 10;
                }
                else
                    sum += 10;
                break;
            case 'L':
                sum += 50;
                break;
            case 'C':
                if(((*(s+1) == 'M') || (*(s+1) == 'D')))
                    sum -= 100;
                else
                    sum += 100;
                break;
            case 'M':
                sum += 1000;
                break;
            case 'D':
                sum += 500;
                break;
            default:
                break;

        }
        s++;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("argument Error\n");
        exit(0);
    }
	int ret = RomanTointeger(argv[1]);
	printf("%d\n", ret);
	exit(0);
}
