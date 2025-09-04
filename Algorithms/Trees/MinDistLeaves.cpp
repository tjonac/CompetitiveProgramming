//Min distance to a leave for every vertex in a tree O(n)
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int MAX=1000000;
int toleaf[100001];
int dist[100001];
//dfs to find the minimum distance to a leaf ONLY going downwards
int dfs(int s,vector<vector<int>>& adj){
  if(toleaf[s]!=MAX) return toleaf[s];
  if(adj[s].size()==0){
    toleaf[s]=1;
    return 1;
  }
  vector<int> aux;
  for(auto&u:adj[s]){
    aux.pb(dfs(u,adj));
  }
  toleaf[s]=*min_element(aux.begin(),aux.end())+1;
  return toleaf[s];
}
void solve(){
  int n; cin>>n;
  vector<bool> visited(n+1,false);
  for(int i=1;i<=n;i++) toleaf[i]=MAX;
  for(int i=1;i<=n;i++) dist[i]=MAX;
  vector<vector<int>> adj(n+1);
  for(int i=2;i<=n;i++){
    int a; cin>>a;
    adj[a].pb(i);
  }
  dfs(1,adj);

  //bfs to find minimum distance to a leaf going upwards or downwards.
  queue<int> q;
  q.push(1);
  dist[1]=toleaf[1];
  while(!q.empty()){
    int s=q.front();
    q.pop();
    for(auto&u:adj[s]){
      dist[u]=min(dist[s]+1,toleaf[u]);
      q.push(u);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t=1; for(int T=0;T<t;T++) solve();
}
