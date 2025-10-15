#include <stdio.h>
int main()
{
    int a[10],i,j,temp;
    printf("Enter 5 numbers:\n");
    for(i=0;i<5;i++) 
    {
        scanf("%d",&a[i]); 
    }
    for(i=1;i<5;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]<temp)
        {
            a[j+1]=a[j];
            j--;  
        }
        a[j+1]=temp;
        for(int k=0;k<5;k++)
        {
            printf("%d\t",a[k]);
        }  
        printf("\n");
    }
    for(i=0;i<5;i++) 
    {
        printf("%d\t",a[i]);
    }
    return 0;
}