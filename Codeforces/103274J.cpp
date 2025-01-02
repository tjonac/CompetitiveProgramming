//https://codeforces.com/gym/103274/problem/J
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
//#define f first
//#define s second
int MAX=1000000;
int toleaf[100001];
int dist[100001];
bool visited[100001];
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
ll inv(ll a) {
  a%=MOD;
  return a <= 1 ? a : MOD- (long long)(MOD/a) * inv(MOD % a) % MOD;
}
void solve(){
  int n; cin>>n;
  for(int i=1;i<=n;i++) toleaf[i]=MAX;
  for(int i=1;i<=n;i++) dist[i]=MAX;
  for(int i=1;i<=n;i++) visited[i]=false;
  vector<vector<int>> adj(n+1);
  for(int i=2;i<=n;i++){
    int a; cin>>a;
    adj[a].pb(i);
  }
  dfs(1,adj);
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
  ll s=0;
  for(int i=1;i<=n;i++){
    s+= (ll) dist[i];
    s%=MOD;
  }
  cout<<(s*inv((ll) n))%MOD;
}
int main(){
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t=1; for(int T=0;T<t;T++) solve();
}
