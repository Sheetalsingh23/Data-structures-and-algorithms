#include <iostream>
using namespace std;

class student
{

public:
    int roll[50],m;
void accept();
void display();
void linear(int);
int binary(int);
//void bubble_sort();
//void sentinel(int);
int fib(int n);
int fibsearch(int ar[],int k,int f,int a,int b);
};
void student::accept()
{
cout<<"enter the total no of students:";
cin>>m;
cout<<"enter the roll no of students attending the program: ";
for(int i=0;i<m;i++)
{
cin>>roll[i];
}
}
void student::display()
{
cout<<"\nRoll no of students attending the program are:\n";
for(int i=0;i<m;i++)
{
cout<<roll[i]<<"\t";
}
}
void student::linear(int x)
{
    int i,l=0;
    for( i=0;i<m;i++)
    {
        if(roll[i]==x)
    {
        cout<<"\nRoll no\t"<<roll[i]<<"is present"<<endl;
        l++;
        break;
    }
    }
    if(l==0)
    cout<<"\nRoll no is absent"<<endl;
    }

int student::binary(int p)
{
int low,high,mid;
low=0;
high=m-1;
mid=(low+high)/2;
while(low<=high && roll[mid]!=p)
{
 if(p>roll[mid])
{
low=mid+1;
}
else
high=mid-1;
mid=(low+high)/2;
}
if(low<=high)
    return mid;
return (-1);
}

int student::fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return (fib(n-1)+fib(n-2));
}
int student::fibsearch(int ar[30],int key,int f,int a,int b)
{
    int temp;
    if(key==ar[f-1])
        return f;
    if(key>ar[f-1])
    {
        if(b==1)
            return (-1);
        f=f+a;
        b=b-a;
        a=a-b;
        return(fibsearch(ar,key,f,a,b));
    }
    else
    {
        if(a==0)
            return(-1);
        f=f-a;
        temp=b-a;
        b=a;
        a=temp;
        return(fibsearch(ar,key,f,a,b));

    }
}

int main()
{
student s;
int t;
char k;
int ch;
do
{
    cout<<"\n_________MENU________\n";
    cout<<"\n1.accept roll no.s and display it \n2.linear search\n3.fibonacci search\n";
cout<<"\n enter your choice";
cin>>ch;
switch(ch)
{
case 1:
    s.accept();
s.display();
break;
case 2:
    cout<<"\n enter the roll no you want to search:";
cin>>t;
    s.linear(t);
    break;

case 3:
    int k,a,b,f,result;
    cout<<"\n enter the roll no you want to search:";
    cin>>t;
    for(k=1;s.fib(k)<=s.m;k++);
    b=s.fib(k-2);
    a=s.fib(k-3);
    f=s.m-b+1;
    result=s.fibsearch(s.roll,t,f,a,b);
    if(result==-1)
        cout<<"roll no is absent";
    else
        cout<<"roll no is present";

    break;
}
cout<<"\n do you want to continue?\t";
cin>>k;
}while(k=='y');

}
