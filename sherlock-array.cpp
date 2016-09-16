//https://www.hackerrank.com/challenges/sherlock-and-array

#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int arr[n];
	long long int sum[n];
	for(int i =0;i<n;i++){
		int n; 
		cin>>n;
		arr[i]=n;
		if(i>0)
			sum[i] = sum[i-1]+n;
		else
			sum[0]=n;
	}	
	//for(int i =0; i<n;i++)	cout<<sum[i]<<" ";
	 //cout<<endl;
	int flag=0;
	for(int i =1 ; i<n-1;i++){
	//	cout<<"sum[i-1] "<<sum[i-1]<<" sum[n] "<<sum[n-1]<<" sum[i] "<<sum[i]<<endl;
		if(sum[i-1]==(sum[n-1]-sum[i])){
			flag=1;
			break;
		}
	}
	if(n==1) flag=1;
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	}
	return 0;
}
