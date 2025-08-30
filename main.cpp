#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

vector<vector<ll>> adj(500), capacity(500,vector<ll> (500));

ll bfs(int s, int t, ll lim, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s]=-2;
    queue<pair<int,ll>> q;
    q.push({s,1e12});

    while(!q.empty()){
        int u=q.front().first; ll x=q.front().second; q.pop();
        for(auto&v:adj[u]){
            if(parent[v]==-1 && capacity[u][v]>=lim){
                parent[v]=u;
                ll flow=min(x,capacity[u][v]);
                if(t==v) return flow;
                q.push({v,flow});
            }
        }
    }
    return 0;
}

ll max_flow(int s, int t, int n){
    vector<int> parent(n);
    ll lim=0,flow=0,curr;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) lim+=capacity[i][j];
    while(lim){
        while(curr=bfs(s,t,lim,parent)){
            flow+=curr;
            int u=t;
            while(u!=s){
                capacity[parent[u]][u]-=curr;
                capacity[u][parent[u]]+=curr;
                u=parent[u];
            }
        }
        lim>>=1;
    }
    return flow;
}

void solve(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        ll x,y,z; cin>>x>>y>>z; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        capacity[x][y]+=z;
    }
    cout<<max_flow(0,n-1,n);
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
