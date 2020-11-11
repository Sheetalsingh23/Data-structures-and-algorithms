#include<iostream>
using namespace std;
class StringOperation
{
char str1[10], str2[10];
public:
    int String_strlen();
    void String_strcpy();
    void String_strcat();
    void String_strrev();
    int String_strcmp();
    void String_strstr();
};
 int StringOperation:: String_strlen()
{
  int i;
cout<<"\n Enter String  ";
cin>>str1;
for(i=0;str1[i]!='\0';i++);
return i;
}
void StringOperation:: String_strcpy()
{
  int i,j=0;
cout<<"\n Enter String  ";
cin>>str1;
for(i=0;str1[i]!='\0';i++)
{
   str2[j]=str1[i];
j++;
}
str2[j]='\0';
cout<<"\n The copied string is  "<<str2;
}

void StringOperation:: String_strcat()
{
  int i,j;
cout<<"\n Enter 1st String ";
cin>>str1;
cout<<"\n Enter 2nd String ";
cin>>str2;
for(i=0;str1[i]!='\0';i++);
for(j=0;str2[j]!='\0';j++)
  {
    str1[i]=str2[j];
    i++;
}
str1[i]='\0';
cout<<"\n The concatenated string is "<<str1;
}
void StringOperation:: String_strrev()
{
  int i,j,n;
cout<<"\n Enter String ";
cin>>str1;
for(i=0;str1[i]!='\0';i++);
n=i;
j=0;
for(i=n-1;i>=0;i--)
  {
    str2[j]=str1[i];
    j++;
}
str2[j]='\0';
cout<<"\n The reversed string is "<<str2;
}
int StringOperation:: String_strcmp()
{
  int i,j=0, flag=0;
cout<<"\n Enter 1st String ";
cin>>str1;
cout<<"\n Enter 2nd String ";
cin>>str2;
for(i=0;str1[i]!='\0';i++)
  {
    if(str1[i]==str2[j])
    j++;
    else
     {
      flag=1;
      break;
     }
  }
if(flag==1)
   return 1;
else
   return 0;
}
void StringOperation:: String_strstr()
{
	int i,j,n,m,flag=0;
	cout<<"\n Enter 1st string  ";
	cin>>str1;
	cout<<"\n Enter substring  ";
	cin>>str2;
	for(i=0;str1[i]!='\0';i++);
	n=i;
	for(j=0;str2[j]!='\0';j++);
	m=j;
	j=0;
	for(i=0;i<n;i++)
	{
		 if(str1[i]==str2[j])
		 {
			 j++;
		     if(str2[j]==NULL) //reaching at the end of substring
		    	 {
		    	 flag=1;
		    	 cout<<"\n The substring found at "<<(i+2-m)<<" position.";
		    	 j=0; // resetting the index of substring

		    	 }
		 }
	}
	if(flag==0)
		cout<<"\n The substring is not present";
}
int main()
{
StringOperation s;
int length, choice;
do
{
 cout<<"\n Program for performing string operations without using library functions ";
cout<<"\n 1:Length \n 2:Copy \n 3:Concatenate\n 4:Reverse\n 5:Compare \n 6: Substring \n 7:Exit";
cout<<"\n Enter your choice";
cin>>choice;

switch(choice)
{
case 1: length=s.String_strlen();
        cout <<"\n Length of string is  "<<length;
        break;
case 2: s.String_strcpy();
        break;
case 3: s.String_strcat();
        break;
case 4: s.String_strrev();
        break;
case 5: if(s.String_strcmp()==0)
               cout<<"\n Two strings are equal";
        else
               cout<<"\n Two strings are not equal";
        break;
case 6: s.String_strstr();
        break;
case 7: break;
default:
            cout << endl << "You entered wrong choice." ;
    }
  }while(choice!=7);

	return 0;
}




