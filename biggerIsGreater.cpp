/* This code is for question in HackerRank,The question name is Bigger The Greater*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
void swap(int arr[], int a, int b);
int main()
{

	int t;
	cin>>t;
	char st[100];
	int arr[100];
	for(int i =0 ; i<t ;i++)
	{
		int l;
		int flag=0;
		cin>>st;
		int len = strlen(st);
		for(int j = 0 ; j<len;j++)
			arr[j]=(int)((int)(st[j])-(int)('a'));
		for( l=len-1; l>0;l--)
		{
			if(arr[l-1]<arr[l])
				break;
		}

		if(l==0)
				cout<<"no answer"<<endl;
		else{
			int shorti=l,shortn=arr[l-1];
			for(int j= l+1;j<len;j++)
				{
					if(arr[j]<arr[shorti] && arr[j] > shortn) shorti=j;
				}
				swap(arr,shorti,l-1);
				//	cout<<*arr<<endl;
				sort(arr+l,arr+len);
				for(int i =0;i<len;i++)
					cout<<char(arr[i]+int('a'));
					cout<<endl;
		}


	}
	return 0;
}
void swap(int arr[100],int a, int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]= temp;
}
