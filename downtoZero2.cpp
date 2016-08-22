/* This code is for question in HackerRank,The question name is Left Rotation*/

#include <iostream>
#include <cmath>

int SIZE= 1000000+1;
int primeArr[SIZE];
using namespace std;
void calculatePrime();
int isPrime(int n);
int getMax(long int n);
void calculatePrime()
        {
        primeArr[0]=1;
        primeArr[1]=1;
        for (int i=2;i*i<=SIZE;i++)
                {
        //      cout<<i;
                        if(!primeArr[i])
                        for(int j=2;j*i<SIZE;j++)
                        primeArr[j*i]=1;

                }
}

int isPrime(int n){
retrun primeArr[n];
}

int getMax(long int i)
{
	int n,k;
	for(int  j =2;j*j<=i;j++)
	{
		if(i/j==0)
		{
		n=j;
		k=i/j;
		}
	}
	n=(j>k)?j:k
	return n 	
}

int main()
{
	for(int i = 0 ; i < SIZE;i++)
		primeArr[i]=0;
	calculatePrime();
	cout<<primeArr[19];
	long int foobar[SIZE];
	foobar[0]=0;
	for(int i =1; i< SIZE;i++)
	{
		if(isPrime(i))
			foobar[i]=foobar[i-1]+1;
		else
		{
			int c=getMax(i);
			foobar[i]=foobar[c]+1;
		}
	}
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

