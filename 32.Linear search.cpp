#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,n,arr[50],key,flag=0;
	printf("enter n");
	scanf("%d",&n);
	
	printf("enter array elements");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	printf("enter the key element to search");
	scanf("%d",&key);
	
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	   printf("the key is found at index %d",i);
	  else
	   printf("the key is not found");
}

