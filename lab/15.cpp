#include<iostream>
using namespace std;

void quick(int a[],int n,int beg,int end,int *loc)
{   
	bool d;
	int left, right, temp;
	left=beg;
	right=end;
	*loc=beg;
	d=false;
	while(!d)
		{
			while(a[*loc]<=a[right] && *loc!=right)
				{
					right--;
				}
			if(*loc==right)
			d=true;
			else if(a[*loc]>a[right])
			{
				temp=a[*loc];
				a[*loc]=a[right];
				a[right]=temp;
				*loc=right;
			}
			if(!d)
			{
				while(a[*loc]>=a[left]&& (left!= (*loc)))
				{
					left++;
				}
				if(left == (*loc))
				d=true;
				else if(a[*loc]<a[left])
				{
					temp=a[left];
					a[left]=a[*loc];
					a[*loc]=temp;
					*loc=left;
				}
		}	}
	}
	
void quicksort(int a[],int n)
{
	int top=-1;
	int beg,end;
	int i,loc;
	int lower[10],upper[10];
	if(n>1)
	{
		top++;
		lower[top]=0;
		upper[top]=n-1;
	}
	while(top!=-1)
	{
		beg=lower[top];//0
		end=upper[top];// 11
		top--;//-1
		quick(a,n,beg,end,&loc);
	
		if(beg<(loc-1))
		{
			top++;
			lower[top]=beg;
			upper[top]=loc-1;
		}
		if((loc+1)<end)
		{
			top++;;
			lower[top]=loc+1;
			upper[top]=end;
		}
		for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
		cout<<endl;
		
	}
	cout<<endl;
	}
	
}

int main()
{
	int i,n,a[20];
	cout<<"enter size"<<endl;
	cin>>n;
	
	
	cout<<"elements"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	cout<<endl;
	
	quicksort(a,n);
	cout<<"After sort"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
		
	}
	
	return 0;
}
