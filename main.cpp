#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int x,y,z; cin>>x>>y>>z;
        adj[x-1].pb({y-1,z});
        adj[y-1].pb({x-1,z});
    }
    vector<int> v(n,1e9);
    for(int i=0;i<n;i++){
        for(auto&u:adj[i]) v[i]=min(v[i],u.second);
    }
    for(int i=0;i<n;i++){
        for(auto&u:adj[i]){
            if(max(v[i],v[u.first])!=u.second){
                cout<<-1<<endl;
                return;
            }
        }
    }
    for(auto&u:v) cout<<u<<' ';
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t; cin>>t; for(int T=0;T<t;T++) solve();
}
