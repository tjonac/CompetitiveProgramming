#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

const int NMAX=202;
vector<vector<ll>> adj(NMAX,vector<ll> (NMAX,0)), capacity(NMAX,vector<ll> (NMAX));

ll bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s]=-2;
    queue<pair<int,ll>> q;
    q.push({s,1e12});

    while(!q.empty()){
        int u=q.front().first; ll x=q.front().second; q.pop();
        for(int i=0;i<NMAX;i++){
            if(parent[i]==-1 && capacity[u][i] && adj[u][i]){
                parent[i]=u;
                ll flow=min(x,capacity[u][i]);
                if(t==i) return flow;
                q.push({i,flow});
            }
        }
    }
    return 0;
}

ll max_flow(int s, int t, int n){
    ll flow=0, curr;
    vector<int> parent(n);
    while(curr=bfs(s,t,parent)){
        flow+=curr;
        int u=t;
        while(u!=s){
            capacity[parent[u]][u]-=curr;
            capacity[u][parent[u]]+=curr;
            u=parent[u];
        }
    }
    return flow;
}


void solve(){
    int n,m; cin>>n>>m;
    vector<ll> w(n);
    for(auto&u:w) cin>>u;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        capacity[x][y]=1e12;
        adj[x][y]=1;
        adj[y][x]=1;
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        if(w[i]>0){
            capacity[i+1][n+1]=w[i];
            adj[i+1][n+1]=1;
            sum+=w[i];
        }
        else{
            capacity[0][i+1]=-w[i];
            adj[0][i+1]=1;
        }
    }
    cout<<sum-max_flow(0,n+1,n+2);
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}