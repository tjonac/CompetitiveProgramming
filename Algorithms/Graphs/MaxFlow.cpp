#include<bits/stdc++.h>
using namespace std;

// O(NE^2)

const int NMAX=202;
vector<vector<int>> adj(NMAX), capacity(NMAX,vector<int> (NMAX));

int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s]=-2;
    queue<pair<int,int>> q;
    q.push({s,INT_MAX});

    while(!q.empty()){
        int u=q.front().first, x=q.front().second; q.pop();
        for(auto&v:adj[u]){
            if(parent[v]==-1 && capacity[u][v]){
                parent[v]=u;
                int flow=min(x,capacity[u][v]);
                if(t==v) return flow;
                q.push({v,flow});
            }
        }
    }
    return 0;
}

int max_flow(int s, int t, int n){
    int flow, curr;
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
