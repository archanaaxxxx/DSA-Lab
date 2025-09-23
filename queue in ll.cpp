#include<iostream>
#include<cstdlib>
using namespace std;
struct lnode{
	int data;
	struct lnode * next;
};
typedef struct lnode node;

node*f=NULL;
node*r=NULL;

bool isEmpty()
{
	if (f==NULL && r==NULL)
	return 1;
	else
	return 0;
}
void enqueue(int val)
{
	node * newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		cout<<"Out of memory\n";
	}
	newnode->data=val;
	if(isEmpty())
	{
		f=r=newnode;
		newnode->next=NULL;
	}
	else
	{
		r->next=newnode;
		r=newnode;
		newnode->next=NULL;
	}
	cout<<val<<" is pushed\n";
}

void dequeue()
{
	if (isEmpty())
	{
		cout<<"Empty\n";
	}
	node*temp=f;
	cout<<f->data<<" is deleted\n";
	
	if(f==r)
	{
		f=r=NULL;
	}
	else
	{
		f=f->next;
	}
	free(temp);
}

void peek()
{
	if (isEmpty())
	{
		cout<<"Empty\n";
	}
	else
	{
		cout<<"Top element: "<<f->data<<endl;
	}
}

void disp()
{
	if(isEmpty())
	{
		cout<<"Empty...\n";
	}
	cout<<"List:";
	node*temp=f;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	disp();
	dequeue();
	disp();
	peek();	
}
