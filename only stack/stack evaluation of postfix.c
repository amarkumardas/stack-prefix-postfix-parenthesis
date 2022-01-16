#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//exit() is a library function, the respecive prototypes are present in the stdlib.h 
             //header file, inoder to call the process to specified code for exit function, you need to attach the as #include stdlib.h header in your program.
#include<ctype.h>
#include<math.h>
#define MAX 20
int top=-1;
int stack[MAX];    //it work for singal digit only  it can be solve by using scanf function if we use scanf then we have to use for loop
void pushintostack(char); //if expression is invalid it produce   invalid expression
int isoperator(char);
int pop();
int main()
{ 
    char exp[100];
    int i=0;
    int top1,top2;
	printf("\nEnter postfix expression: ");
	gets(exp);
	while(exp[i]!=0)
	{
		if(isdigit(exp[i]))
		{
			 pushintostack(exp[i]-'0'); //character - '0' is used for getting digit rather than ASCII code of digit.
			                           // ascii code for 0 is 48 so exp[i] is '1' then ascii 49-48=1 so if we prind using %d then we will get 1 as digit 
		}
		else if(isoperator(exp[i])==1)
		{
		   top2=pop();
		   top1=pop();
		   switch(exp[i])
		   {
		   	    case '+':pushintostack(top1+top2); 
		   	  	break;
		   	  	case '-':pushintostack(top1-top2);
		   	  	break;
		   	  	case '*':pushintostack(top1*top2);
		   	  	break;
		   	  	case '^':pushintostack(pow(top1,top2)); 
		   	  	break;
		   	  	case '/':pushintostack(top1/top2);
		   	  	break;
			}	
		}
		i++;
	}
	printf("%d",stack[0]);//when evaluation get over the right ans will be stored in this position stack[0]	 
	getch();
	return 0;

}
void pushintostack(char val)
{
	if(top==MAX-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		stack[++top]=val;
	}
}
int isoperator(char val)
{
	if (val=='+'||val=='-'||val=='/'||val=='*'||val=='^')
	return 1;
	else
	return 0;
}
int pop()
{
	 
	if(top==-1)
	{
		printf("\nInvalid expression");
		 exit(0);
	}
	else
	{
		return(stack[top--]);
	}
}
