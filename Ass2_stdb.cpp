#include <iostream>
using namespace std;
int m[31];		//to store count of students on particular marks
void init()	    //initialize all array index to 0
{
	for(int i=0;i<31;i++)  
        m[31]=0;
}

class Student
{
	int n;
	int rollNo;
	int marks;
	string name;

public:
	static int count; //one copy of data member shared by all objects of class due to static
	static int avg,sum,min,max,absent;

	void init();
	void getdata();
	void printdata();
	void display();
};

	int Student :: count;//defining static variable outside the class
	int Student :: max=0;
	int Student :: min=30;//accessing static data member outside the class
	int Student :: absent;
	int Student :: avg;
	int Student :: sum;

	void Student :: getdata()
	{
		cout<<"\n Enter the rollNo\n ";
		cin>>rollNo;
		cout<<"\n Enter the name\n ";
		cin>>name;
		cout<<"\n Enter the marks\n ";
		cin>>marks;
		if(marks<0)
		{
			Student :: absent++;
		}
		else
		{
			m[marks]++;
			if(Student ::max<marks)
			{
				Student::max=marks;
			}
			if(Student ::min>marks)
			{
				Student ::min=marks;
			}
			sum=sum+marks;
		}

		Student :: count++;
	}

		void Student::printdata()
		{
			cout<<"\n Roll No "<<rollNo;
			cout<<"\t Name "<<name;
			cout<<"\t Marks"<<marks;
		}

		void Student::display()
		{
			cout<<"\n The count of data entries made "<<Student::count;
			cout<<"\n Maximum Score "<<Student::max;
			cout<<"\n Minimum score "<<Student::min;
			cout<<"\n Absent count "<<Student::absent;
			int present;
			present=count-absent;
			Student::avg=sum/present;
			cout<<"\n Average Marks of class "<<Student::avg;
			cout<<"\n maximum number of students scoring same marks ";
			int max=0,mark=0;
			for(int i=0;i<31;i++)
			{
				if(max<m[i])
					{
					max=m[i];
					mark=i;
					}
			}
			cout<<"\n Count "<<max<<"\t Marks "<<mark;

			}


int main()
{
	Student s[100];
	int i=0;
	init();
	while(1)				//to execute infinite times
	{
		cout<<"\n 1: Enter Details for new student";
		cout<<" \n2: Print the details of all students";
		cout<<" \n3: class test details";
		cout<<"\n 4: Exit";
		cout<<" \n Enter your choice";
		int ch;
		cin>>ch;
		switch(ch)
		{
		case 1:s[i].getdata();
				i++;
				break;
		case 2: for(int j=0;j<i;j++)
				s[j].printdata();
				break;
		case 3: s[1].display();
				break;
                


		}
	}
	return 0;
}
