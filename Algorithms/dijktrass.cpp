#include<bits/stdc++.h>
using namespace std;
class dijkstra{
    private:
    int n;
    vector<int> dist;
    vector<bool> visited;
    vector<vector<pair<int,int>>> adj;
    set<pair<int,int>> nodes={{0,0}};
    public:
    dijkstra(int n,vector<vector<pair<int,int>>> A): adj(A){
        for(int i=0;i<n;i++){
            dist.push_back(INT_MAX);
            visited.push_back(false);
        }
        dist[0]=0;
    }
    int find(){
        for(int i=0;i<n;i++){
            auto it=nodes.begin();
            int u=(*it).second;
            nodes.erase(it);
            visited[u]=true;
            for(auto&v:adj[u]){
                if(visited[v.first]) continue;
                nodes.erase({dist[v.first],v.first});
                dist[v.first]=min(dist[v.first],dist[u]+v.second);
                nodes.insert({dist[v.first],v.first});
            }
        }
        return dist[n-1];
    }
};

