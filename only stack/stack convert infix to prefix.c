#include<stdio.h>
#include<conio.h>
#include<string.h>//to use strlen
#include<ctype.h>
#define MAX 100                       //expression should be valid if not wrong ans
char stack[MAX];
int top=-1;
void reverse(char []);
void pushintostack(char);
int precedence(char);
int isopertor(char);         //we are taking ( as ) and ) as (
char pop();
int main()
{ 
   int i=0,j=0;
   char infix[100],postfix[100],x;
   printf("\nEnter the infix expression: ");
   gets(infix);
   reverse(infix);
	while(infix[i]!=0)
		{
		 i++;
    	}
	infix[i]='(';//putting this ( at last of infix expression because when all evaluation get over at last ( will encounter which mnas pop all 
	               //operator  till this ) is encounter 
	infix[i+1]='\0';
	pushintostack(')');//in stack last element will contain ) which is here means open bracket (
	i=0;
	  while(infix[i]!='\0')
	  {
	  	if(isalpha(infix[i]))
	  	 {
	  	   postfix[j++]=infix[i];
		 }
		  else if(infix[i]==')')
		   {
		     pushintostack(infix[i]);	
		   }
		    else if(isopertor(infix[i])==1)
		     {
		    	x=pop();
		    	while(isopertor(x)==1&&precedence(infix[i])<=precedence(x))
		    //	while( precedence(infix[i])<=precedence(x)) error
		    	{	
		    		postfix[j++]=x;
		    		x=pop();	
				}
				 pushintostack(x);
				 pushintostack(infix[i]);
		     }
		     else if(infix[i]=='(')
		     {		
		     	x=pop();
		     	while(x!=')')
		     	{ 
		     		postfix[j++]=x;
		     		x=pop();
				}
			 }
	     i++;
	  }
	 postfix[j]='\0';
	  reverse(postfix );
	  printf("Prefix expression: ");
	   puts(postfix);
   getch();
   return 0;	
}
void reverse(char exp[])
{
   int length,i,k;
   char temp;
   length=strlen(exp);
   i=0,k=length-1;
   while(i<k)
   {
   	  temp=exp[i];
   	  exp[i]=exp[k];
   	  exp[k]=temp;
   	  i++,k--;
   }  	
}
void pushintostack(char val)
{
  if(top==MAX-1)
  {
  	printf("\nStackoverflow no space");
  }
  else
  {
  	stack[++top]=val;
  }
}
int isopertor(char val)
{
   if(val=='+'||val=='-'||val=='*'||val=='^'||val=='/')
   return 1;
   else
   return 0;	
}
char pop( )
{
	char x;
	 if(top==-1)
	 {
	 	printf("\nStack underflow no data");
	}
	else
	{
	  x=stack[top];
	   top--;
		return(x);
	}
}
int precedence(char val)
{
	if(val=='^')
	return 3;
	 else if(val=='*'||val=='/')
	 return 2;
	 else if(val=='+'|| val=='-')
	 return 1;
}
 
