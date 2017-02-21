#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* convert(char *s, int numRows)
{
	int row,column;

	char *ret = malloc(sizeof(s));
	if(NULL == ret)
	{
		return NULL;
	}
	*(ret + strlen(s)) = '\0';
	int i,j,index;
	int sum = 0;

	for(row = 0,j = 0,index = 0; row < numRows; ++row)
	{
		sum = row;
		for(column = 0; ;)
		{
			if(row == 0 || row == numRows - 1)
			{
				index = row + (column / 2) * numRows + (column / 2) * (numRows - 2);
				column += 2; 
			}
			else
			{
				if(column != 0)
				{
					if(column % 2 == 0)
					{
						sum += row + 1;
						sum += numRows - 2 - row;
					}else
					{
						sum += row;
						sum += numRows - row  - 1;
					}
				}
				index = sum;
				column += 1;
			}


			if(index >= strlen(s))
				break;
			else
			{
				ret[j++] = s[index];
			}
		}
	}
		
	return ret;
}


int main(int argc, char *argv[])
{
	char *s = convert("PAYPALISHIRING", 5);

	printf("%s\n", s);

	free(s);

	return 0;
}
