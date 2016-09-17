//https://www.hackerrank.com/challenges/maxsubarray

#include <iostream>
using namespace std;
int getMin(int [],int n);
int main(){
	int t,n;
	cin>>t;
	while(t--){
	cin>>n;
	int arr[n];
	long int continousSum=0,nonContinous=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>0) nonContinous = nonContinous+arr[i];
	//	cout<<"entering beast mode"<<nonContinous<<endl;
	}
	if(nonContinous ==0) cout<<getMin(arr,n)<<" "<<getMin(arr,n)<<endl;
	else{
		long int testingSum =0,continousSum=arr[0];
		for(int i = 0;i<n;i++){
			testingSum=testingSum+arr[i];
			if(testingSum<0) testingSum =0;
		       if(testingSum>continousSum)	continousSum=testingSum;
		}
		cout<<continousSum<<" "<<nonContinous<<endl;
	}
	}

	return 0;


}
int getMin(int arr[],int n){
	int min=arr[0];
	for(int i=1;i<n;i++) if(min<arr[i]) min=arr[i];
	return min;
}
