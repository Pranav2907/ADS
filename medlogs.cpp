#include <iostream>
#include<cstring>
using namespace std;
void search();
class medicine
{
	public:
		int med_id;
		char med_name[20];
		int price;
		int stock;
		public:
			void input();
			void output();
}m[5];

void input()
{
	int i;
	for(i=0;i<5;i++)
	{
		cout<<"med_id : ";
		cin>>m[i].med_id;
		cout<<"med_name : ";
		cin>>m[i].med_name;
		cout<<"Price : ";
		cin>>m[i].price;
		cout<<"Stock : ";
		cin>>m[i].stock;
		cout<<"\n\n";
	}
}

void output()
{
	int i;
	cout<<"\t\t\t\t\t\t\tMEDICINE LOGS\n\n";
	for(i=0;i<5;i++)
	{
		cout<<"ID : "<<m[i].med_id<<"\n";
		cout<<"NAME : "<<m[i].med_name<<"\n";
		cout<<"PRICE : "<<m[i].price<< " /-"<<"\n";
		cout<<"STOCK : "<<m[i].stock<<"\n";
		cout<<"\n";
	}
}

void search()
{
    char med[100];
	int res;
	int i;
	cout<< " \nEnter the medicine to be found : ";
	cin>>med;
		for(i=0;i<5;i++)
	{
		res=strcmp(m[i].med_name,med);
		if (res==0)
		break;	
	}
	if (res == 0)
	cout<<"\nThe medicine is found";
	else
	cout<<"\nThe medicine is not found";
}

int main()
{
	int i;
	input();
	output();
	search();
}
