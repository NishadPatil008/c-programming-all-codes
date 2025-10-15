#include <stdio.h>
int main()
{
    int a[5];
    printf("Enter 5 numbers:\n");
    for(int i = 1; i <=5; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Squares of numbers at odd positions:\n");
    for(int i = 1; i <= 5; i++)
    {
        if(i%2!=0)
        {
            printf("Position %d:Square of %d = %d\n",i,a[i],a[i]*a[i]);
        }
    }
    return 0;
}