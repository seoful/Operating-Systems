#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("int size: %d, int value: %d,\nfloat size: %d, float value %f,\ndouble size: %d, double value: %f",sizeof(a),a,sizeof(b),b,sizeof(c),c);
    return 0;
}
