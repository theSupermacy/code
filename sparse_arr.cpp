//https://www.hackerrank.com/challenges/sparse-arrays


#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	int n; 
	cin>>n;
	char arr[n][20];
	char matched[20];
	for(int i = 0; i< n; i++)
		cin>>arr[i];
	int m;
	cin>>m;
	for(int i = 0; i < m;i++)
	{
		cin>>matched;
		int matchedLength = strlen(matched);
		int count = 0 ;
		for(int j = 0 ; j< n;j++)
		{
			if(!strcmp(arr[j],matched))
			{
				count++;
			//	cout<<matched<<" "<<arr[j]<<" "<<strcmp(arr[j],matched)<<endl;
			}
		}
		cout<<count<<endl;
	}
				
	return 0;
}
