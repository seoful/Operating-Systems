#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int len = strlen(s);
    for(int i = 0;i <len;i++){
        printf("%c",s[len-i -1]);
    }

    return 0;
}