#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}list;
list *top=0;
void push();
void display();
void peep();
void pop();
int main()
{
	int option;
	do
  {
		printf("\n***MAIN MENU***");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
      switch(option)
    {
    case 1:push();
       break;
       case 2:pop();
       break;
    case 3:peep();
       break;
    case 4:display();
       break;	    	
    }
  }while(option<=4);
getch();
return 0;
}
 
 void push()
 {
 	list *newnode;
 	newnode=(list*)malloc(sizeof(list));
 	printf("\nEnter the elements:");
 	scanf("%d",&newnode->data);
 		newnode->link=top;
 		top=newnode;
 }
 
 void display()
 {
 	list *temp;
 	if(top==0)
 	{
 	printf("\nstack is enpty: ");
    }
	 else
	 {
 	temp=top;
 	while(temp!=0)
 	{
	    printf(" %d",temp->data);
 		temp=temp->link;	
	 }
   }
 }
 
 void peep()
 {
 		if(top==0)
 	{
 		printf("stack is empty.");
	}
	 else
	 {
    	printf("\nTop most element in stake: ");
 	    printf(" %d",top->data);
     }
 }
 
 void pop()
 {
 	list *temp=top;
 	 //temp=top; same
 	if(top==0)
 	{
 		printf("stack is empty.");
	 }
	 else
	 {
 	printf("\nElement deleted successfully: %d",temp->data);
 	top=top->link;
 	free(temp);
     }
 }
 
