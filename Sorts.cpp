#include <iostream>
using namespace std;

void bubbleSort(int a[])
{
	for(int i=0; i<5; i++ )
	{
		for(int j=0; j<(5-i-1); j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		cout<<"\nAfter "<<i+1<<" Pass"<<endl;
		for(int k=0;k<5;k++)
		{
			cout<<a[k]<<" ";
		}
	}
}

void selectionSort(int arr[])
{
	for(int i=0;i<4;i++)
	{
		int max = i;
		
		for(int j=i+1;j<5;j++)
		{
			if(arr[j] > arr[max])
			{
				max = j;
			}
			if(max != i)
			{
				int tmp = arr[max];
				arr[max]=arr[i];
				arr[i]=tmp;
			}
		}
		cout<<"\nAfter "<<i+1<<" Pass"<<endl;
		for(int k=0;k<5;k++)
		{
			cout<<arr[k]<<" ";
		}
	}
}

void insertionSort(int array[])
{
	int j=0;
	int key = 0;
	
	
	for(int i=1;i<5;i++)
	{
		key=array[i];
		j= i-1;
		while(j>=0 && array[j] < key)
		{
			array[j+1] = array[j];
			j= j-1;
		}
		array[j+1] = key;
		
	
		
	}
	cout<<"After Sorting"<<endl;
	for(int k=0;k<5;k++)
		{
			cout<<array[k]<<" ";
		}
		
	
}

int binarysearch(int b[], int left, int right,int x)
{
	while(left<=right)
	{
		int mid = left + (right-left)/2;
		if(b[mid]== x)
		{
			return mid;
		}
		else if(b[mid]<x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid-1;
		}
	}
	return -1;
}

int main()
{
	int myarray[5] , i;
	cout<<"Enter 5 integers in any order: "<<endl;
	for(i=0;i<5;i++)
	{
		cin>>myarray[i];
	}
	
	cout<<"Before Sorting"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<myarray[i]<<" ";
	}
	
	cout<<"BUBBLE SORT"<<endl;
	bubbleSort(myarray);
	
	cout<<"\n\n\nBINARY SEARCH"<<endl;
	int num;
	int output;
	cout<<"Enter one number that you want to search in the Array: "<<endl;
	cin>>num;
	
	output=binarysearch(myarray,0,4,num);
	
	if(output==-1)
	{
		cout<<"No Match Found"<<endl;
	}
	else
	{
		cout<<"Match found at index Position : "<<output<<endl;
	}
	
	cout<<"\n\n\n\nSELECTION SORT"<<endl;
	selectionSort(myarray);
	
	cout<<"\n\n\nINSERTION SORT"<<endl;
	insertionSort(myarray);
	
	
	return 0;
}
