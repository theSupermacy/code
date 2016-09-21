//http://www.spoj.com/problems/CATM/
#include <iostream>
#include <list>
#include <cstring>

using namespace std;
int visited[101][101];
void bfs(int ,int ,int ,int);
void print(string,int,int,int );
bool valid(int ,int ,int ,int);
void reset(int [], int , int);
int main(){
	int n,m;
	cin>>n>>m;
	int length = 2*(n+m-2);
	int mouse[length];
	int cat1[length];
	int cat2[length];
	int t;
	cin>>t;
	while(t--){
		for(int i =0;i<=n;i++)
			for(int j =0;j<=m;j++){
				visited[i][j]=0;
			}
		int mouse_x,mouse_y,cat_x,cat_y,cat2_x,cat2_y;
		cin>>mouse_x>>mouse_y>>cat_x>>cat_y>>cat2_x>>cat2_y;
		bfs(mouse_x,mouse_y,n,m);
		//print("after mouse " , n,m,1);
		reset(mouse,n,m);
		//for(int i =0 ;i<length;i++) cout<<mouse[i]<<" ";
		bfs(cat_x,cat_y,n,m);
		//print("after cat1 " , n,m,1);
		reset(cat1,n,m);
		//for(int i =0 ;i<length;i++) cout<<cat1[i]<<" ";
		bfs(cat2_x,cat2_y,n,m);
		//print("after cat2 " , n,m,1);
		reset(cat2,n,m);
		//for(int i =0 ;i<length;i++) cout<<cat2[i]<<" ";
		int flag=0;
		for(int i =0 ; i<length;i++){
			//cout<<"mouse ka "<<mouse[i]<<" cat1 ka "<<cat1[i]<<" cat2 ka "<<cat2[i]<<endl;
			if(mouse[i]<min(cat1[i],cat2[i]))
				flag=1;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		}
	return 0;
}
void reset(int arr[],int x_length,int y_length){
	int k =0;
	for(int i = 1; i<=x_length;i++){
		for(int j =1 ; j<=y_length;j++){
			if(i==1 or j==1 or i==x_length or j==y_length){
				arr[k]=visited[i][j];
				k++;
			}
		}
	}
	for(int i =0;i<=x_length;i++)
		for(int j =0;j<=y_length;j++){
			visited[i][j]=0;
		}

}
void print(string comment, int x, int y,int flag){
	//flag 1 for visited and flag 0 for matrix
	cout<<comment<<endl;
	for(int i = 1; i<=x;i++)
	{
		for(int j = 1; j<=y ;j++){
			if(flag) cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
}
int x_movement[]= {1,0,-1,0};
int y_movement[] = {0,1,0,-1};
bool valid(int x,int y,int limitx,int limity){
	if((x>limitx or  x<1) or( y>limity or y<1)) return false;
	//cout<<x<<" "<<y<<endl;
	return true;
}
void bfs(int x , int y,int limit_x,int limit_y){
	list <int> x_queue;
	list <int> y_queue;
	visited[x][y] = 1;
	x_queue.push_back(x);
	y_queue.push_back(y);
	while(!x_queue.empty()){
		int current_x = x_queue.front();
		int current_y = y_queue.front();
		x_queue.pop_front();
		y_queue.pop_front();
		//cout<<current_y<<" "<<current_x<<endl;
		int steps = visited[current_x][current_y];
		for(int i =0; i<4;i++){
			int topx = current_x+x_movement[i];
			int topy = current_y+y_movement[i];
			if(valid(topx,topy,limit_x,limit_y) and visited[topx][topy]==0){
				x_queue.push_back(topx);
				y_queue.push_back(topy);
				visited[topx][topy]=visited[current_x][current_y]+1;
			}
		}
	}
}
