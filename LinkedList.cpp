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
		
		// 4)Update Node by Key
		void updateNodeByKey(int k , int d)
		{
			node*ptr = nodeExists(k);
			if(ptr!=NULL)
			{
				ptr->data=d;
				cout<<"The Node has been UPDATED"<<endl;
			}
			else
			{
				cout<<"Node with keys value doen't exists"<<endl;
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
		
};

int main()
{
	singlyLinkedList s;
	int option;
	int key1,k1,data1;
	do
	{
		cout<<"\nWhat operation do you want to perform ? . Select the number of the option , press 0 to exit."<<endl;
		cout<<" 1. AppendNode()"<<endl;
		cout<<" 2. insertNodeAfter()"<<endl;
		cout<<" 3. deleteNodeByKey()"<<endl;
		cout<<" 4. updateNodeByKey()"<<endl;
		cout<<" 5. Display()"<<endl;
		cout<<" 6. ClearScreen()"<<endl;
		cout<<" 7. PrependNode()"<<endl;
		
		cin>>option;
		node *n1 = new node();
		
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Append Node operation , \nEnter key and data of the node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				break;
			case 2:
			    cout<<"Insert Node After Operation \nEnter the key after which the node should be inserted"<<endl;
				cin>>k1;
				cout<<"Enter the key & data of the new node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.insertNodeAfter(k1,n1);
				break;
			case 3 :
			    cout<<"Delete Node by Key Operation \nEnter the key of the node to be deleted"<<endl;
				cin>>k1;
				s.deleteNodeByKey(k1);
				break;
			case 4 :
			    cout<<"Update Node By Key Operation \nEnter key & new data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				s.updateNodeByKey(key1,data1);
				break;
			case 5:
			    s.display();
			    break;
			case 6:
				system("cls");
				break;
			case 7:
			   cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
               cin >> key1;
               cin >> data1;
               n1 -> key = key1;
               n1 -> data = data1;
               s.prependNode(n1);
               break;
			default :
			    cout<<"Enter Proper Option Number";	
			    					
				
			    	
		}
		
	}while(option!=0);
	return 0;
}
