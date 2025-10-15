#include <stdio.h>
int main()
{
    int i,a[10],key,mid,low=0,high=9,n;
    printf("Enter Numbers: ");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter a element to be searched \n");
    scanf("%d",&key);
    while(low<=high)
    {
        mid=(low+high)/2;
        if (a[mid]==key) 
        {
            printf("Element found at position %d\n",mid);
            return 0;
        } 
        else if(key<a[mid]) 
        {
            high=mid-1;
        } 
        else 
        {
            low=mid+1;
        }
    }
printf("Element not found in the array");
return 0;
    }
