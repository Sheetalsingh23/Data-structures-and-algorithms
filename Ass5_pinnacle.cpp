
#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;
struct Node
{
	string name;
	int prn;
	Node* next;
};
class Pinnacle
{
	public:
	Node* header;
	Node *temp1;int m;int k;
	Node *footer;
	Pinnacle()
	{
		header=NULL;
		 k=0;
	}
	void InsertMember();
	void DisplayList();
	void DeleteMember();
	void ConcatLists();
	void DeleteFirst();
	void DeleteLast();
	int CheckIfPresent();
	void Reverse();
	void AppendTwoLists(Pinnacle);
};
void Pinnacle::InsertMember()
{
	Node *nn;
	Node *temp;
	nn=new Node();
	nn->next=NULL;
	int k=0;
	cout<<"\nEnter The Name Of The Student\n";
	cin>>nn->name;
	cout<<"\nEnter The PRN No Of The Student\n";
	cin>>nn->prn;
	temp=header;
	while(temp!=NULL)
	{
		if(temp->prn==nn->prn)
		{
			cout<<"\nOne Member Already Exist With This PRN No! So Try Again\n";k=1;
		}
		temp=temp->next;
	}
	if(k!=1)
	{
		if(header==NULL)
		{
			header=nn;
		}
		else
		{
			temp=header;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=nn;

		}
	}
}
void Pinnacle::DeleteMember()
{
    int a=CheckIfPresent();
    if(a==0)
    {
        cout<<"\n\nAll Members Already Deleted ! Nothing To Delete!\n\n";
    }
    else
    {
        cout<<"\nEnter The PRN No Of Student To Be Removed\n";
        int n;
        cin>>n;
        Node* temp;
        temp=header;
        Node *last;
        last=header;
        Node *temp1;
        temp1=temp->next;
        while(last->next!=NULL)
        {
            last=last->next;
        }
        if(temp->prn==n)
        {
            int a=CheckIfPresent();
            if(a>2)
            {
                cout<<"\nSorry! Unless All Members Are Deleted , You Can't Delete The President Or Secretary\n";
            }
            else
            {
                DeleteFirst();
            }
        }
        else if(last->prn==n)
        {
            int a=CheckIfPresent();
            if(a>2)
            {
                cout<<"\nSorry! Unless All Members Are Deleted , You Can't Delete The President Or Secretary\n";
            }
            else
            {
                DeleteLast();
            }
        }
        else
        {
            while(temp1!=NULL)
            {
                if(temp1->prn==n)
                {
                    temp->next=temp->next->next;
                }
                temp1=temp1->next;
            }
        }

    }

}
int Pinnacle::CheckIfPresent()
{
	Node *temp;
	int a=0;
	temp=header;
	while(temp!=NULL)
	{
		temp=temp->next;
		a++;
	}
	/*temp=header;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	footer=temp;*/
	return a;
}
void Pinnacle::DisplayList()
{
    int a=CheckIfPresent();
    if(a==0)
    {
        cout<<"\n\nAll Members Already Deleted ! Nothing To Display\n\n";
    }
    else
    {
        Node* temp;
        temp=header;
        for(int i=0;i<40;i++)
        {
            cout<<"-";
        }

        cout<<"\n";
        cout<<"\nPresident Is:";
        cout<<temp->name<<" And His "<<"PRN :"<<temp->prn;
        cout<<"\n";
        for(int i=0;i<40;i++)
        {
            cout<<"-";
        }
        cout<<"\n\n\t\tMembers Are\n";
        for(int i=0;i<40;i++)
        {
            cout<<"-";
        }
        cout<<"\n";
        cout<<"\t"<<setw(12)<<"Name"<<setw(8)<<"PRN\n\n";
        while(temp!=NULL)
        {
            cout<<"\t"<<setw(12)<<temp->name<<"|"<<setw(4)<<temp->prn;
            temp=temp->next;
            cout<<"\n";
        }
        Node *temp1;
        temp=header;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp1=temp;
        for(int i=0;i<40;i++)
        {
            cout<<"-";
        }
        cout<<"\n\nSecretary Is:";
        cout<<temp1->name<<" And His PRN :"<<temp1->prn;
        cout<<"\n";
        for(int i=0;i<40;i++)
        {
            cout<<"-";
        }
        cout<<"\n\n";
    }

}
void Pinnacle::Reverse()
{
	if(m!=0)
	{
		temp1=header;
		for(int i=0;i<m-1;i++)
		{
			temp1=temp1->next;
		}
		cout<<"Name: "<<temp1->name<<"  PRN: "<<temp1->prn;
		cout<<"\n";
		--m;
		Reverse();
	}
	
}
void Pinnacle::DeleteFirst()
{
	cout<<"\nPresident Deleted! Now Second Member Becomes President\n";
	Node *temp;
	header=header->next;
}
void Pinnacle::DeleteLast()
{
	if(header!=NULL)
	{
		cout<<"\nSecretary Deleted! Now The Student Before Secretary Is New Secretary\n";
		Node *temp;
   		Node *temp1;
   	 	temp=header->next;
   	 	temp1=header;
   	 	while(temp->next!=NULL)
   	 	{
   	     		temp1=temp;
   	     		temp=temp->next;
   	 	}
  	 	delete temp;
    		temp1->next=NULL;
    	}
   	else
        cout<<"\nYou Haven't Entered Any Element\n";
}
void Pinnacle::AppendTwoLists(Pinnacle p)
{
    Node *temp;
    temp=this->header;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p.header;
}
int main()
{

	Pinnacle l,s,q,r;
	int p;int n;int x;int y=0;
	while(y!=-1)
    {
        cout<<"\nEnter 1 To Take Inputs OR Make Changes In First Class\n";
        cout<<"\nEnter 2 To Take Inputs OR Make Changes In Second Class\n";
        cout<<"\nEnter 3 To Append Two List\n";
        cout<<"\nEnter 4 To Display Appended List\n";
        cout<<"\nEnter 5 To Exit\n";
        cout<<"\nEnter Your Choice\n";
        cin>>x;
        switch(x)
        {
            case 1:
            {
                p=0;
                while(p!=-1)
                {
                cout<<"\nEnter 1 To Insert A Member\n";
                cout<<"\nEnter 2 To Delete A Member\n";
                cout<<"\nEnter 3 To Display Member List\n";
		cout<<"\nEnter 4 To Display In Reverse Manner\n";
                cout<<"\nEnter 5 To Exit\n";
                cin>>n;
                switch(n)
                {
                    case 1:
                    {
                        l.InsertMember();
                    }
                    break;
                    case 2:
                    {
                        l.DeleteMember();
                    }
                    break;
                    case 3:
                    {
                        l.DisplayList();
                    }
                    break;
		    case 4:
		    {
			l.m=l.CheckIfPresent();
			l.temp1=l.header;
			l.Reverse();
	            }
                    case 5:
                    {
                        p=-1;
                    }
                    break;
                }
            }

        }
        break;
        case 2:
            {
                p=0;
                while(p!=-1)
                {
                    cout<<"\nEnter 1 To Insert A Member\n";
                    cout<<"\nEnter 2 To Delete A Member\n";
                    cout<<"\nEnter 3 To Display Member List\n";
                    cout<<"\nEnter 4 To Display In Reverse Manner\n";
	 	    cout<<"\nEnter 5 To Exit\n";
                    cin>>n;
                    switch(n)
                    {
                        case 1:
                        {
                            s.InsertMember();
                        }
                        break;
                        case 2:
                        {
                            s.DeleteMember();
                        }
                        break;
                        case 3:
                        {
                            s.DisplayList();
                        }
                        break;
			case 4:
			{
				s.m=s.CheckIfPresent();
				s.temp1=s.header;
				s.Reverse();
			}
                        case 5:
                        {
                            p=-1;
                        }
                        break;
                    }
                }

            }
            break;
            case 3:
                {
                    if(l.CheckIfPresent()>=1&&s.CheckIfPresent()<1)
                    {
                        cout<<"\nOnly Members Of First Class Are Entered! So Could Not Append! Only First Class Members Will Be Displayed\n";
                        l.DisplayList();
                    }
                    else if(l.CheckIfPresent()<1&&s.CheckIfPresent()>=1)
                    {
                         cout<<"\nOnly Members Of Second Class Are Entered! So Could Not Append! Only Second Class Members Will Be Displayed\n";
                         s.DisplayList();
                    }
                    else if(l.CheckIfPresent()>=1&&s.CheckIfPresent()>=1)
                    {
                        cout<<"\n\nList Has Been Appended\n\n";
                        q=l;
                        r=s;
                        q.AppendTwoLists(r);

                    }
                    else if(l.CheckIfPresent()<1&&s.CheckIfPresent()<1)
                    {
                        cout<<"\nSorry! You Haven't Enter Members In Any Of The Classes! Nothing To Append!Try Again!\n";
                    }
                }
                break;
            case 4:
                {
                    if(l.CheckIfPresent()>=1&&s.CheckIfPresent()<1)
                    {
                        cout<<"\nOnly Members Of First Class Are Entered!Only First Class Members Will Be Displayed\n";
                        l.DisplayList();
                    }
                    else if(l.CheckIfPresent()<1&&s.CheckIfPresent()>=1)
                    {
                         cout<<"\nOnly Members Of Second Class Are Entered!Only Second Class Members Will Be Displayed\n";
                         s.DisplayList();
                    }
                    else if(l.CheckIfPresent()>=1&&s.CheckIfPresent()>=1)
                    {
                        q.DisplayList();

                    }
                    else if(l.CheckIfPresent()<1&&s.CheckIfPresent()<1)
                    {
                        cout<<"\nSorry! You Haven't Enter Members In Any Of The Classes! Nothing To Append!Try Again!\n";
                    }

                }
                break;
            case 5:
                y=-1;
                break;




        }

    }
	return 0;
}

