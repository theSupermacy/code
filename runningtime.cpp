//https://www.hackerrank.com/challenges/runningtime?h_r=next-challenge&h_v=zen
#include <iostream>
using namespace std;
void print(int [],int);
int insert(int [],int ,int,int);
int main(){
	int n ;
	cin>>n;
	int arr[n],j,steps=0;
	for(int i = 0 ; i< n; i++) cin>>arr[i];
	for(int i = 1 ; i< n; i++)
	{
		for( j = 0 ; j< i;j++) if(arr[j]>arr[i]) steps=steps+insert(arr,j,i,arr[i]);
	}
	cout<<steps;
	return 0 ;
}
void print(int arr[],int length){
	for(int i =0;i<length;i++) cout<<arr[i]<<" ";
		cout<<endl;
}

int insert(int arr[],int start, int last,int lastElem){
	int steps = 0;
	for(int i = last-1; i >= start; i--)	{
		arr[i+1] = arr[i];
	}
	steps = last - start;
//	cout<<lastElem<<"is shifted from"<<last<<"to " <<start<<endl;
	arr[start] = lastElem;
	return steps;
}


