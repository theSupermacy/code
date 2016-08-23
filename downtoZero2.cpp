/* This code is for question in HackerRank,The question name is Left Rotation*/

#include <iostream>
#include <cmath>

int SIZE= 1000000+1;
int primeArr[1000001];
using namespace std;
void calculatePrime();
int isPrime(int n);
int getMax(long int n);




int main()
{
	int foobar[SIZE];
	for(int i = 0 ; i < SIZE;i++)
	{	primeArr[i]=0;
		foobar[i]=0;
	}
	calculatePrime();
	//for(int i =0;i<100;i++)
	//cout<<primeArr[i]<<" "<<i<<endl;
//		int foobar[SIZE];
//	for(int i = 0 ; i < SIZE;i++)
  //              foobar[i]=0;
	foobar[0]=0;
	for(int i =1; i<SIZE;i++)
	{
		long int n;
//		cout<<isPrime(i)<<"testing"<<endl;
		if(!isPrime(i))
			n=foobar[i-1]+1;
		else
		{
			
			int c=getMax(i);
//			cout<<c<<"c hain bc"<<i<<endl;
			n=foobar[c]+1;
		}
		foobar[i]=n;
	}
//	for(int i =0; i<100;i++)
//	cout<<foobar[i]<<" "<<i<<endl;
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
void calculatePrime()
        {
        primeArr[0]=1;
        primeArr[1]=0;
        for (int i=2;i*i<=SIZE;i++)
                {
        //      cout<<i;
                        if(!primeArr[i])
                        for(int j=2;j*i<SIZE;j++)
                       {
			if()
				 primeArr[j*i]=i*j;
 
                }
}

int isPrime(int n){
//cout<<n<<"testiiii"<<primeArr[n]<<endl;
return primeArr[n];
}

int getMax(long int i)
{
        int n,k,l=(int)sqrt(i);
  //      cout<<l<<"test"<<i<<endl;
        for(int  j =l;j>0;j--)
        {
                if(i%j==0)
                {
                n=j;
                k=i/j;
                break;
//		cout<<j<<"break"<<endl;
                }
        }
//	cout<<n<<k<<endl;
        n=(n>=k)?n:k;
        return n ;
}


