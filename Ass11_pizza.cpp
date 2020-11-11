#include<iostream>
using namespace std;
#define size 5
class PizzaQue
{
   struct queue
   {
     int que[size];
     int front, rear;
   }Q;
   public:
     PizzaQue()
      {
        Q.front=-1;
        Q.rear=-1;
      }
     int Qfull();
     int Qempty();
     int Accept(int);
     int Ready();
     void Display();
};
 int PizzaQue::Qfull()
   {
     if(Q.front==(Q.rear+1)%size)
         return 1;
     else
         return 0;
   }

int PizzaQue::Qempty()
   {
     if(Q.front==-1)
        return 1;
     else
        return 0;
   }

int PizzaQue::Accept(int item)
   {
	     if(Q.front==-1)
	        Q.front=Q.rear=0;
	     else
	      Q.rear=(Q.rear+1)%size;
	      Q.que[Q.rear]=item;
	     return Q.rear;
     
   }

int PizzaQue::Ready()
   {
   
      cout<<"\n The order no : "<<Q.que[Q.front]<<" is Ready";
if(Q.front==Q.rear)
Q.front=Q.rear=-1;
else
      Q.front=(Q.front+1)%size;
       
     
   }

void PizzaQue:: Display()
   {
    int i;
    i=Q.front;
     while(i!=Q.rear)
     {
         cout<<" "<<Q.que[i];
         i=(i+1)%size;
     }
     cout<<" "<<Q.que[i];
   }

int main()
{
  int choice,item;
  PizzaQue obj;
  do
  {
     cout<<"\n Main Menu";
     cout<<"\n 1.ADD Order \n 2.Ready Order \n 3. Display Order Queue";
     cout<<"\n Enter Your Choice";
     cin>>choice;
     switch(choice)
     {
        case 1: if(obj.Qfull())
                    cout<<"\n Can not accept order";
                else
                 {
                   cout<<"\n Enter The order number: ";
                   cin>>item;
                   obj.Accept(item);
                 }
                break;
        case 2: if(obj.Qempty())
                    cout<<"\n No Order Ready";
                else
                   obj.Ready();
                break;

        case 3: if(obj.Qempty())
                    cout<<"\n Order queue is empty";
                else
                   obj.Display();
                break;
        default : cout<<"\n wrong choice";
      }
     
  }while(choice<=3);
}    
