#include<stdio.h>
#include<conio.h>
#define MAX 13  //total size of array
int arr[MAX];
int top1=-1,top2=(MAX/2)+1,top3=MAX/2,top4=MAX; //all the top should start from before the actual start example top1 is starting from -1 actual start is from 0 
void push1(int);                                //top2 is starting from (MAX/2)+1 which is before from actual start same as top3 and top4
void push2(int);
void display1(void);
void display2(void);
void pop1(void);
void pop2(void);
void peep1(void);
void peep2(void);
void push3(int);
void push4(int);
void display3(void);
void display4(void);
void pop3(void);
void pop4(void);
void peep3(void);
void peep4(void);
int main()
{
	int option,e;
	do
	{
		printf("\n\n***MAIN MENU***");
		printf("\n 1. PUSH1");
        printf("\n 2. POP1");
        printf("\n 3. PEEP1");
        printf("\n 4. DISPLAY1");
        printf("\n 5. PUSH2");
        printf("\n 6. POP2");
        printf("\n 7. PEEP2");
        printf("\n 8. DISPLAY2");
        printf("\n 9. PUSH3");
        printf("\n 10. POP3");
        printf("\n 11. PEEP3");
        printf("\n 12. DISPLAY3");
        printf("\n 13. PUSH4");
        printf("\n 14. POP4");
        printf("\n 15. PEEP4");
        printf("\n 16. DISPLAY4");
        printf("\nEnter your option: ");
        scanf("%d",&option);
        switch(option)
        {
        	case 1:printf("\nEnter element: ");
        	       scanf("%d",&e);
			       push1(e);
                   break;
            case 2:pop1();
                   break;
            case 3:peep1();
                   break;
            case 4:display1();
                   break;
            case 5:printf("\nEnter element: ");
        	       scanf("%d",&e);
			       push2(e);
                   break;
            case 6:pop2();
                   break;
            case 7:peep2();
                   break;
            case 8:display2();
                   break;
          	case 9:printf("\nEnter element: ");
        	       scanf("%d",&e);
			       push3(e);
                   break;
            case 10:pop3();
                   break;
            case 11:peep3();
                   break;
            case 12:display3();
                   break;
            case 13:printf("\nEnter element: ");
        	        scanf("%d",&e);
		        	push4(e);
                    break;
            case 14:pop4();
                   break;
            case 15:peep4();
                   break;
            case 16:display4();
                   break;       
		}
	}while(option<=16);
	int i;
	for(i=0;i<13;i++)
	printf(" %d",arr[i]);
	getch();
	return 0;
}
void push1(int e)
{
	if(top1+1==top2)
	{
		printf("\nStack overflow no space.");
	}
	else
	{
		arr[++top1]=e;
	}
}
void push2(int e)
{
	if(top1+1==top2)
	{
		printf("\nStack overflow no space.");
	}
	else
	{
		arr[--top2]=e;
	}
}
void display1()
{
	int i;
	if(top1==-1)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nElements are: ");
	  for(i=top1;i>=0;i--)
	  {
	    printf(" %d",arr[i]);
	  } 
	}
}
void display2()
{
	int i;
	if(top2==(MAX/2)+1)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nElements are: ");
	  for(i=top2;i<(MAX/2)+1;i++)//here = not using if we use it print extra value 0 
	  {
	    printf(" %d",arr[i]);
	  } 
	}
}
void pop1(void)
{
	if(top1==-1)
	{
		printf("\nstack underflow no data.");
	}
	else
	{
		printf("\nDeleted successfully: %d",arr[top1]);
		--top1;
	}
}
void pop2(void)
{
	if(top2==(MAX/2)+1)
	{
		printf("\nstack underflow no data.");
	}
	else
	{
		printf("\nDeleted successfully: %d",arr[top2]);
		top2++;
	}
}
void peep1(void)
{
	if(top1==-1)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nTop most element: %d",arr[top1]);
	}
}
void peep2(void)
{
	if(top2==(MAX/2)+1)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nTop most element: %d",arr[top2]);
	}
}
void push3(int e)
{
   	if(top3+1==top4)
	{
		printf("\nStack overflow no space.");
	}
	else
	{
		arr[++top3]=e;
	}	
}
void push4(int e)
{
   	if(top4==top3+1)
	{
		printf("\nStack overflow no space.");
	}
	else
	{
		arr[--top4]=e;
	}	
}
void display3()
{
	int i;
	if(top3==MAX/2)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nElements are: ");
	  for(i=top3;i>MAX/2;i--)//not using = it print extra number
	  {
	    printf(" %d",arr[i]);
	  } 
	}
}
void display4()
{
	int i;
	if(top4==MAX)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nElements are: ");
	  for(i=top4;i<MAX;i++)
	  {
	    printf(" %d",arr[i]);
	  } 
	}
}
void pop3(void)
{
	if(top3==MAX/2)
	{
		printf("\nstack underflow no data.");
	}
	else
	{
		printf("\nDeleted successfully: %d",arr[top3]);
		--top3;
	}
}
void pop4(void)
{
	if(top4==MAX)
	{
		printf("\nstack underflow no data.");
	}
	else
	{
		printf("\nDeleted successfully: %d",arr[top4]);
		++top4;
	}
}
void peep3(void)
{
	if(top3==MAX/2)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nTop most element: %d",arr[top3]);
	}
}
void peep4(void)
{
	if(top4==MAX)
	{
		printf("\nStack is empty.");
	}
	else
	{
		printf("\nTop most element: %d",arr[top4]);
	}
}


