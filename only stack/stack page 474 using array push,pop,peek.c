#include<stdio.h>
#include<conio.h>
#define MAX 3
int stack[MAX];
 int top=-1;
void push();
void pop();
void peep();
void display();
int main()
{
	int option;
  do
{
printf("\n *****MAIN MENU*****");
printf("\n 1. PUSH");
printf("\n 2. POP");
printf("\n 3. PEEK");
printf("\n 4. DISPLAY");
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
	int val;
	if(top==MAX-1)
	{
		printf("\nstake overflow nospace.");
	}
	else
	{
		printf("\nEnter the elements: ");
		scanf("%d",&val);
		top++;
		stack[top]=val;
		printf("\nInserted successfully:%d",stack[top]);
	}
}

void pop()
{ 
  if(top==-1)
	{
		printf("\nstake underflow no data.");
	}
	else
	{
	   printf("\nValue deleted successfully: %d",stack[top]);
	   top--;	
	}	
}
void peep()
{
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nValue store at top of stack is: %d",stack[top]);
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("\nstack is empty");
	}
	else
	{
	 for(i=top;i>=0;i--)
	 {
	 	printf(" %d",stack[i]);
	 }
	}
}


/*#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3 // Altering this value changes size of stack created
int st[MAX]; 
 int top=-1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int main( ) {
int val, option;
do
{
printf("\n *****MAIN MENU*****");
printf("\n 1. PUSH");
printf("\n 2. POP");
printf("\n 3. PEEK");
printf("\n 4. DISPLAY");
printf("\n 5. EXIT");
printf("\n Enter your option: ");
scanf("%d", &option);
switch(option)
{
case 1:
printf("\n Enter the number to be pushed on stack: ");
scanf("%d", &val);
push(st, val);
break;
case 2:
val = pop(st);
if(val != -1)
printf("\n The value deleted from stack is: %d", val);
break;
case 3:
val = peek(st);
if(val != -1)
 printf("\n The value stored at top of stack is: %d", val);
break;
case 4:
display(st);
break;
 }
}while(option != 5);
return 0;
}
void push(int st[], int val)
{
if(top == MAX-1)
{
printf("\n STACK OVERFLOW");
}
else
{
top++;
st[top] = val;
}
}
int pop(int st[])
{
int val;
if(top == -1)
{
printf("\n STACK UNDERFLOW");
return -1;
}
else
{
val = st[top];
top--;
return val;
}
}
void display(int st[])
{
int i;
if(top == -1)
printf("\n STACK IS EMPTY");
else
{
for(i=top;i>=0;i--)
printf("\n %d",st[i]);
printf("\n"); // Added for formatting purposes
}
}
int peek(int st[])
{
if(top == -1)
{
printf("\n STACK IS EMPTY");
return -1;
}
else
return (st[top]);
}*/

