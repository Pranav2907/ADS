#include<iostream>
using namespace std ;
const int city = 2;
const int week = 7;
int main()
{
	int temp[city][week];
	cout<<"Enter the temperature of Pune and Mumbai city :\n";
		for (int i=0;i<city;i++)
		{
			if (i==0)
			{
				cout<<"\t\t\tPUNE CITY\t\t\t\n";
			}
			else
			{
				cout<<"\t\t\tMUMBAI CITY\t\t\t\n";
			}
			for(int j=0;j<week;j++)
			{
				cout<<"Day "<<j+1<<" :";
				cin>>temp[i][j];
			}
		}
	cout<<"Displaying the values of the temperatures in respective cities\n";
	   for (int i=0;i<city;i++)
	   {
	   	   if (i==0)
	   	   {
	   	   	  cout<<"\t\t\tPUNE CITY\n";
			  }
			else
			{
				cout<<"\t\t\tMUMBAI CITY\n";
			  }  
	   	   for(int j=0;j<week;j++)
	   	   {
	   	   	cout<<"Day "<<j+1<<" :"<<temp[i][j]<<endl;
			  }
	   	   	  
	   }
	   	
}
