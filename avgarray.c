#include <stdio.h>

int main() {
    int i, j, a[5],flag=0;

    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) 
	{
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 5; i++) 
	{
        for (j = i + 1; j < 5; j++) 
		{
            if (a[i] == a[j]) 
			{
                printf("element found %d\n",a[i]);
                flag=1;
            }
            if(flag=0)
            {
            	printf("Not found");
			}
        }
    }
    return 0;
}
