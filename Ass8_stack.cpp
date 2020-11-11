#include<iostream>
#include<string.h>
using namespace std;
#define MAX 50

class StClass
{

	struct stknode
	{
		char stack[MAX];
		int top;
	}st;

public:
	StClass()
	{
		st.top=-1;
	}
	void push(char);
	char pop();
	int check(char exp[MAX]);
	 int match(char a, char b);
};

int StClass:: check(char exp[])
{
	int i;
	char temp;
	int n= strlen(exp);
	for(i=0;i<n;i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		push(exp[i]);
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
		if(st.top==-1)
		return 0;
		else
		{
			temp=pop();
			if(!match(temp,exp[i]))
			return 0;
		}
	}
	if(st.top==-1)
	return 1;
	else
	return 0;
}

int StClass::match(char a, char b)
{
	if(a=='[' && b==']')
	return 1;
	if(a=='{' && b=='}')
	return 1;
	if(a=='(' && b==')')
	return 1;
	return 0;
}

void StClass::push(char item)
{
	if(st.top==(MAX-1))
	{
		cout<<"Stack Overflow \n";
		return;
	}
	st.top=st.top+1;
	st.stack[st.top]=item;
}

char StClass::pop()
{
	if(st.top==-1)
	{
		cout<<"stack Underflow \n";
	}
	return(st.stack[st.top--]);
}

int main()
{
	char exp[MAX];
	int status;
	StClass obj;
	cout<<"Enter a parenthesized expression: ";
	cin>>exp;
	status= obj.check(exp);
	if(status==1)
		cout<<"The expression is well paranthesized \n";
	else
		cout<<"The expression is not well paranthesized \n";
	return 0;
}





