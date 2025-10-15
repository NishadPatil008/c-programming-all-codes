#include <stdio.h>
int main()
{
    int i,n,a[10],key;
    printf("Enter Numbers: ");  
    
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to be found: ");
    scanf("%d",&key);
    int found=0;
    for(i=0;i<10;i++)
    {
        if(a[i]==key)
        {
        printf("Key found at %d",i);
        found=1;
        break;
        }
    }
    if(!found)
    {
    printf("Key not found");
    }
    return 0;
}