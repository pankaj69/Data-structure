#include<iostream>
#include<conio.h>
using namespace std;
class diagonal
{
	public:
		int *a,s;
		diagonal(int size)
		{
			s=size;
			a=new int[s];
		}
		void set(int i,int j,int val)
		{
			if(i<0 || j<0 || i>s || j>s)
			{
				return;
			}
			if(i==j)
			{
				a[i]=val;
			}
		}
		
		int get(int i,int j)
		{
			if(i!=j)
				return 0;
			else 
				return i;
		}
		
		void display()
		{
			cout<<"Elements in array are "<<endl;
			for(int i=0;i<s;i++)
			{
				cout<<a[i];
				cout<<endl;
			}
		}
		
};


int main()
{
	int r,c,n,a;
	char ch;
	cout<<"Enter the rows for a square matrix "<<endl;
	cin>>r;
	c=r;
	diagonal d(r);
	
	do
	{
		cout<<"Enter your choice among following "<<endl;
		cout<<"****DIAGONAL MATRIX**** "<<endl;
		cout<<"1.Set an element "<<endl;
		cout<<"2.Get en element "<<endl;
		cout<<"****LOWER TRIANGULAR MATRIX**** "<<endl;
		cout<<"3.Set an element "<<endl;
		cout<<"4.Get en element "<<endl;
		cout<<"****UPPER TRIANGULAR MATRIX****"<<endl;
		cout<<"5.Set an element "<<endl;
		cout<<"6.Get en element "<<endl;
		cout<<"****SYMMETRIC MATRIX**** "<<endl;
		cout<<"7.Set an element "<<endl;
		cout<<"8.Get en element "<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
				cout<<"Enter the diagonal elements in matrix "<<endl;
					for(int i=0;i<r;i++)
					{
						for(int j=0;j<r;j++)
						{
							if(i==j)
							{
								cin>>n;
								d.set(i,j,n);
							}
						}
					}
					break;
			case 2:
				d.display();
				break;
		}
		cout<<"Press y to continue "<<endl;
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	
	
	getch();
	return 0;
}
