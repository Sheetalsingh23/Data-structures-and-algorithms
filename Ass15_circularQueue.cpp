#include<bits/stdc++.h>
using namespace std;
struct patient{
    string name;
    int id;
};
class Queue
{
    public:
	int rear, front;
	int size;
	patient *arr;
	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new patient[s];
	}
	void enQueue();
	patient deQueue();
	void displayQueue();
};
void Queue::enQueue()
{
    string name; int value;
	if ((front == 0 && rear == size-1) ||(rear == (front-1)%(size-1)))
	{
		cout<<"\nQueue is Full";
		return;
	}
	else if (front == -1) /* Insert First Element */
	{

        cout<<"Enter name and ID:\n";
        cin>>name;
        cin>>value;
		front = rear = 0;
        arr[rear].id=value;
        arr[rear].name=name;
	}
	else if (rear == size-1 && front != 0)
	{
		rear = 0;
         cout<<"Enter name and ID:\n";
        cin>>name;
        cin>>value;
        arr[rear].id=value;
        arr[rear].name=name;
	}
	else
	{
		rear++;
         cout<<"Enter name and ID:\n";
        cin>>name;
        cin>>value;
        arr[rear].id=value;
        arr[rear].name=name;
	}
}
patient Queue::deQueue()
{
	if (front == -1)
	{
		cout<<"\nQueue is Empty";
        struct patient p;
		return p;
	}
	patient data = arr[front];
     cout<<"Element deleted is : "<<arr[front].id<<" "<<arr[front].name<<endl;
	// arr[front] = ;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
	if (front == -1)
	{
		cout<<"\nQueue is Empty";
		return;
	}
	cout<<"\nElements in Circular Queue are: \n";
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			cout<<arr[i].id<<" "<<arr[i].name<<"\n";
	}
	else
	{
		for (int i = front; i < size; i++)
			cout<<arr[i].id<<" "<<arr[i].name<<"\n";

		for (int i = 0; i <= rear; i++)
			cout<<arr[i].id<<" "<<arr[i].name<<"\n";
	}
}

/* Driver of the program */
int main()
{
   Queue q(5);
   int ch;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   do{
      cout<<"Enter choice : "<<endl;
      cin>>ch;
       switch(ch) {
         case 1:
         q.enQueue();
         break;

         case 2:
         q.deQueue();
         break;

         case 3:
         q.displayQueue();
         break;
         default: cout<<"Incorrect!\n";
    }
    }
    while(ch != 4);
	return 0;
}
