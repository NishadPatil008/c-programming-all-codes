#include<stdio.h>
int main()
{
	int a[5],max,i,min;
	printf("Enter 5 array elements:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	max=i;
	for(i=0;i<5;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	printf("The max number is %d\n",max);
	min=i;
	for(i=0;i<5;i++)
	{
		if(min>a[i])
			min=a[i];
	}
	printf("The min number is %d",min);
	return 0;
} 