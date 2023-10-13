#include <stdio.h>
void main()
{
    float x = 2, sum, t, d;
    int i, n = 5;
    sum = 1;
    t = 1;
    for (i = 1; i < n; i++)
    {
        d = (2 * i) * (2 * i - 1);
        t = -t * x * x / d;
        sum = sum + t;
    }
    printf("sum = %f", sum);
}