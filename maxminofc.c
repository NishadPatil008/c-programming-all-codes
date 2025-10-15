#include<stdio.h>
int main()
{
    int a[5],min,max,i;
    printf("Enter 5 nos.\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    min=a[0];
    for(i=0;i<5;i++)
    {
        if(a[i]>max)
       { max=a[i];}
        if (a[i]<min)
       { min=a[i];}
    }
printf("The maximum no. is %d ",max);
printf("The minimum no. is %d ",min);
}