#include<stdio.h>
#include<conio.h>
#define MAX 10
void pushintostack(char);
void pop(void);
int top=-1;
char stack[MAX];
int main()
{
	int i=0;
	char exp[30];
	printf("\nEnter the expression: ");
	gets(exp);
	 while(exp[i]!=0)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
		 {
		 	pushintostack(exp[i]);
		 }
		 else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		 {
		 	 if(top==-1)
			 {
			 	printf("\nExpression is not balanced");
			 	return -1;//means terminate
			 }
		 	else if(exp[i]==')' && stack[top]=='(' )
		 	     {
		 	   	  pop();
			     }
			else if(exp[i]==']' && stack[top]=='[') 
		 	     {
		 	  	  pop();
			     }
			else if(exp[i]=='}' && stack[top]=='{')
		     	{
		 	    	pop();
			    }
				else
				{
				   //when top three condition become false that means parenthesis is not matching with the stack
					break;//terminate while loop
				}		 
		 }
		 i++;
	}
	(top==-1)?printf("\nExpression is balanced"):printf("\nExpression is not balanced");
	getch();
	return 0;
}
void pushintostack(char exp)
{
	if(top==MAX-1)
	{
		printf("\nStack overflow no space");
	}
	else
	{
		stack[++top]=exp;
    }
}
void pop(void)
{	 
		--top;
       
}
