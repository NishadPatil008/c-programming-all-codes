#include <stdio.h>
int main() 
{
    int a[10],i,j,t;
    printf("Enter 5 numbers:\n");
    for(i=0;i<5;i++ ) 
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++) 
    {
        for(j=i+1;j<5;j++) 
        {
            if(a[i]<a[j]) 
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    printf("The numbers in ascending order are:\n");
    for(i=0;i<5;i++) 
    {
        printf("%d\t",a[i]);
    }
    return 0;
}  