//https://www.hackerrank.com/challenges/array-left-rotation
#include <iostream>
#include <cmath>
int SIZE= 1000000+1;
//int SIZE= 10;
int primeArr[1000001];
int primeArr2[1000001];
using namespace std;
void calculatePrime();
int isPrime(int n);
int main()
{
	int foobar[SIZE];
	for(int i = 0 ; i < SIZE;i++)
	{	primeArr[i]=1;
		primeArr2[i]=1;
		foobar[i]=0;
	}
	calculatePrime();
	foobar[0]=0;
	for(int i =1; i<SIZE;i++)
	{
	 	int x= primeArr[i];
		int y= primeArr2[i];
		x=min(x,y);
//		cout<<x<<"testinig"<<i<<endl;
		if(x==1)
		foobar[i]=foobar[i-1];
		else
			foobar[i]=min(min(foobar[max(x,i/x)],foobar[max(y,i/y)]),foobar[i-1]);
		foobar[i]=foobar[i]+1;
	}
	cout<<primeArr[556]<<" "<<primeArr2[556];
	// for(int i =0; i<10;i++)
	// cout<<foobar[i]<<" "<<i<<endl;
	int q;
	cin>>q;
	for(int i = 0; i< q;i++)
	{
		int n;
		cin>>n;
		cout<<foobar[n]<<endl;
	}

	return 0;
}
void calculatePrime(){
	primeArr[0]=0;
	primeArr2[0]=0;
	for (int i=2;i*i<=SIZE;i++){
  	for(int j=2;j*i<SIZE;j++){
			primeArr[j*i]=i;
			if(primeArr2[i]==1)
				primeArr2[j*i]=i;
		}
	}
}

int isPrime(int n){
//cout<<n<<"testiiii"<<primeArr[n]<<endl;
return primeArr[n];
}
