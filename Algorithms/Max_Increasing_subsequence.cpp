#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
#define inf 1000000001
//#define f first
//#define s second 
void solve(){
  int n; cin>>n;
  vector<int> v(n),dp(n,inf);
  for(auto&u:v) cin>>u;
  dp[0]=v[0];
  for(int i=1;i<n;i++){
    auto it=lower_bound(dp.begin(),dp.end(),v[i]);
    dp[it-dp.begin()]=v[i];
  }
  int ans=0;
  for(int i=1;i<n;i++) if(dp[i]!=inf) ans=i;
  cout<<ans+1;
}
int main(){
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t=1; for(int T=0;T<t;T++) solve();
}