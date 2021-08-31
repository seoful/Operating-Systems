#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int n;
    sscanf(argv[1],"%d",&n);
    int max_len = 2*n-1;
    for(int i = 1;i<=n;i++){
        int len = 2*i-1;
        for(int j = 0;j<(max_len-len)/2;j++)
            printf("%c",' ');
        for(int j = 0;j<len;j++)
            printf("%c",'*');
        for(int j = 0;j<(max_len-len)/2;j++)
            printf("%c",' ');
        printf("%c",'\n');
    }
    return 0;
}