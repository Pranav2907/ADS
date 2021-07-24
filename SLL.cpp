#include<iostream>
#include<string>
using namespace std;

class node 
{
	public:
		int key;
		string data;
		node *next;
	    
	    node()
	    {
	    	key=0;
	    	data='\0';
	    	next=NULL;
		}
		node(int k,string d)
		{
			key = k;
			data = d;
			next=NULL;
		}		
};
 
class singlyLinkedList
{
	public:
		node*head;
		
		singlyLinkedList()
		{
			head=NULL;
		}
		singlyLinkedList(node *n)
		{
			head = n;
		}
		
		bool isEmpty()
		{
			if(head==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		// 1) Check if node exists using key value
		node *nodeExists( int k)
		{
			node *temp = NULL;
			node *ptr = head;
			while(ptr!=NULL)
			{
				if(ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		
		// 2) Insert a Node After particular node in the list
		void insertNodeAfter(int k , node *n)
		{
			node *ptr = nodeExists(k);
			if (ptr==NULL)
			{
				cout<<"No node exists with key value: "<<k<<endl;
			}
			if (nodeExists(n->key)!=NULL)
			{
				cout<<"Node exists with key value:"<<n->key<<"Use different key value to insert the node"<<endl;
			}
			else
			{
				n->next=ptr->next;
				ptr->next=n;
				cout<<"Node Inserted"<<endl;
			}
		}
		
		//3) Delete a Node by Unique key
		void deleteNodeByKey(int k)
		{
			if(head == NULL)
			{
				cout<<"Singly linked list already empty, can't delete'"<<endl;
			}
			else if(head!=NULL)
			{
				if(head->key ==k )
				{
					head = head->next;
				    cout<<"Node UNLINKED with keys value :"<<k<<endl;
				}
				else
				{
					node *temp = NULL;
					node *prevprt = head;
					node *currentptr = head->next;
					while (currentptr!=NULL)
					{
						if(currentptr->key == k)
						{
							temp = currentptr;
							currentptr=NULL;
						}
						else
						{
							prevprt=prevprt->next;
							currentptr = currentptr->next;
						}
					}
					if(temp!=NULL)
					{
						temp->next=prevprt->next;
						cout<<"Nodes UNLINKED with keys value:"<<k<<endl;
					}
					else
					{
						cout<<"Node doesn't exists with key value:"<<k<<endl;
					}
				}
			}
			
		}
		
		// 5)Displaying the Linked List
		void display()
		{
			if(head==NULL)
			{
				cout<<"The Linked List is empty"<<endl;
			}
			else
			{
				cout<<endl<<" Linked List Values :";
				node*temp = head;
				while(temp!=NULL)
				{
					cout<<"("<<temp->key<<","<<temp->data<<") --> ";
					temp = temp->next;
				}
			}
		}
		
		// 6) Append a Node
		void appendNode(node *n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node already exists"<<endl;
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					cout<<"Node Appended"<<endl;
				}
				else
				{
					node* ptr = head;
					while(ptr->next!=NULL)
					{
						ptr = ptr->next;
					}
					ptr->next=n;
					cout<<"Node Appended"<<endl;
				}
			}
		}
		
		//7) prepend a node
            void prependNode(node * n) 
			{
                if (nodeExists(n -> key) != NULL) 
				{
                    cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
                } 
				else 
				{
                    n -> next = head;
                    head = n;
                    cout << "Node Prepended" << endl;
               }
            }
            
            // deletefrombegining
            void deleteFromStart()
            {
            	
				node* temp=head;
				if(isEmpty())
            	{
            		cout<<"Cannot be DELETED , List is Empty"<<endl;
				}
				else 
				{
					
					if(temp->next==NULL)
					{
					    head=NULL;
					    cout<<"Element Deleted from Start"<<endl;
					}
					else
					{
						head=temp->next;
						cout<<"Element Deleted from Start"<<endl;	
					}
				
				}
				
			}
			
			//deleteFromEnd
			void deleteFromEnd()
			{
				node* temp1=head;
				
				if(isEmpty())
            	{
            		cout<<"Cannot be DELETED , List is Empty"<<endl;
				}
				else 
				{
					
					if(temp1->next==NULL)
					{
					    head=NULL;
					    cout<<"Element Deleted from End"<<endl;
					}
					else
					{
						node*temp2=temp1;
						while(temp1->next!=NULL)
						{
							
							temp1=temp1->next;
						}
						temp2=NULL;
						cout<<"Element Deleted From End"<<endl;
					}
			    }
			}
		
		
		
};
int main()
{
	singlyLinkedList s;
	int option,key1,k1;
	string data1;
	do
	{
		cout<<"Enter the number to do following operation . Press 0 to exit"<<endl;
		cout<< "1. Entry of patient who has Serious Condition"<<endl;
		cout<<" 2. Entry of patient who  has Medium Condition"<<endl;
		cout<<" 3. Entry of patient who has General Condition"<<endl;
		cout<< "4. Delete the entry of patient who has Serious Condition"<<endl;
		cout<<" 5. Delete the entry of patient who  has Medium Condition"<<endl;
		cout<<" 6. Delete the entry of patient who has General Condition"<<endl;
		cout<<" 7.Display The List of Patient"<<endl;
		cout<<" 8.Clearscreen"<<endl;
		cin>>option;
		
		node *n1 = new node();
		
		switch(option)
		{
			case 0:
				break;
			case 1:
			    cout<<"Entry of patient who has Serious Condition , \nEnter key and Name of the person in the node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
			case 2:
			    cout<<"Entry of patient who  has Medium Condition \nEnter the key after which the node should be inserted"<<endl;
				cin>>k1;
				cout<<"Enter the key & name  of the patient in new node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.insertNodeAfter(k1,n1);
				break;
			case 3:
			    cout<<"Entry of patient who has General Condition, \nEnter key and name of the person in node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				break;
			case 4:
			    cout<<"Delete the entry of patient who has Serious Condition"<<endl;
				s.deleteFromStart();
				break;
			case 5:
			    cout<<"Delete the entry of patient who  has Medium Condition \nEnter the key of the node to be deleted"<<endl;
				cin>>k1;
				s.deleteNodeByKey(k1);
				break;
			case 6:
			    cout<<"Delete the entry of patient who has General Condition"<<endl;
				s.deleteFromEnd();
				break;
			case 7:
				cout<<"Displaying The List"<<endl;
				s.display();
				break;
			case 8:
				system("cls");
				break;
			default :
			    cout<<"Enter Proper Option Number";			
			     						
		}
		
	}while(option!=0);
	
	return 0;
}

