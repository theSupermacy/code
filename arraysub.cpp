#include<iostream>
#include<cstring>
using namespace std;
void print(long int [] ,long long int , string);
long int maximum(long int ,long int);
int main()
{

   	long long int size,max=0;
       	cin>>size;
	long int a[size],lf[size],rht[size];
	for(int i=0;i<size;i++)
	cin>>a[i];
	int window;
       	cin>>window;
	for(int i=0;i<size;i++){
		if((i+1)%window==0) max= a[i];
		if(max<a[i]) max= a[i];
		lf[i]=max;		
	}
	int j =0;
	for(int i = size-1;i>=0;i--){
		if(i==size-1) max = a[i];
		if((i+1)%window ==0) max = a[i];
		if(max<a[i]) max = a[i];
		rht[i] = max;
	}
	//print(lf,size,"This is left array");
	//print(rht,size,"This is right array");
	for(int i =0 ;i<size-window+1;i++)
		cout<<maximum(lf[window+i-1],rht[i])<<" ";
	return 0;
}
long int maximum(long int a,long int b){
	return (a>=b)?a:b;
}
void print(long int arr[],long long int size,string comment){
	for(int i =0;i< size;i++) cout<<arr[i]<<" ";
	cout<<comment<<endl;
}
