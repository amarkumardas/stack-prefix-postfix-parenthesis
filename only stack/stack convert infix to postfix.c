#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100
int stack[MAX];
int top=-1;
void pushintostack(char);
int isopertor (char);
int precedence(char);
int pop();               //it does not work if incorrect expression
int main()              //incorrect expression will give inorrect answer it does not check incorrect expression 
{
	char infix[100],postfix[100];
	int i=0,j=0,x;
	printf("\nEnter the infix expression: "); 
	gets(infix);
	pushintostack('(');//in stack first elemennt will contain (
		while(infix[i]!=0)
		{
		 i++;
    	}
	infix[i]=')';//putting this ) at last of infix expression because when all evaluation get over at last ) will encounter which means
	               //pop all operator  till this ( is encounter which is in stack 
	infix[i+1]='\0';
	i=0;
	while(infix[i]!=0)
	{
		if(infix[i]=='(')
		{
			pushintostack(infix[i]);
		}
		else if(isdigit(infix[i]) || isalpha(infix[i]))
		{
		   	postfix[j++]=infix[i];
		}
		else if(isopertor(infix[i])==1)
		{
	    	x=pop(); 
		    while(isopertor(x)==1 && precedence(infix[i]) <= precedence(x))//isopertor(x)==1 when x=( then this function will excute isopertor and check which 
			                                                            //is ( not an operator so condition fails while loop fails
			{
			   	postfix[j++]=x;
				   x=pop();	
			}
			pushintostack(x);
			pushintostack(infix[i]);  	
		}
		else if(infix[i]==')')
		{
			x=pop();
			while(x!='(')
			{
				postfix[j++]=x;
				   x=pop();	
            }
		}
		i++;
	}
		postfix[j]='\0';//here if we use postfix[j]=NULL; then we will get warring because NULL = 0 WHICh is integer so since postfix is character array so
		                 //we have to use postfix[j]='\0'; which is null character '\0' that ends the  string array.
		printf("\nExpression are: ");
		puts(postfix);
		getch();
		return 0;  
}
void pushintostack(char val)
{
	if(top==MAX-1)
	{
		printf("\nStack overflow");
	}
	else
	{
		stack[++top]=val;
	}
}
int isopertor (char val)
{
   if(val=='+' || val=='-'|| val=='*'||val=='^'||val=='/')
   {
   	return 1;
   }
   else
   {
   	return 0;
   }	
}
int precedence(char symbol)
{
	if(symbol=='^')
	{
		return 3;
	}
	else if(symbol=='*'||symbol=='/')
	{
		return 2;
	}
	else if(symbol=='+'||symbol=='-')
	{
		return 1;
	}
}
int pop()
{
	char item;
	if(top==-1)
	{
		printf("\nStack underflow no data");
	}
	else
	{
		item=stack[top];
		top--;
		return(item);
	}
}
