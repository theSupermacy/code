//https://www.hackerrank.com/challenges/insertionsort2?h_r=next-challenge&h_v=zen

#include <iostream>
using namespace std;
void print(int [],int);
void insert(int [],int ,int,int);
int main(){
	int n ;
	cin>>n;
	int arr[n],j;
	for(int i = 0 ; i< n; i++) cin>>arr[i];
	for(int i = 1 ; i< n; i++)
	{
		for( j = 0 ; j< i;j++) if(arr[j]>=arr[i]) insert(arr,j,i,arr[i]);
		print(arr,n);
	}

	return 0 ;
}
void print(int arr[],int length){
	for(int i =0;i<length;i++) cout<<arr[i]<<" ";
	cout<<endl;
}

void insert(int arr[],int start, int last,int lastElem){
	for(int i = last-1; i >= start; i--){
		arr[i+1] = arr[i];
	}
	arr[start] = lastElem;
	return;
}

