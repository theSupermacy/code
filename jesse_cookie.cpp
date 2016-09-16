//https://www.hackerrank.com/challenges/jesse-and-cookies
#include <iostream>
using namespace std;
void insert(long long int [],long int &len, long long int);
void perculup(long long  int [],long long int);
long int getMin(long long int arr[],long int &);
void deleteRoot(long long int [],long int &);
void print(long long int [],long int);
int main(){
	long int n,k,length=0,first,second;
	long long int sum;
	int steps = -1;
	cin>>n>>k;
	long long int minHeap[n+1];
	minHeap[0]=-1;
	for(int i =0;i<n;i++){
		long long int input;
		cin>>input;
		insert(minHeap,length,input);
	}
//	print(minHeap,length);
	while(length>1){
		first = getMin(minHeap,length);
		second = getMin(minHeap,length);
		if(first >= k and  second >= k) break;
//		cout<<"after step " <<steps+1<<"sum is " << sum<<endl;
		sum = first + 2*second;
		insert(minHeap,length,sum);
		if(steps>=999996) { cout<<length<<" "<<steps<<endl;print(minHeap,length);}
	//	print(minHeap,length);
		steps++;
	}
	if(length ==1 and minHeap[1]<k) cout<<-1<<endl;
	else cout<<steps+1<<endl;
	print(minHeap,length);
	return 0;
}
void print(long long int minheap[],long int length){
	for(int i =1;i<=length;i++) cout<<minheap[i]<<" ";
	cout<<endl;
	return;
}
void insert(long long int arr[],long int &length,long long int input){
	length++;
	arr[length]=input;
	perculup(arr,length);
}
void perculup(long long int minHeap[],long long int length){
	long int temp,templength=length;
	while(templength>1){
		if(minHeap[templength]>=minHeap[templength/2]) break;
		temp = minHeap[templength];
		minHeap[templength] = minHeap[templength/2];
		minHeap[templength/2] = temp;
		templength = templength/2;
	}
	return;
}	
long int getMin(long long int arr[],long int &length){
	long int minElement = arr[1];
	deleteRoot(arr,length);
	return minElement;
}
void deleteRoot(long long int minHeap[], long int &length){
	long int index=1;
	minHeap[index]=minHeap[length];
	long int temp,right,left;
	right = 2*index+1;
	left = 2*index;
//	cout<<minHeap[index]<<" "<<length<<endl;
	while(right<length){
		if(minHeap[right]>=minHeap[index] and minHeap[left]>=minHeap[index]) break;
		if(minHeap[right]<minHeap[left]){
			temp=minHeap[index];
			minHeap[index]=minHeap[right];
			minHeap[right]=temp;
			index = right;
		}
		else{
			temp = minHeap[index];
			minHeap[index] = minHeap[left];
			minHeap[left]=temp;
			index = left;
		}
		right = index * 2 +1;
		left = index * 2;
	}
		if (left == length+1 && minHeap[index])    {
			temp = minHeap[index];
			minHeap[index] = minHeap[left];						        minHeap[left] = temp;
		    }
	length--;
	return;

}
