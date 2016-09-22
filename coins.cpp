//http://www.spoj.com/problems/COINS/

#include<iostream>
#include<cstring>
using namespace std;
long long int sum[1000001];
long long int limit = 1000001;
long long int recursion(long long int);
int main(){
	sum[0] =0;
	for(long long int i =1;i<limit;i++){
		if(i<sum[i/2]+sum[i/3]+sum[i/4])
			sum[i]=sum[i/2]+sum[i/3]+sum[i/4];
		else
			sum[i] =i;
	}
	long long int number;
	while(cin>>number){
	//	if(number==0) break;
		//cout<<"from sum" << sum[number]<<endl;
		if(number<limit) cout<<sum[number]<<endl;
		else{
		cout<<recursion(number)<<endl;
		}
		}
	return 0;
}
long long int recursion(long long int number){
	if(number<limit)
		return sum[number];
       	long long int summation = recursion(number/2) +recursion(number/3) +recursion(number/4);
		if(summation>number)
			return summation;
		return number;
}
