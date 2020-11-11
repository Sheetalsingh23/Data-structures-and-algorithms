#include <iostream>
using namespace std;

class cSparse
{
private:
	int nMat[20][3];
public:
	void fget_sparse();
	void fdisplay_sparse();
	void fadd_sparse(cSparse , cSparse);
    void stranspose_sparse(cSparse);
    void ftranspose_sparse(cSparse);
};
void cSparse::fget_sparse()
{
	cout<<"\nEnter number of Rows, columns, and number of non zero entries : ";
	cin>>nMat[0][0]>>nMat[0][1]>>nMat[0][2];
	for(int i=1;i<=nMat[0][2];i++)
	{
		cout<<"\nEnter the Row number : ";
		cin>>nMat[i][0];
		cout<<"\nEnter the Column number : ";
		cin>>nMat[i][1];
		cout<<"\nEnter the non zero value at that position : ";
		cin>>nMat[i][2];
	}
}
void cSparse::fdisplay_sparse()
{
	cout<<"\n"<<nMat[0][0]<<"\t"<<nMat[0][1]<<"\t"<<nMat[0][2];
	cout<<"\n------------------";
	for(int i=1;i<=nMat[0][2];i++)
	{
		cout<<"\n"<<nMat[i][0]<<"\t"<<nMat[i][1]<<"\t"<<nMat[i][2];
	}
}

void cSparse::fadd_sparse(cSparse a, cSparse b)
	{
		int p=0,q=0;
		nMat[0][0]=a.nMat[0][0];
		nMat[0][1]=a.nMat[0][1];
		p=a.nMat[0][2];
		q=b.nMat[0][2];

		int i=1,j=1,k=1;
		while(i<=p && j<=q)
		{
			if(a.nMat[i][0]==b.nMat[j][0])
			{
				if(a.nMat[i][1]==b.nMat[j][1])
				{
					nMat[k][0]=a.nMat[i][0];
					nMat[k][1]=a.nMat[i][1];
					nMat[k][2]=a.nMat[i][2] + b.nMat[j][2];
					i++;j++;k++;
				}
					else
					{
						if(a.nMat[i][1]<b.nMat[j][1])
						{
							nMat[k][0]=a.nMat[i][0];
							nMat[k][1]=a.nMat[i][1];
							nMat[k][2]=a.nMat[i][2];
							i++;
							k++;
					}
						else
						{
							nMat[k][0]=b.nMat[j][0];
				        	nMat[k][1]=b.nMat[j][1];
							nMat[k][2]=b.nMat[j][2];
							j++;k++;
						}

				}
			}
			else
			{
				if(a.nMat[i][0]<b.nMat[j][0])
				{

					nMat[k][0]=a.nMat[i][0];
					nMat[k][1]=a.nMat[i][1];
					nMat[k][2]=a.nMat[i][2];
					i++;
					k++;
				}
				else
				{

					nMat[k][0]=b.nMat[j][0];
		        	nMat[k][1]=b.nMat[j][1];
					nMat[k][2]=b.nMat[j][2];
					j++;k++;
				}
			}
		}
		while(i<=p)
		{
			nMat[k][0]=a.nMat[i][0];
			nMat[k][1]=a.nMat[i][1];
			nMat[k][2]=a.nMat[i][2];
			i++;
			k++;
		}
		while(j<=q)
		{
			nMat[k][0]=b.nMat[j][0];
			nMat[k][1]=b.nMat[j][1];
			nMat[k][2]=b.nMat[j][2];
			j++;k++;
		}
		nMat[0][2]=k-1;
	}
void cSparse::stranspose_sparse(cSparse b)
{
int k=1;
nMat[0][0]=b.nMat[0][1];
nMat[0][1]=b.nMat[0][0];
nMat[0][2]=b.nMat[0][2];
if(b.nMat[0][2]>0)
{
 for(int i=0;i<b.nMat[0][1];i++)
  {
	for(int j=1;j<=b.nMat[0][2];j++)
	{
		if(i==b.nMat[j][1])
		{
			nMat[k][0]=b.nMat[j][1];
		    nMat[k][1]=b.nMat[j][0];
		    nMat[k][2]=b.nMat[j][2];
	        k++;
		}
     }
   }
 }
else{
	    cout<<"Empty Matrix";
     }
}
void cSparse::ftranspose_sparse(cSparse a)
{
int count[10],index[10];
	nMat[0][0]=a.nMat[0][1];
	nMat[0][1]=a.nMat[0][0];
	nMat[0][2]=a.nMat[0][2];
for(int i=0;i<a.nMat[0][1];i++)
{
count[i]=0;
}
for(int j=1;j<=a.nMat[0][2];j++)
{
count[a.nMat[j][1]]++;
}
index[0]=1;
for(int i=1;i<a.nMat[0][1];i++)
{
	index[i]=index[i-1]+count[i-1];
}
for(int k=1;k<=a.nMat[0][2];k++)
{
	int pstn=0,p=0;
	pstn=a.nMat[k][1];
    p=index[pstn];
    nMat[p][0]=a.nMat[k][1];
    nMat[p][1]=a.nMat[k][0];
    nMat[p][2]=a.nMat[k][2];
    index[pstn]++;
}

}
int main()
{
	cSparse s1,s2,s3,s4,s5;
	char ch;
	int n;
	do
	{
	cout<<"\npress 1 for sparse matrix addition";
	cout<<"\npress 2 for simple transpose of the sparse matrix";
	cout<<"\npress 3 for fast transpose of the sparse matrix";
	cout<<"\nEnter your choice";
	cin>>n;
	switch(n)
	{
	case 1:
		cout<<"\nEnter the entries of sparse matrix A : ";
		s1.fget_sparse();
		cout<<"\nsparse matrix  representation of A : ";
		s1.fdisplay_sparse();
		 cout<<"\nEnter the entries of sparse matrix B : ";
		s2.fget_sparse();
		cout<<"\nsparse matrix  representation of B : ";
		s2.fdisplay_sparse();
		s3.fadd_sparse(s1,s2);
		cout<<"\nAddition of two Entered sparse matrices is : ";
		s3.fdisplay_sparse();
	    break;
	case 2:
		cout<<"\nEnter the entries of sparse matrix : ";
		s1.fget_sparse();
		cout<<"\nsparse matrix  representation  : ";
	    s1.fdisplay_sparse();
	    s4.stranspose_sparse(s1);
	    cout<<"\nSimple transpose of the 1st matrix is : ";
	    s4.fdisplay_sparse();
	    break;
	case 3:
		cout<<"\nEnter the entries of sparse matrix : ";
	    s1.fget_sparse();
	    cout<<"\nsparse matrix  representation  : ";
	    s1.fdisplay_sparse();
	    s5.ftranspose_sparse(s1);
	    cout<<"\nfast transpose of the 1st matrix is : ";
	    s5.fdisplay_sparse();
	    break;
	default:
		cout<<"\nEnter valid choice";
	    }
	cout<<"\nWhether you wish to continue (Y/N) : ";
	cin>>ch;
}while(ch=='y'||ch=='Y');
cout<<"THANK YOU " ;
return 0;
}

