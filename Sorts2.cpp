#include <iostream>
using namespace std;

int Partition(int arr[], int s, int e)
{
	int pivot = arr[e];
	int pIndex =s;
	
	for(int i=s;i<e;i++)
	{
		if(arr[i]<pivot)
		{
			int temp = arr[i];
			arr[i]=arr[pIndex];
			arr[pIndex]=temp;
			pIndex++;
		}
	}
	int tmp = arr[e];
	arr[e] = arr[pIndex];
	arr[pIndex]=tmp;
	
	return pIndex;
}


void QuickSort(int arr[] , int s,int e)
{
	if(s<e)
	{
		int p = Partition(arr,s,e);
		QuickSort(arr,s,(p-1));
		QuickSort(arr,(p+1),e);
	}
		
		
}


void merge(int b[],int l, int m, int r)
{
	int i=l;  // starting index for left subarray
	int j=m+1;  // starting index for right subarray
	int k=l;    //starting index for temporary
	
	int temp[5];
	while(i<=m && j<=r)
	{
		if (b[i]<=b[j])
		{
			temp[k]=b[i];
			i++;
			k++;
		}
		else
		{
		    temp[k]=b[j];
			j++;
			k++;
		}
	}
	while(i<=m)
	{
		temp[k]=b[i];  // copying all elements from left subarray to temp as it is
		i++;
		k++;
	}
	while(j<=r)
	{
		temp[k]=b[j];   // copying all elements from right subarray to temp as it is
		j++;
		k++;
	}
	for(int s=l;s<=r;s++)
	{
		b[s]=temp[s];
	}
	
}


void mergeSort(int array[],int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		mergeSort(array,l,m);
		mergeSort(array,m+1,r);
		merge(array,l,m,r);
	}
}

int main()
{
	int size=0;
	cout<<"\t\t\tQUICK SORT"<<endl;
	cout<<"Enter Size of array :"<<endl;
	cin>>size;
	int myarray[size];
	
	cout<<"Enter "<<size<< " integers in any order : "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>myarray[i];
	}
	cout<<"Before Sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarray[i]<<" ";
	}
	cout<<endl;
	QuickSort(myarray,0,(size-1));
	
	cout<<"After Sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarray[i]<<" ";
	} 
	
	cout<<"\n\t\tMERGE SORT\n\n"<<endl;

	int myarr[5];
	
	cout<<"Enter 5 integers in any order : "<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>myarr[i];
	}
	cout<<"Before Sorting"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	
	mergeSort(myarr,0,4);
	
	
	cout<<endl<<"After Sorting"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<myarr[i]<<" ";
	} 
	
	return 0;
}
