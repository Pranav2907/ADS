#include<iostream>
using namespace std;

class node
{
	public:
		int key;
		int data;
		node *next;
		
		node(){
			key =0;
			data=0;
			next=NULL;
		}
		
		node(int k,int d){
			key=k;
			data=d;
		}
};

class stack
{
	public:
		node *top;
		
		stack(){
			top = NULL;
		}
		
		//1) isempty
		bool isEmpty()
		{
			if(top==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		//2) checkIfNodeExists
		bool checkIfNodeExists(node* n)
		{
			node *temp=top;
			bool exists = false;
			while (temp!=NULL)
			{
				if(temp->key==n->key)
				{
					exists = true;
					break;
				}
				else
				{
					temp=temp->next;
				}
			}
			return exists;
		}
		//3) push()
		void push(node *n)
		{
			if(top==NULL)
			{
				top=n;
			}
			else if(checkIfNodeExists(n))
			{
				cout<<"Node already exists  \n Enter different key value"<<endl;
			}
			else
			{
				node *temp = top;
				top = n;
				n->next=temp;
				cout<<"Node is Pushed"<<endl;
			}
		}
		
		//4) pop()
		node *pop()
		{
			node *temp = NULL;
			if(isEmpty())
			{
				cout<<"Stack is Underflow"<<endl;
				return temp;
			}
			else
			{
				temp = top;
				top=top->next;
				return temp;
			}
		}
		
		//5) peek()
		node *peek()
		{
			if(isEmpty())
			{
				cout<<"Stack is underflow"<<endl;
				return NULL;
			}
			else
			{
				return top;
			}
		}
		
		//6) count()
		int count()
		{
			int count = 0;
			node *temp=top;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}
		
		//display()
		void display()
		{
			cout<<"All the values in stack are :"<<endl;
			node *temp = top;
			while(temp!=NULL)
			{
				cout<<"("<<temp->key<<","<<temp->data<<")"<<" -->";
				
				temp = temp->next;
			}
			cout<<"Total number of Nodes in Stacks"<<count()
			<<endl;
			cout<<endl;
		}
};

int main()
{
	stack s1;
	int option,key,data;
	
	do
	{
		cout<<"What operation do you want to perform.  \n Select the number from options. Press 0 to exit"<<endl;
		cout<<" 1. push() "<<endl;
		cout<<" 2. pop() "<<endl;
		cout<<" 3. isEmpty() "<<endl;
		cout<<" 4. peek() "<<endl;
		cout<<" 5. count "<<endl;
		cout<<" 6. display() "<<endl;
		cout<<" 7. clear screen"<<endl;
		cin>>option;
		
		node *new_node = new node();
		
		switch(option)
		{
			case 0:
				break;
			case 1:
			    cout<<"Enter the Key and Data of new node to be pushed"<<endl;
				cin>>key;
				cin>>data;
				new_node->key=key;
				new_node->data=data;
				s1.push(new_node);
				break;
			case 2:
			    cout << "Pop Function Called - Poped Value: " << endl;
                new_node = s1.pop();
                cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")";
                delete new_node;
                cout << endl;
                break;
            case 3:
                if (s1.isEmpty())
                cout << "Stack is Empty" << endl;
                else
                cout << "Stack is not Empty" << endl;
                break;
            case 4:
                if (s1.isEmpty()) {
                cout << "Stack is Empty" << endl;
                } else {
                cout << "PEEK Function Called : " << endl;
                new_node = s1.peek();
                cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")" <<endl;
                cout<< endl;
                }
                break;
            case 5:
                cout << "Count Function Called: " << endl;
                cout << "Number of nodes in the Stack: " << s1.count() << endl;
                break;
 
            case 6:
                cout << "Display Function Called - " << endl;
                s1.display();
                cout << endl;
                break;
            case 7:
            system("cls");
            break;
            default:
            cout << "Enter Proper Option number " << endl;
        }
 
    } while (option != 0);		
		
	
	return 0;
}
