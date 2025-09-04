//Algorithm to find the lenght of the maximum path starting from each node in O(n).
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define s second
#define f first
const int NMAX=1e6;
vector<vector<int>> adj(NMAX);
vector<pair<int,int>> toleaf1(NMAX,{0,-1}), toleaf2(NMAX,{0,-1});
vector<int> toparent(NMAX,0),maxpath(NMAX);
void dfs1(int u, int k){
    priority_queue<pair<int,int>> st;
    for(auto&v:adj[u]){
        if(v==k) continue;
        dfs1(v,u);
        st.push({toleaf1[v].f,v});
    }
    if(st.empty()) return;
    toleaf1[u].f=st.top().f+1;
    toleaf1[u].s=st.top().s;
    st.pop();
    if(st.empty()) return;
    toleaf2[u].f=st.top().f+1;
    toleaf2[u].s=st.top().s;
}
void dfs2(int u,int k){
    for(auto&v:adj[u]){
        if(v==k) continue;
        if(v==toleaf1[u].s){
            toparent[v]=max(toparent[u],toleaf2[u].f)+1;
        }
        else toparent[v]=max(toparent[u],toleaf1[u].f)+1;
        dfs2(v,u);
    }
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i=0;i<n;i++) maxpath[i]=max(toparent[i],toleaf1[i].f);
}