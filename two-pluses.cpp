#include <iostream>
using namespace std;

int arr[15][15];

int checkplus(int i, int c, int cj);
void transfer(char charArr[][15] , int m , int n);


void transfer(char charArr[][15], int n , int m)
{
	for(int i = 0;i<n;i++)
	{
	for(int j=0;j<m;j++)
	{
		if(charArr[i][j]=='G')
				arr[i][j]=1;
				}
	}
	}


int checkplus(int n, int ci , int cj)
{
	for( int j =0  ; j < n;j++)
		{
		if(!arr[cj+n/2][ci+j] or !arr[cj+j][ci+n/2])
		return 0;
		}
return n+n-1;
}
int main ()
{
	for ( int  i = 0 ; i < 15;i++)
		for ( int j= 0 ; j< 15; j++)
		arr[i][j] = 0;
	int n, m;
	cin>>n>>m;
	char chararr[15][15];
	for(int i = 0 ; i< n ;i++)
		for (int j =0; j< m ; j++)
			cin>>chararr[i][j];
	transfer(chararr, n, m);
	for(int i =0 ; i < n;i++)
	{
		for ( int j = 0 ; j < m; j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	int val= 0;
	for( int i = 0 ; i<=n-3 ; i++)
		for( int j = 0 ; j <=n-3; j++)
		{
			cout<<i<< " " <<j << " " << checkplus(3,i,j) <<endl;
			if(checkplus(3,i,j) )
				val = val + checkplus(3,i,j);
		}
	cout<<val;
	return 0;
}

