//http://www.spoj.com/problems/PT07Y/
#include <iostream>
#include <vector>
#include <list>

using namespace std;
void BFS(int, vector<vector<int>> , int []);
int main(){
  int n,m,e1,e2;
  cin>>n>>m;
  int visited[n];
  for(int i = 0 ; i< n; i++) visited[i] = -1;
  vector< vector<int> > adjencyList(n+1);
  while(m--){
    cin>>e1>>e2;
    adjencyList[e1].push_back(e2);
    adjencyList[e2].push_back(e1);
  }
  int starting_point = e1;
  bool result = BFS(starting_point, adjencyList, visited);
  if(result)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}

void BFS(int starting_point, vector< vector<int>> adjList, int visited[]){
  list <int> q;
  q.push_back(starting_point);
  while(!q.empty()){
      int node = q.front();
      for(int i =0 ; i< adjList[node].size() ; i++){
        if(visited[i] == -1){
          q.push(i);
          visited[i] = node;
        }
        else return false;
      }
  }
  return true;
}
