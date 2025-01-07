//https://codeforces.com/contest/1420/problem/C1
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
//#define f first
//#define s second
void solve(){
  int n,q; cin>>n>>q;
  vector<ll> v(n);
  for(auto&u:v) cin>>u;
  vector<ll> mxsub(n+1),mnsub(n+1);
  for(int i=n-1;i>=0;i--){
    mxsub[i]=max(mxsub[i+1],v[i]-mnsub[i+1]);
    mnsub[i]=min(mnsub[i+1],v[i]-mxsub[i+1]);
  }
  cout<<mxsub[0]<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t; cin>>t; for(int T=0;T<t;T++) solve();
}
