#include<iostream>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

bool isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='*' || c=='/')
	{
		return 2;
	}
	else if(c=='+' || c=='-')
	{
		return 1;
	}
	else 
	{
		return -1;
	}
}



string InfixToPrefix(stack <char> s , string infix)
{
	string prefix;
	reverse(infix.begin(),infix.end());
	for(int i=0;i<infix.length();i++)
	{
		if(infix[i]=='(')
		{
			infix[i]=')';
		}
		else if(infix[i]==')')
		{
			infix[i]='(';
		}
	}
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{
			prefix+=infix[i];
		}
		else if (infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp = s.top();
				prefix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if (isOperator(infix[i]))
		{
			if (s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i]) > precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else if(precedence(infix[i]) == precedence(s.top()) && infix[i] == '^')
				{
					while(precedence(infix[i])==precedence(s.top()))
					{
						prefix+=infix[i];
						s.pop();
					}
					s.push(infix[i]);
				}
				else if(precedence(infix[i]) == precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty()) && (precedence(infix[i])<precedence(s.top())))
					{
						prefix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	
	while(!s.empty())
	{
		prefix+=s.top();
		s.pop();
	}
	reverse(prefix.begin(),prefix.end());
	
	return prefix;
}

string InfixToPostfix(stack <char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((s.top()!= '(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			
		}
		else if(isOperator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i]) > precedence(s.top()))
				{
					s.push(infix[i]);
				}
			    else if(precedence(infix[i]) == precedence(s.top()) && infix[i] == '^')
			    {
			    	s.push(infix[i]);
				}
				else 
				{
					while((!s.empty()) && (precedence(infix[i])<=precedence(s.top())))
					{
						char temp=s.top();
						postfix+=temp;
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}
int top=-1;
int stk[20];

void push(int x)
{
    top++;
    stk[top]=x;
}

 int pop(int y)
 {
     int x;
     x=stk[y];
     top--;
     return x;
 }



int main()
{
	string infix,prefix,postfix;
	stack <char> s;
	char input [100];
	cout<<"Enter a Infix Expression :";
	cin>>infix;
	stack <char> stack;
	cout<<"INFIX EXPRESSION : "<<infix<<endl;
	
	prefix=InfixToPrefix(stack,infix);
	cout<<"PREFIX EXPRESSION : "<<prefix;
	
	postfix=InfixToPostfix(stack,infix);
	cout<<endl<<"POSTFIX EXPRESSION : "<<postfix<<endl;
	
	cout<<"Enter a POSTFIX Expression to evaluate :";
	cin>>input;
	char *p;
	p=input;
	int temp;
	
	
	
	
	 while(*p!='\0')
    {

        if(isalnum(*p))
            push(*p-48);

        else if(*p=='+')
        {
            temp=pop(top)+pop(top);
            push(temp);
        }

         else if(*p=='-')
        {
            temp=pop(top-1)-pop(top+1);
            push(temp);
        }

         else if(*p=='*')
        {
            temp=pop(top)*pop(top);
            push(temp);
        }

         else if(*p=='/')
        {
            temp=pop(top-1)/pop(top+1);
            push(temp);
        }
          else if(*p=='^')
        {
            temp=pow(pop(top-1),pop(top));
            push(temp);
        }


        p++;
    }

    while(top!=-1)
    {
        cout<<"POSTFIX EVALUATED RESULT: "<<stk[top];
        top--;
    }
   
}
