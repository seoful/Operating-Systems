#include <stdio.h>
#include <limits.h>
#include <float.h>
void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a;
    int b;
    scanf("%d",&a);
    scanf("%d",&b);
    swap(&a,&b);
    printf("%d,%d",a,b);
    return 0;
}
