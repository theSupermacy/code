//https://www.hackerrank.com/challenges/insertionsort1

#include <iostream>
using namespace std;
void print(int [],int);
void insert(int [],int ,int,int);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n;i++) cin>>arr[i];
	int lastElem = arr[n-1];
	int i ;
	for( i =0;i<n-1;i++) {
		if(arr[i]>=lastElem) break;
	}
	insert(arr,i,n-1,lastElem);

	return 0;
}
void print(int arr[],int length){
	for(int i =0;i<length;i++) cout<<arr[i]<<" ";
	cout<<endl;
}

void insert(int arr[],int start, int last,int lastElem){
	for(int i = last-1; i >= start; i--){
		arr[i+1] = arr[i];
		print(arr, last+1);
	}
	arr[start] = lastElem;
	print(arr,last+1);
	return;
}

