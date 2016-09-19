//http://www.spoj.com/problems/PPATH/
#include <iostream>
#include <list>
#include <cmath>

using namespace std;
int PrimeArr[10000];
void seive();
bool checkPrime(int);
int main(){
	int t;
	cin>>t;
	seive();
	//cout<<checkPrime(1033)<<checkPrime(1030)<<endl;
	int visited[10001];
	while(t--){
		list<int> queue;
		int prime1,prime2,steps =0;
		cin>>prime1>>prime2;
		for(int i=1;i<10000;i++) visited[i]=0;
		queue.push_back(prime1);
		visited[prime1]=prime1;
		int flag =1;
		int test =1;
		if(prime1==prime2) test =0;
		while(!queue.empty() and flag){
			int current_number=queue.front();
			queue.pop_front();
			int n =1,testPrime=current_number,remainder=0,firstPart;
		       	while(testPrime){
				firstPart = current_number/(int)pow(10,n);
				for(int i =0 ;i<=9;i++) {
					if( i==0 and testPrime/10==0) continue;
					int number = firstPart *(int) pow(10,n) + i*(int)pow(10,n-1)+remainder;
					if(checkPrime(number) and visited[number]==0) {
					visited[number] = current_number;
					queue.push_back(number);
					//cout<<number<<" "<<current_number<<endl;		
					}
					if(number == prime2) {
						flag=0;
						break;
					}
				//	cout<<number<<" ";
			}
	//		cout<<endl;

			remainder = current_number%int(pow(10,n));
			n++;
			testPrime = testPrime/10;
			}
		}
		int varindex = prime2;
		while(visited[varindex]!=prime1 and test){
		//	cout<<visited[varindex]<<"testing"<<endl;
			steps++;
			varindex = visited[varindex];
		}
		if(!test) cout<<test<<endl;
		else cout<<steps+1<<endl;

	}
	return 0;
}
void seive(){
	for(int i =2;i*i<10001;i++){
		if(PrimeArr[i]==0){
			for(int j = 2;j*i < 10001;j++)
			{
				PrimeArr[j*i] =1;
			}
		}
	}
}
bool checkPrime(int number){
	int result = true;
	if(PrimeArr[number]) result =false;
	return result;
}
