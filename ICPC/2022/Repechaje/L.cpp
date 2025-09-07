#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define f first
#define s second
vector<vector<int>> adj(1000001);
vector<int> childs(1000001);
int parent=-1, t, path=0, temp=0;
int dfs(int u, int prev){
    if(u==t){
        parent=prev;
    }
    for(auto&v:adj[u]){
        if(v!=prev) childs[u] += dfs(v,u);
    }
    childs[u]=max(1,childs[u]);
    return childs[u];
}

void dfs3(int u, int prev){
    if(u==t){
        path=temp;
    }
    for(auto&v:adj[u]){
        if(v!=prev) {temp++; dfs3(v,u); temp--;}
    }
}
void solve(){
    int n; cin>>n>>t;
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    dfs3(1,0);
    cout<<2*(n-1)-2*childs[parent]-path+2;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
