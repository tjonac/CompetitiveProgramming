#include<bits/stdc++.h>
using namespace std;

const int NMAX=1e6;
vector<vector<int>> adj(NMAX);
vector<bool> visited(NMAX,false);
//dfs
void dfs(int s){
    if(visited[s]) return;
    visited[s]=true;
    for(auto&u:adj[s]) dfs(u);
}

//bfs
void bfs(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(auto&u:adj[s]){
            if(visited[u]) continue;
            q.push(u);
        }
    }
}