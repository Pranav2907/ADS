#include<iostream>
using namespace std;

class node 
{
	public:
		int key;
		int data;
		node *next;
	    
	    node()
	    {
	    	key=0;
	    	data=0;
	    	next=NULL;
		}
		node(int k,int d)
		{
			key = k;
			data = d;
			next = NULL;
		}		
};

class queue
{
	public:
		node *front;
		node *rear;
		
		queue()
		{
			front=NULL;
			rear=NULL;
		}
		
		
		bool isEmpty()
		{
			if(front==NULL && rear==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}
		
		bool checkIfNodeExists(node*n)
		{
			node *temp=front;
			bool exists = false;
			while(temp!=NULL)
			{
				if(temp->key==node->key)
				{
					exists= true;
					break;
				}
				temp=temp->next;
				
			}
			return exists;
		}
		
		//1) enqueue
		void enqueue(node* n)
		{
			if(isEmpty)
			{
				front=n;
				rear=n;
				cout<<"Node ENQUEUED"<<endl;
			}
			else if(checkIfNodeExists(n))
			{
				cout<<"Node already EXISTS"<<endl;
				cout<<"Enter node with different key"<<endl;
			}
			else
			{
				rear->next=n;
				rear=n;
				cout<<"Node ENQUEUED"<<endl;
			}
		}
		
		//2) dequeue
		
		node * dequeue(node* n)
		{
			node *temp=NULL;
			if(isEmpty())
			{
				cout<<"Queue Underflow"<<endl;
				return NULL;
			}
			else
			{
				if (front==rear)
				{
					temp=front;
					front=NULL;
					rear=NULL;
					return temp;
				}
				else
				{
					temp=front;
					front=front->next;
					return temp;
				}
			}
		}
		
		//3) count
		int count()
		{
			int count=0;
			node* temp=front;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
		}
};
