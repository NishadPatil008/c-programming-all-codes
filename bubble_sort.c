#include <stdio.h>
int main()
{
    int a[5],i,j,temp=0;
    printf("Enter 5 Numbers:");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i;j++)
        {

            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            for(int k=0;k<5;k++)
            {
                printf("%d\t",a[k]);
            }
            printf("\n");
        }
    }
    printf("Elements in ascending order are:\n");
    for(i=0;i<5;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}