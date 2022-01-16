#include<stdio.h>
#include<conio.h>
#define MAX 5
int arr[MAX];     //int arr[];error
int top1=-1,top2=MAX;
void push1();
void display1();
void pop1();
void peep1();
void push2();
void display2();
void pop2();
void peep2();
int main()
{
	int option;
	do
	{
		printf("\n***MAIN MENU***");
		printf("\n 1. PUSH1");
        printf("\n 2. POP1");
        printf("\n 3. PEEP1");
        printf("\n 4. DISPLAY1");
        printf("\n 5. PUSH2");
        printf("\n 6. POP2");
        printf("\n 7. PEEK2");
        printf("\n 8. DISPLAY2");
        printf("\nEnter your option: ");
        scanf("%d",&option);
        switch(option)
        {
        	case 1:push1();
                   break;
            case 2:pop1();
                   break;
            case 3:peep1();
                   break;
            case 4:display1();
                   break;
            case 5:push2();
                   break;
            case 6:pop2();
                   break;
            case 7:peep2();
                   break;
            case 8:display2();
                   break;
		}
	}while(option<=8);
	getch();
	return 0;
}
void push1()
{
	int element;
	if(top1==top2-1)
	{
		printf("\nStack overflow no space");
	}
	else
	{
		printf("\nEnter element: ");
		scanf("%d",&element);
		arr[++top1]=element;	
	}
}
void display1()
{
	if(top1==-1)
	{
		printf("\nstack is empty");
	}
	else
	{
	int i;
	printf("\nElements are: ");
	for(i=top1;i>=0;i--)
	{
		printf(" %d",arr[i]);
	}
}
}
void pop1()
{
	if(top1==-1)
	{
		printf("\nstack underflow no data");
	}
	else
	{
		printf("\nElement deleted successfully: %d",arr[top1]);
		top1--;
	}
}
void peep1()
{
	if(top1==-1)
	{
		printf("\n Stack is empty.");
	}
	else
	{
	printf("\nTOP most element in stack is: %d",arr[top1]);
}
}
void pop2()
{
	if(top2==MAX)
	{
		printf("\nstack overflow no space");
	}
	else
	{
	  	printf("\nElement deleted successfully: %d",arr[top2]);
		top2++;	
	}
}
void push2()
{
	int element;
	if(top2-1==top1)
	{
		printf("\nStack  overflow no space");
	}
	else
	{
		printf("\nEnter the elements: ");
		scanf("%d",&element);
		arr[--top2]=element;
	}
}
void peep2()
{
	if(top2==MAX)
	printf("\nstack is empty.");
	else
	printf("\nTop most element in stack is: %d",arr[top2]);
}
void display2()
{
	int i;
	if(top2==MAX)
	{
		printf("\nstack is empty.");
	}
	else
	{
		printf("\nElements are:");
	   for(i=top2;i<=MAX-1;i++)
	   {
	     printf(" %d",arr[i]);
       }
	}
}
