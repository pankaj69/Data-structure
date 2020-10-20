#include<iostream>
#include<conio.h>
using namespace std;
template <class T>
class stack
{
	int top,size;
	T *arr;
	public:
		stack(int n)
		{
			arr=new int[n];
			size=n;
			top=-1;
		}
		
		bool isempty()
		{
			if(top==-1)
			return true;
			else
			return false;
		}
		bool isfull()
		{
			if(top==size-1)
			return true;
			else
			return false;
		}
		void push(T val)
		{
			if(!isfull())
			{
				arr[++top]=val;
				cout<<"Element inserted "<<endl;
			}
			else
			{
				cout<<"stack is full "<<endl;
			}
		}
		T pop()
		{
			if(isempty())
			cout<<"Stack is empty "<<endl;
			else
			{
				cout<<arr[top]<<" element is removed "<<endl;
				top--;
			}
		}
		void display()
		{
			cout<<"Elements in the stack are "<<endl;
			if(top>-1)
			{
				for(int i=top;i>=0;i--)
				{
					cout<<arr[i]<<endl;;
				}
			}
			else
			{
				cout<<"Stack is empty "<<endl;
			}
		}
};

int main()
{
	int n;
	cout<<"Enter the limit of stack "<<endl;
	cin>>n;
	stack <int> s(n);
	int ch;
	int choice,x;
	do
	{
	cout<<"Enter your choice among following . Enter 0 for exit "<<endl;
	cout<<"1. Insert an element "<<endl;
	cout<<"2. Pop an element "<<endl;
	cout<<"3. Display the stack "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter the value to be inserted "<<endl;
			cin>>x;
			s.push(x);
			break;
		case 2:
			s.pop();
			cout<<endl;
			break;
		case 3:
			s.display();
			cout<<endl;
			break;
		default:
			cout<<"Wrong choice entered "<<endl;
			cout<<"Enter the number once again "<<endl;
	}
	}
	while(choice!=0);
	getch();
	return 0;
}
