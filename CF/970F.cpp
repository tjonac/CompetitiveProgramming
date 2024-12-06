#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
//#define f first
//#define s second
const int NMAX=2e6;
int parent[NMAX],siz[NMAX], col[NMAX];

void make_set(int v) { //O(1)
  parent[v] = v;
  siz[v] = 1;
}

int find_set(int v) { //O(logn)
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) { //O(logn)
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (siz[a] < siz[b])
       swap(a, b);
      parent[b] = a;
      siz[a] += siz[b];
      col[a]+=col[b];
  }
}
void solve(){
  int n; cin>>n;
  int p[n];
  bool visited[n];
  for(int i=0;i<n;i++){
    cin>>p[i];
    p[i]-=1;
  }
  string s; cin>>s;
  for(int i=0;i<n;i++) visited[i]=false;
  for(int i=0;i<n;i++){
    if(s[i]=='0') col[i]=1;
    else col[i]=0;
  }
  for(int i=0;i<n;i++) make_set(i);
  for(int i=0;i<n;i++){
    if(visited[i]) continue;
    visited[i]=true;
    int aux=p[i];
    while(aux!=i){
      visited[aux]=true;
      union_sets(i,aux);
      aux=p[aux];
    }
  }
  for(int i=0;i<n;i++){
    cout<<col[parent[i]]<<' ';
  }
  cout<<'\n';

}


int main() {
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t; cin>>t; for(int T=0;T<t;T++) solve();
}
