#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<time.h>
using namespace std;

#define file_input myfile<<size[i]<<","<<comparison[i]<<endl;

int comparison[10];
int counter=0;
class sort
{
	int quick,compare,com;
	public:
		void Swap(int &a, int &b);
		void bubblesort(int arr[],int n);
		void selectionsort(int arr[],int n);
		void insertionsort(int arr[],int n);
		int shiftvac(int a[],int g);
		void mergesort(int a[],int l, int r);
		void mergeS(int arr[],int n);
		void merge(int b[], int beg, int mid, int end);
		void quickS(int arr[],int n);
		void quicksort(int arr[],int first,int last);
		void qsb(int a[],int b[],int l,int low,int high,int &c);
		int partition(int arr[],int pivot,int first, int last);
		int extendLargeRegion(int arr[],int pivot,int lowVac,int high);
		int extendSmallRegion(int arr[],int pivot,int low,int highVac);
};
void sort::Swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void sort::bubblesort(int arr[],int n)
{
	int count=0;
	bool flag;
		for(int j=0; j<n-1; j++)
		{
			flag=false;
			for(int k=0; k<n-j-1; k++)
			{
				count++;
				if(arr[k]>arr[k+1])
				{
					Swap(arr[k], arr[k+1]);
					flag=true;
				}
			}
			if(flag==false)
				break;
		}
		cout<<"\nThe size of the array : "<<n;
		cout<<"\nNumber of comparisons in array  : "<<count;
		cout<<"\nSorted array is :"<<endl;
		comparison[counter]=count;
		counter++;
		for(int i=0; i<n; i++)
			cout<<arr[i]<<"  ";
}
void sort::selectionsort(int arr[],int n)
{
	int count=0; 
	int min_idx;
	for(int j=0; j<n-1; j++)
	{
		min_idx=j;
		for(int k=j+1; k<n; k++)
		{
			count++;
			if(arr[k]<arr[min_idx])
				min_idx=k;
		}
		Swap(arr[j], arr[min_idx]);
	}
	cout<<"\nThe size of the array : "<<n;
	cout<<"\nNumber of comparisons in array : "<<count;
	comparison[counter]=count;
	counter++;
	cout<<"\nSorted array is :"<<endl;
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"  ";
}
void sort :: insertionsort(int arr[], int n)
{
	int xloc;int c=0;
	compare=0;
	for(int i=0;i<n;i++)
	{
		int curr=arr[i];
		xloc=shiftvac(arr,i);
		arr[xloc]=curr;
	}
	cout<<"\nThe size of the array : "<<n;
	cout<<"\nNumber of comparisons in array : "<<compare;
	comparison[counter]=compare;
	counter++;
	cout<<"\nSorted array is :"<<endl;
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"  ";
}
int sort :: shiftvac(int a[],int g)
{
	int vacant=g,xloc=0;
	int m=a[g];
	while(vacant>0)
	{
		compare++;
		if(a[vacant-1]<=m)
		{
			xloc=vacant;
			break;
		}
		a[vacant]=a[vacant-1];
		vacant--;
	}
	return xloc;
}
void sort:: quickS(int arr[],int n)
{
	quick=0;
	quicksort(arr,0,n-1);	
	cout<<"\nThe size of the array : "<<n;
	cout<<"\nNumber of comparisons in array  : "<<quick;
	comparison[counter]=quick;
		counter++;
	cout<<"\nSorted array is :"<<endl;
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"  ";
}
void sort::qsb(int a[],int b[],int l,int low,int high,int &c)
{
	if(low==high)
	{
		b[c]=a[low];
		c++;
	}
	else if(low<high)
	{
		int curr=(low+high)/2;
		b[c]=a[curr];
		c++;
		qsb(a,b,l,low,curr-1,c);
		qsb(a,b,l,curr+1,high,c);
	}
}
void sort::quicksort(int arr[], int first, int last)
{
	int pivot;
	if(first<last)
	{
		pivot=arr[first];
		int split=partition(arr,pivot,first,last);
		arr[split]=pivot;
		quicksort(arr,first-1,split-1);
		quicksort(arr,split+1,last);\
	}
}
int sort::partition(int arr[], int pivot, int first, int last)
{
	int low=first, high=last;
	while(low<high)
	{
		int highVac=extendLargeRegion(arr,pivot,low,high);
		int lowVac=extendSmallRegion(arr,pivot,low+1,highVac);
		low=lowVac;
		high=highVac;
	}
	return low;
}
int sort::extendLargeRegion(int arr[],int pivot,int lowVac, int high)
{
	int highVac=lowVac, current=high;
	while(current>lowVac)
	{
		quick++;
		if(arr[current]<pivot)
		{
			arr[lowVac]=arr[current];
			highVac=current;
			break;
		}
		current--;
	}
	return highVac;
}
int sort::extendSmallRegion(int arr[],int pivot,int low, int highVac)
{
	int lowVac=highVac, current=low;
	while(current<highVac)
	{
		if(arr[current]>pivot)
		{
			quick++;
			arr[highVac]=arr[current];
			lowVac=current;
			break;
		}
		current++;
	}
	return lowVac;
}
void sort:: mergeS(int arr[],int n)
{
	mergesort(arr,0,n-1);
	cout<<"\nThe size of the array : "<<n;
	cout<<"\nNumber of comparisons in array  : "<<com;
	comparison[counter]=com;
		counter++;
	cout<<"\nSorted array is :"<<endl;
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"  ";
}
void sort:: mergesort(int a[],int l,int r)
{
	com=0;
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void sort:: merge(int b[],int beg, int mid,int end)
{
	int i=beg;
	int j=mid+1,k=0;
	int tempor[end+1];
	while(i<=mid && j<=end)
	{
		if(b[i]<=b[j])
		{
			com++;
			tempor[k]=b[i];
			i++;	
		}
		else
		{
			com++;
			tempor[k]=b[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		tempor[k]=b[i];
		i++;
		k++;
	}	
	while(j<=end)
	{
		tempor[k]=b[j];
		j++;
		k++;
	}
	for(int l=beg,m=0;l<=end;l++,m++)
	{
		b[l]=tempor[m];
	}	
}
int main()
{
	ofstream myfile;
	myfile.open("graph_mks3.csv");
	
	sort s;
	int A[100];
	int size[10];
	int** S;
	srand(time(0));
	//storing size for arrays
	for(int i=0; i<10; i++)
	{
		size[i]=(int)rand()%70+30;
	}
	//creating arrays
	S=new int*[10];
	for(int i=0; i<10; i++)
	{
		S[i]=new int[size[i]];
	}
	//Entering elements in arrays
	for(int i=0; i<10; i++)
	{
		if(i==0)
		{
			for(int j=0; j<size[i]; j++)
			{
				S[i][j]=j+1;
			}
		}
		else if(i==1)
		{
			for(int j=0; j<size[i]; j++)
			{
				S[i][j]=size[i]-j;
			}
		}
		else if(i==2)
		{
			int c=0;
			for(int l=0;l<size[i];l++)
			{
				A[l]=l+1;
			}
			s.qsb(A,S[i],size[i],0,size[i]-1,c);
		}
		else
		{
			for(int j=0; j<size[i]; j++)
			{
				S[i][j]=(rand()%1001);
			}
		}
	}
	
	cout<<"\nBUBBLE SORT\n";
	myfile<<"BUBBLE SORT"<<endl;
	myfile<<"Size"<<","<<"Comparisons"<<endl;
	counter=0;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<size[i]; j++)
		{
			A[j]=S[i][j];
		}
		cout<<"\nARRAY NUMBER "<<i+1<<endl;
		s.bubblesort(A,size[i]);
		file_input;
	}
	for(int i=0; i<10; i++)
			cout<<comparison[i]<<"  ";
		
	cout<<"\nSELECTION SORT\n";
	myfile<<"SELECTION SORT"<<endl;
	myfile<<"Size"<<","<<"Comparisons"<<endl;
	counter=0;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<size[i]; j++)
		{
			A[j]=S[i][j];
		}
		cout<<"\nARRAY NUMBER "<<i+1<<endl;
		s.selectionsort(A,size[i]);
		file_input;
	}
	
	cout<<"\nINSERTION SORT\n";
	myfile<<"INSERTION SORT"<<endl;
	myfile<<"Size"<<","<<"Comparisons"<<endl;
	counter=0;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<size[i]; j++)
		{
			A[j]=S[i][j];
		}
		cout<<"\nARRAY NUMBER "<<i+1<<endl;
		s.insertionsort(A,size[i]);
		file_input;
	}
		
	cout<<"\nMERGE SORT\n";
	myfile<<"MERGE SORT"<<endl;
	myfile<<"Size"<<","<<"Comparisons"<<endl;
	counter=0;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<size[i]; j++)
		{
			A[j]=S[i][j];
		}
		cout<<"\nARRAY NUMBER "<<i+1<<endl;
		s.mergeS(A,size[i]);
		file_input;
	}
	
	cout<<"\nQUICK SORT\n";
	myfile<<"QUICK SORT"<<endl;
	myfile<<"Size"<<","<<"Comparisons"<<endl;
	counter=0;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<size[i]; j++)
		{
			A[j]=S[i][j];
		}
		cout<<"\nARRAY NUMBER "<<i+1<<endl;
		s.quickS(A,size[i]);
		cout<<"comparison: "<<comparison[i]<<" ";
		file_input;
	}	
	getch();
	myfile.close();
	return 0;
}
