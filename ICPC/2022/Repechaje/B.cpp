#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define f first
#define s second
pair<int,int> a,b;
vector<vector<int>> mat(101,vector<int> (101));
vector<vector<bool>> visited(101,vector<bool> (101));
vector<int> movesx = {0,0,1,-1}, movesy={1,-1,0,0};
bool found=false;

void dfs(int mask, pair<int,int> curr, int n, int m){
    if(!(mask&(1<<mat[curr.f][curr.s]))) return;
    if(curr.f==b.f && curr.s==b.s){
        found = true;
        return;
    }
    visited[curr.f][curr.s] = true;
    for(int i=0;i<4;i++){
        int x=curr.f+movesx[i],y=curr.s+movesy[i];
        if(x>0 && x<n+1 && y>0 && y<m+1 && !visited[x][y] && (mask&(1<<mat[x][y]))){
            dfs(mask,{x,y},n,m);
        }
    }
}
void solve(){
    int n,m; cin>>n>>m;
    cin>>a.f>>a.s;
    cin>>b.f>>b.s;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++) {cin>>mat[i][j]; mat[i][j]--;}
    }
    int ans=10;
    for(int i=1;i<(1<<10);i++){
        found=false;
        for(int i=1;i<n+1;i++) for(int j=1;j<m+1;j++) visited[i][j]=false;
        dfs(i,a,n,m);
        if(found) ans=min(ans,__builtin_popcount(i));
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}