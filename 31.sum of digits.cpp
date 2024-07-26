#include<stdio.h>
int main()
{
	int sum=0,num;
	printf("Enter number: ");
	scanf("%d",&num);
	int rem;
	while(num!=0)
	{
		rem=num%10;
		sum+=rem;
		num=num/10;
	}
	printf("%d",sum);
}
