#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct Node
{
	string name;
	int data;
	Node* next;
	Node* prev;
};

class CinemaxTheater
{
	public:
	int r,c;
	Node* header;
	CinemaxTheater()
	{
		header=NULL;
	}
	public:
	void CreateList();
	void BookSeats();
	void RemoveBooking();
	void Display();
	void DisplayDetails();
	
};

void CinemaxTheater::CreateList()
{
	Node*nn;
	Node* temp;
	nn=new Node();
	nn->data=0;
	nn->name="";
	nn->next=NULL;
	nn->prev=NULL;
	if(header==NULL)
	{
		header=nn;
                header->next=header;
                header->prev=header;
	}
	else
	{
		temp=header;
		while(temp->next!=header)
		{
			temp=temp->next;
		}
		temp->next=nn;
		nn->prev=temp;
                nn->next=header;
                header->prev=nn;
	}
}

void CinemaxTheater::BookSeats()
{
	Node* temp;
	cout<<"\nEnter The Row No. In Which You Want To Book(Range 1 To 10)\n";
	cin>>r;
	cout<<"\nEnter The Seat No. Which You Want To Book(Range 1 To 7)\n";
	cin>>c;
	temp=header;
	for(int i=0;i<(7*r-(7-c))-1;i++)
	{
		temp=temp->next;
	}
	if(temp->data==0)
	{
		cout<<"\nEnter The Name Of The Person For Whom The Seat Is To Be Booked\n";
		cin>>temp->name;
		temp->data=1;
	}
	else
	{
		cout<<"\nSorry! Already Booked\n";
	}
}
void CinemaxTheater::RemoveBooking()
{
	Node *temp;
	cout<<"\nEnter The Row No. In Which You Want To Remove the Booking\n";
	cin>>r;
	cout<<"\nEnter The Seat No. For Which You Want To Remove Booking\n";
	cin>>c;
	temp=header;
	for(int i=0;i<(7*r-(7-c))-1;i++)
	{
		temp=temp->next;
	}
	if(temp->data==1)
	{
		temp->data=0;
		cout<<"Congratulations! The Seat Is Free !\n";
	}
	else
	{
		cout<<"\nThe Seat Is Already Free\n";
	}
}
void CinemaxTheater::Display()
{
    cout<<"\n\n\n";
    cout<<"PS: Here 'B' Are The Booked Seats, Whereas 'X' Are Unbooked Seats\n\n";
	Node *temp;
	temp=header;
	cout<<"   ";
	for(int j=1;j<=7;j++)
    {
        if(j!=1)
            cout<<" ";
        cout<<j<<"\t";
    }
    cout<<"\n";
	for(int i=0;i<8*7;i++)
    {
            cout<<"-";
    }
    cout<<"\n";
	for(int i=1;i<=10;i++)
	{
	    cout<<i<<".";
		for(int j=1;j<=7;j++)
		{
			if(temp->data==1)
			{
                cout<<"|";
				cout<<"B";
                cout<<"|"<<"\t";
				temp=temp->next;
			}
			else
			{
                cout<<"|";
				cout<<"X";
				cout<<"|"<<"\t";
				temp=temp->next;
			}

		}
		cout<<"\n";
		for(int i=0;i<8*7;i++)
        {
            cout<<"-";
        }
		cout<<"\n";
	}
}

void CinemaxTheater::DisplayDetails()
{
	cout<<"\nEnter Row No. Whose Details Are To Be Displayed\n";
	cin>>r;
	cout<<"\nEnter The Seat No. Whose Details Are To Be Displayed\n";
	cin>>c;
	Node* temp=header;
	for(int i=0;i<(7*r-(7-c))-1;i++)
    {
        temp=temp->next;
    }
    if(temp->data==1)
    {
        cout<<"\nThe Seat Is Booked By A Person Named:"<<temp->name<<"\n\n";
    }
    else
    {
        cout<<"\nSorry! Since, Seat Is Free, Nothing To Display\n";
    }

}
int main()
{
	int n;
	int p=0;
	CinemaxTheater c;
	for(int i=1;i<=70;i++)
	{
		c.CreateList();
	}
	while(p!=-1)
	{
		cout<<"\nEnter 1 To Book A Seat\n";
		cout<<"\nEnter 2 To Un-book A Seat\n";
		cout<<"\nEnter 3 To Display Details Of The Person Who Has Booked A Seat\n";
		cout<<"\nEnter 4 To Display Overall Theater\n";
		cout<<"\nEnter 5 To Exit\n";
		cout<<"\nEnter Your Choice\n";
		cin>>n;
		switch(n)
		{
			case 1:
			{
				c.BookSeats();
			}
			break;
			case 2:
			{
				c.RemoveBooking();
			}
			break;
			case 3:
			{
			    c.DisplayDetails();
			}
			break;
            case 4:
            {
                c.Display();
            }
                break;
            case 5:
                {
                     p=-1;
                }

                break;
            default:
                cout<<"\nEntered A Wrong Choice\n";
		}
	}
	return 0;
}
