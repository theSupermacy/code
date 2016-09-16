//https://www.hackerrank.com/challenges/qheap1


#include<iostream>
using namespace std;
long int getMin(long int arr[]);
long int insert(long int,long int [],long int);
void perculup(long int arr[],long int );
long int deleteHeap(long int , long int [],long int);
int main(){
	int t;
	cin>>t;
	long int arr[100002],length=0;
	arr[0]=-111;
	while(t--){
		long int options,number;
		cin>>options;
		//cout<<length<<"testin"<<number<<endl;
		if(options==1){
			cin>>number;
		       	length=insert(number,arr,length);
		}
		else if(options == 2){
			cin>>number;
			length= deleteHeap(number,arr,length);
		}
		else cout<<getMin(arr)<<endl;
	//	cout<<"Heap after "<<options << " : "<<number<<endl;
	//	for(int i = 1 ; i<=length;i++) cout<<arr[i]<<" ";
	//	cout<<endl;
	}
	return 0;
}

long int insert(long int insertElem,long int arr[],long int length){
	length++;
	arr[length]=insertElem;
	perculup(arr,length);
	return length;
}
void perculup(long int arr[],long int length){
	while(length>1){

		if(arr[length]>arr[length/2]) return ;
		int temp;
		temp=arr[length];
		arr[length] = arr[length/2];
		arr[length/2] = temp;
		length = length/2;
	}
	return;
}

long int getMin(long int arr[]){
	return arr[1];
}
long int deleteHeap(long int number,long int arr[],long int length){
	long int index,left,right,parent,temp;
	for(index=1;index<=length;index++)
		if(number==arr[index])
			break;
	arr[index]=arr[length];
	length--;
	parent=index/2;
	left=index*2;
	right=index*2+1;
	if(arr[index]<arr[parent]){
		while(index>=1){
			 if(arr[index]>arr[parent]) break;
			 temp=arr[index];
			 arr[index] = arr[parent];
			 arr[parent] = temp;
			 index=parent;
		         parent=parent/2;
		 }
	}
	else{
	//	cout<<right<<" "<<left<<" "<<index<<" "<<parent<<endl;
		while(right<length+1){
                //	cout<<arr[right]<<" "<<arr[left]<<" "<<index<<" "<<parent<<endl;
			if(arr[index]<=arr[right] and arr[index]<=arr[left])
				break;
			if(arr[left]<=arr[right]){
		//		cout<<right<<" "<<left<<" "<<index<<" "<<parent<<endl;
				temp = arr[left];
				arr[left]=arr[index];
				arr[index]=temp;
				index = left;
			}
			else{
				temp = arr[right];
				arr[right] = arr[index];
				arr[index]= temp;
				index = right;
			}
			left=2*index;
			right = 2*index+1;
		}
		if (left == length+1 && arr[index])    {
			temp = arr[index];
			arr[index] = arr[left];
		        arr[left] = temp;
		    }


	}
	return length;
}
