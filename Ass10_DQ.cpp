#include <iostream>
using namespace std;
#define SIZE 30
class DQ
{
    int data[SIZE];
    int front1,rear;
public:
    DQ()
    {
        front1=-1;
        rear=-1;
    }
    int isqueuefull();
    int isqueueempty();
    void enqueueF(int);
    void enqueueR(int);
    int dequeueF();
    int dequeueR();
    void display();
} ;
int DQ::isqueueempty()
{
    if(rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DQ::isqueuefull()
{
    if((rear+1)%SIZE==front1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void DQ::enqueueF(int x)
{
    if(isqueueempty())
    {
        front1=0;
        rear=0;
        data[rear]=x;
    }
    else
    {
        front1=(front1-1+SIZE)%SIZE;
        data[front1]=x;
    }
}

void DQ::enqueueR(int x)
{
    if(isqueueempty())
    {
        front1=0;
        rear=0;
        data[rear]=x;
    }
    else
    {
        rear=(rear+1)%SIZE;
        data[rear]=x;
    }
}

int DQ::dequeueF()
{
    int y;
    y=data[front1];
    if(rear==front1)
    {
        front1=-1;
        rear=-1;
    }
    else
    {
        front1=(front1+1)%SIZE;
    }
    return y;
}

int DQ::dequeueR()
{
    int y;
    y=data[rear];
    if(rear==front1)
    {
        front1=-1;
        rear=-1;
    }
    else
    {
        rear=(rear-1+SIZE)%SIZE;
    }
    return y;
}
void DQ::display()
{
   int i;
   i=front1;
   cout<<"\n DATA:";
   while(i!=rear)
   {
    cout<<data[i]<<" ";
    i=(i+1)%SIZE;
   }
   cout<<data[i]<<" ";
}
int main()
{
    int n,n1,x;
    char ch;
    DQ d;
    do
    {
        cout<<"\n *********DEQUE*********";
        cout<<"\n         1.Create";
        cout<<"\n         2.Insert(front)";
        cout<<"\n         3.Insert(rear)";
        cout<<"\n         4.Delete(front)";
        cout<<"\n         5.Delete(rear)";
        cout<<"\n Enter your choice";
        cin>>n1;
        switch(n1)
        {
        case 1:
            cout<<"\n Enter no.of elements";
            cin>>n;
            cout<<"\n Enter DATA";
            for(int i=0;i<n;i++)
            {
                cin>>x;
                if(d.isqueuefull())
                {
                    cout<<"\n Queue is full";
                }
                else
                {
                    d.enqueueR(x);
                }
            }
            d.display();
            break;
        case 2:
            cout<<"\n Enter DATA";
                cin>>x;
                if(d.isqueuefull())
                {
                    cout<<"\n Queue is full";
                }
                else
                {
                    d.enqueueF(x);
                }
            d.display();

            break;
        case 3:
             cout<<"\n Enter DATA ";
                cin>>x;
                if(d.isqueuefull())
                {
                    cout<<"\n Queue is full";
                }
                else
                {
                    d.enqueueR(x);
                }
            d.display();
            break;
        case 4:
             if(d.isqueueempty())
             {
                 cout<<"\n Queue is empty";
             }
             else
             {
                 x=d.dequeueF();
             }
             d.display();
             cout<<"\n Deleted element is"<<x;
            break;
        case 5:
             if(d.isqueueempty())
             {
                 cout<<"\n Queue is empty";
             }
             else
             {
                 x=d.dequeueR();
             }
             d.display();
             cout<<"\n Deleted element is"<<x;
            break;
        }
        cout<<"\n Do you wish to continue";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}

