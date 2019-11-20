#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
template<class X> class Node
{
	public:
	Node *next;
	X info;
	Node(X data)
	{
		next=NULL;
		info=data;
	}
};

template<class X> class Stack
{
	public:
	Node <X>*top;
	Stack()
	{
		top=NULL;
		
	}
	void insert1(X data)
	{
		Node <X>*temp=new Node<X>(data);
		if(top==NULL)
		{
			top=temp;
		}
		else
		{
			temp->next=top;
			top=temp;
			
		}
	}
	X del()
	{
		if(top==NULL)
		{
			cout<<"Stack is empty";
			return NULL;
		}
		else
		{
			
			X data=top->info;
			Node <X>*temp=top;
			top=top->next;
			delete temp;
			return data;
		}
	}
	X topElement()
	{
		if(top==NULL)
		{
			cout<<"Stack is empty";
			return  NULL;
			
		}
		else
		{
			cout<<top->info;
			
		}
	}
	void display()
	{
		Node <X>*temp=top;
		while(temp!=NULL)
		{
			cout<<temp->info;
			temp=temp->next;
			
		}
	}
	bool isEmpty()
	{
		return(top==NULL);
	}
	void menu()
		{
			X ch;
			X a;
			while(1)	
			{
			cout<<"\nMenu  \n1.Push\n2. Pop\n3. Return first Element\n4.Display\n5. EXIT";
			cout<<"\nEnter your choice: ";
			cin>>ch;
			switch(ch)
			{
				case 1: cout<<"\nEnter the data to be entered: ";
						cin>>a;
						insert1(a);
						break;
				case 2: cout<<"\nThe Deleted element is: "<<del();
						break;
				case 3: cout<<"\nThe front element is: "<<topElement();
						break;
				case 4: display();
						break;O
				case 6: exit(0);
						break;
				default: cout<<"\nWRONG CHOICE!!";
			} 
		}
	}
		
};
int main()
{
	Stack <int>obj;
	obj.menu();
	getch();
}
