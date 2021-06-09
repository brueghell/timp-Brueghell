
#include <math.h>
#include <stdio.h>
int main()
{
    int i;
    int n = 0;
    double sum = 0;
    int x = 0;
    (void)scanf("%d", &n);
    for( i=1; i<=n; i++)
    {
        (void)scanf("%d", &x);
        if (i%2 == 0)
        {
            x = x*x*x;
            sum = sum + x;
        }
    }
    printf("%lf", sum);
    return 0;
}