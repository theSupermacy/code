/* This code is for question in HackerRank,The question name is Bigger The Greater*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	
	int t;
	cin>>t;
	char st[100];
	int arr[100];
	for(int i =0 ; i<t ;i++)
	{
		int flag=0;
		cin>>st;
		int len = strlen(st);
		for(int j = 0 ; j<len;j++)
			arr[i]=(int)(int(st[i])-int('a'));
		sort(arr,arr+len);
		for(int j =len-1; j>0; j--)
		{
			if(arr[i]!=arr[len-i])	
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<""<<endl;
		else
		{
			for(int j = len-1;j>=0;j--)
				cout<<char(int('a')+arr[i]);
			cout<<endl;
		}
	
	}
	return 0;
}
