#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class sq
{ 	
	int *ar,m,front,rear,ch;
	bool isEmpty()
	{
		return ((front==-1)&&(rear==-1));
	}
	bool isFull()
	{
		return(((rear+1)%m)==front);
	}
	public:
		sq()
		{
			front =-1;
			rear=-1;
			ch=0;
			m=0;
		}
		void input()
		{
			cout<<"Enter size of queue\n";
			cin>>m;
			ar=new int[m];
			
		} 
		void menu()
		{
			input();
			while(true)
			{
			cout<<"MENU\n1.EnQueue\n2.DeQueue\n3.Display\n4.EXIT!!!\n";
			cin>>ch;
			switch(ch)
			{
			case 1:
				enq();
				break;
			case 2:
				deq();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nWrong Choice\n";
				break;
			}
			}
		}
		void enq()
		{
			int data=0;
			if(isFull())
			{
			cout<<"\nOverflow\n";
			}
			else
			{
			cout<<"Enter Data ";
			cin>>data;
			rear=((rear+1)%m);
			ar[rear]=data;
			if(front==-1){
			front=((front+1)%m);
			}
			}
			
		}
		void deq()
		{
			int data=0;
			if(isEmpty())
			{
			cout<<"\nUnderFlow\n";
			cout<<front<<rear;
			}
			else if(front==rear)
			{
			data=ar[front];
			front=((front+1)%m);
			cout<<"\nDELETED DATA IS-->"<<data<<endl;
			front=-1;
			rear=-1;
			}
			else
			{
			data=ar[front];
			front=((front+1)%m);
			cout<<"\nDELETED DATA IS-->"<<data<<endl;
			}
			
			
		}
		void display()
		{
			cout<<"\nQUEUE is--\n";
			int f=front;
			do
			{
			cout<<ar[f]<<" ";
			f=(f+1)%m;
			}
			while (f!=(rear+1)%m);
			getch();
		} 
	};
	int main()
	{
		sq obj;
		obj.menu();
		getch();
	}
