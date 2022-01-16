#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10
typedef struct node
{
   int data;
   struct node *next;	
}list;
list *head=0,*tail; //we are using tail so that use can create list more than one and data will be added from tail position
list *stack[MAX];//maximum size array of pointers
void create(void);
void displaylinkedlist(void);
void reverseusingstack(void);
int pushinstack(list *,int);
int pop(int);
int main()
{
	int option;
	do
	{
		printf("\n\nMAIN MENU");
		printf("\n1.create list");
		printf("\n2.Display Linked list");
		printf("\n3.Reverse list using stack");
		printf("\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:create();
				break;
			case 2:displaylinkedlist( );
			    break;
		    case 3:reverseusingstack( );
			    break;
		}
	}while(option<=3);
	getch();
	return 0;
}
void create( ) //best code because user can call this function number of times and data will be connected to previous data 
{
	list *newnode;
	int element;
    printf("\nEnter -1 to stop entering data.");
    printf("\nEnter the element: ");
	    scanf("%d",&element);
     while(element!=-1)
	  {
	  	newnode=(list*)malloc(sizeof(list));
	    if(head==0)//done stop
     	{
	     tail=head=newnode;//=(list*)malloc(sizeof(list));
	     tail->data=element;
	     tail->next=0;
        }
        else
        {
		 //newnode=(list*)malloc(sizeof(list));
		 newnode->data=element;
		 newnode->next=0;
		 tail->next=newnode;//this line connecting the node
		 tail=newnode;
	   }
	   printf("\nEnter the element: ");
	   scanf("%d",&element);
    }
}
void displaylinkedlist()
{
    list *temp;
    temp=head;
    if(head==0)
    {
    	printf("\nNo data list is empty.");
	}
	   else
    	{
        	printf("\nElements are:");
			while(temp!=0)
			{
				printf(" %d",temp->data);
				temp=temp->next;
			}
		}      			
}
void reverseusingstack(void)
{
	int top=-1;//it is not global because in secind time execution it should start from beginning so stack will not be fulled
	list *temp;
	   temp=head;
	   while(temp!=0)
	   {
	   	 top=pushinstack(temp,top);
	   	 temp=temp->next;
	   }
	     temp=stack[top];//it is the top of stack so it will contain last node address which will become head after reversed
	   while(temp!=head)
	   {
	       top=pop(top);
	   	 temp=temp->next=stack[top] ;
	   }
	   temp->next=0;//since last node contain 0 after reversed and here temp contain head address
	   head=tail;
	   tail=temp;//since temp contain head address so head will become tail after reversed
	   printf("\nLinked list after Reversed using STACK: ");
	   displaylinkedlist();
}
int pushinstack(list *temp,int top)
{
	if(top==MAX-1)
	{
		printf("\nStack OVERFLOW (pushinstack function) cannot reverse(ELEMENTS IS MORE THAN SIZE).");
		exit(0); //it will terminate whole program even if it is in function
	}
	else
	{
		stack[++top]=temp;
	}
	return top;
}
int pop(int top)
{
	/*if(top==-1)  //not need this because this function will execute first int pushinstack(list *temp,int top) so if this func produce any error then it will not execute
	{ 
		printf("\nStack underflow pop.");
	}*/
	  --top;
      return top;
}
