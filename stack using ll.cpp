#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	node*next;
};
class Linked{
	node*top=NULL;
	public:
		int Push(int val)
		{
			node*newNode=(node*)malloc(sizeof(node));
			if(newNode==NULL){
				cout<<"stack is empty";
			}
			newNode->data=val;
			newNode->next=top;
			top=newNode;
			cout<<"Inserted at begining:"<<val<<endl;
		}
		void display()
		{
			if(top==NULL){
				cout<<"List is empty";
				return;
			}
			node*temp=top;
			cout<<"Element are in the list:";
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		void peek(){
			if(top==NULL){
				cout<<"stack empty\n";
				return;
			}
			else{
				cout<<"Top Element:"<<top->data<<endl;
			}
		}
		void pop(){
			if(top==NULL){
				cout<<"stack empty\n";
				return;
			}
			node*del=top;
			
			top=top->next;
			cout<<del->data<<" is deleted\n";
			free(del);
		}
		
};
int main()
{
	Linked a;
	a.Push(3);
	a.Push(4);
	a.Push(5);
	
	a.display();
	a.Push(6);
	a.peek();
	a.Push(7);
	a.pop();
	a.display();
}
