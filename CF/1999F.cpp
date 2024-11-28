#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
#define f first 
#define s second
// https://codeforces.com/problemset/problem/1999/F
vector<ll> factorial(1e6);
ll inv(ll a) {
  return a <= 1 ? a : mod- (long long)(mod/a) * inv(mod % a) % mod;
}
ll bin(int n, int k) {
  if(k>n) return 0;
  if(k==n) return 1;
  return factorial[n]*inv(factorial[k])%mod*inv(factorial[n - k]) % mod;
}
void solve(){
  int n,k; cin>>n>>k;
  int ones=0,aux;
  ll res=0;
  for(int i=0;i<n;i++){
    cin>>aux;
    ones+=aux;
  }
  for(int i=(k+1)/2;i<=k;i++){
    res+=bin(ones,i)*bin(n-ones,k-i) % mod;
  }
  cout<<res%mod<<'\n';
}

int main() {
  factorial[0] = 1;
  for (ll i = 1; i <= 1e6; i++) {
    factorial[i] = factorial[i - 1] * i % mod;
  }
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t; cin>>t; for(int T=0;T<t;T++) solve();
}
