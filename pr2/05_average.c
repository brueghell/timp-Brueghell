#include<stdio.h>

int main()
{
int n,a,i;
double sum=0;
(void)scanf("%d", &n);
for (i=0;i<n;i++)
{
    (void)scanf("%d",&a);
    sum+=a;
}
printf("%lf",(double)sum/n);
return 0;
}