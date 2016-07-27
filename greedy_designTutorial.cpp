#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0 ;i<n;i++)
		arr[i]=0;
	
	arr[1]=1;
	for (int i=2;i*i<=n;i++)
		{
	//	cout<<i;
		if(!arr[i])
		for(int j=2;j*i<n;j++)
			arr[j*i]=1;
				
		}
	int flag=0;
	for(int j=4; j< n;j++)
	{
		//cout<<arr[j];
		if(arr[j] and arr[n-j])
				{
					flag=j;
					break;
				}
	} 
	cout<<flag<<" " << n-flag;
	return 0;
}
