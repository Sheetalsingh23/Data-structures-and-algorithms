#include <iostream>
using namespace std;

class post
{
	char expr[20]="",out[20]="",stack[15];
	int stack1[15];
	int top=-1,j=0;

public:
	void getData();
	int getPrecedence(char);
	void push(char);
	char pop();
	void push_int(int);
	int pop_int();
	void evaluate();
	int stEmpty();
	void convert();
};

void post::getData()
{
	cout<<"\nEnter Infix Expression:";
	cin>>expr;
}

int post::getPrecedence(char ch)
{
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/')
		return 2;
	else
		return 0;
}

void post::push(char ch)
{
	stack[++top]=ch;
}

char post::pop()
{
	return stack[top--];
}


int post::stEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void post::convert()
{
	int i=0;
	char tmp;
	while(expr[i]!='\0')
	{
		if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
		{
			push(expr[i]);
		}
		else if(expr[i]==')' || expr[i]==']' || expr[i]=='}')
		{
			if(expr[i]==')')
			{
				while(stack[top]!='(')
				{
					out[j++]=pop();
				}
			}
			if(expr[i]==']')
						{
							while(stack[top]!='[')
							{
								out[j++]=pop();
							}
						}
			if(expr[i]=='}')
						{
							while(stack[top]!='{')
							{
								out[j++]=pop();
							}
						}

	tmp=pop();
		}
		else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/')
		{
			if(getPrecedence(stack[top]) >= getPrecedence(expr[i]))
			{
				out[j++]=pop();
				push(expr[i]);
			}
			else
			{
				push(expr[i]);
			}
		}
		else
		{
			out[j++]=expr[i];
		}

		i++;
	}

	if(top!=-1)
	{
		while(top>=-1)
		{
			out[j++]=pop();
		}
	}

	out[j]='\0';

	cout<<"\nPostfix expression is:";
	for(i=0;out[i]!='\0';i++)
		cout<<out[i];
}

void post::push_int(int ch)
{
	stack1[++top]=ch;
}

int post::pop_int()
{
	return stack1[top--];
}

void post::evaluate()
{
	int i=0;
	int op1=0,op2=0;

	while(out[i]!='\0')
	{

		if(out[i]=='+')
		{
			op2=pop_int();
			op1=pop_int();
			push_int(op1+op2);

		}
		else if(out[i]=='-')
		{
			op2=pop_int();
			op1=pop_int();
			push_int(op1 - op2);

		}
		else if(out[i]=='*')
		{
			op2=pop_int();
			op1=pop_int();
			push_int(op1 * op2);

		}
		else if(out[i]=='/')
		{
			op2=pop_int();
			op1=pop_int();
			push_int(op1 / op2);

		}
		else
		{
			push_int((int)out[i]-48);
		}

		i++;
	}

	cout<<"\n\nEvaluation is:"<<pop_int()<<"\n";

}

int main()
{
	post p;

	p.getData();
	p.convert();
	p.evaluate();

	return 0;
}

/*OUTPUT

Enter Infix Expression:(a*b)

Postfix expression is:ab*

Evaluation is:2450
*/