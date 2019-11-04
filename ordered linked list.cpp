#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
class oll
{
	node *head;
	public:
		oll()
		{
			head=NULL;
		}
		void insert(int val)
		{
			node *p=new node;
			p->data=val;
			p->next=NULL;
			if(head==NULL)
			{
				head=p;
				cout<<"Node inserted "<<endl;
			}
			else if(head->next==NULL)
			{
				if(head->data<p->data)
				{
					head->next=p;
					cout<<"Node Inserted "<<endl;
				}
			}
			else
			{
				node *temp=head;
				node *nex=head->next;
				while(nex!=NULL)
				{
					if(temp->data<p->data)
					{
						if(nex->data>p->data)
						{
							p->next=nex;
							temp->next=p;
							cout<<"Node Inserted "<<endl;
						}
						else if(nex->next==NULL)
						{
							nex->next=p;
							p->next=NULL;
							cout<<"Node Inserted "<<endl;
						}
					}
					else if(p->data<temp->data)
					{
						p->next=head;
						head=p;
						cout<<"Node Inserted "<<endl;
						return ;
					}
					temp=temp->next;
					nex=nex->next;
				}
			}
		}
		
		oll merge(oll p1,oll p2)
		{
			oll p3;
			node *head3=p3.head;
			node *head1=p1.head;
			node *head2=p2.head;
			if(head1==NULL)
				return p2;
			if(head2==NULL)
				return p1;
			if(head1->data<=head2->data)
			{
				head3->data=head1->data;
				head1=head1->next;
				head3->next=merge(p1,p2);
			}
			else
			{
				head3->data=head2->data;
				head2=head2->next;
				head3->next=merge(p1,p2);
			}
			return p3;
		}
		
		void delatend()
		{
			node *prev=head;
			node *temp=head->next;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				prev=prev->next;
			}
			prev->next=NULL;
			delete temp;
			cout<<"Node deleted at the end "<<endl;
		}
		
		void delatbeg()
		{
			head=head->next;
			cout<<"Node deleted in the beginning "<<endl;
		}
		
		void display()
		{
			if(head==NULL)
				cout<<"Ordered linked list is empty "<<endl;
			else
			{
				node *temp=head;
				cout<<"Elements of ordered linked list are "<<endl<<"[ ";
				while(temp!=NULL)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<"]"<<endl;
			}
		}
};


int main()
{
	oll o,o1,o2;
	int n,a;
	do
	{
		cout<<"Enter your choice amoong following Press 0 for exit "<<endl;
		cout<<"1. Insertion "<<endl;
		cout<<"2. Deletion at beginning "<<endl;
		cout<<"3. Deletion at the end "<<endl;
		cout<<"4. Insertion a new linked list for merging "<<endl;
		cout<<"4. Merging two linked list "<<endl;
		cout<<"5. Display "<<endl;
		cin>>n;
		switch(n)
		{
			case 1:
				cout<<"Enter the value to be inserted "<<endl;
				cin>>a;
				o.insert(a);
				break;
			case 2:
				o.delatbeg();
				break;
			case 3:
				o.delatend();
				break;
			case 4:
				cout<<"Enter the value to be inserted "<<endl;
				cin>>a;
				o1.insert(a);
			case 5:
				o2=o2.merge(o,o1);
				o2.display();
			case 6:
				o.display();
				break;	
		}
	}while(n!=0);
	getch();
	return 0;
}
