#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//must free the return str
char *longestCommanPrefix(char **strs, int strsSize)
{
    char *str = malloc(200);
    memset(str, 0x00, 200);
    int i = 0, j = 0;
    char c = 0;

    for(j = 0;; ++j)
    {
        c = strs[0][j];
        for(i = 1; i < strsSize; ++i)
        {
            if(c == '\0' || strs[i][j] == '\0')
                return str;
            if(c != strs[i][j])
                return  str;
        }
        str[j] = c;
    }

    return str;
}
int main(void)
{
    char *s = NULL;
    char *arr[] = {"a", "abd", "abf"};
    s = longestCommanPrefix(arr, sizeof(arr)/sizeof(char *));
    puts(s);
    free(s);

    exit(0);
}
