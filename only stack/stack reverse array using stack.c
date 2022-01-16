#include<stdio.h>
#include<conio.h>
#define MAX 13  //total size of array
int arr[MAX];
int top1=-1;
int stk[13];
void push(int);
int pop(void);
int main()
{
	int element,i,n,val;
	printf("\nEnter number of elements in aray.");
	scanf("%d",&n);
	printf("\nEnter the number.");
	for(i=0;i<n;i++)
	{
		scanf("%d",&*(arr+i));//or arr[i]
	}
	for(i=0;i<n;i++)
	{
		push(arr[i]);
	}
	for(i=0;i<n;i++)
	{
		val=pop();
		arr[i]=val;
	}
	printf("Reversed elements are: ");
		for(i=0;i<n;i++)
	{
	  printf(" %d",arr[i]);
	}
	getch();
	return 0;
}
void push(int val)
{
	stk[++top1]=val;
}
int pop()
{
	return stk[top1--];
}
