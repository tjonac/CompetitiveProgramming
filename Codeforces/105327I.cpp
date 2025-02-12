#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
#define inf 1000000000
//#define f first
//#define s second 

const int kMaxV=1e6;
int sieve[kMaxV+1];
void primes(){
  for(int i=4;i<=kMaxV;i+=2) sieve[i]=2;
  for(int i=3;i<=kMaxV/i;i++){
    if(sieve[i]) continue;
    for(int j=i*i;j<=kMaxV;j+=i){
      if(sieve[j]) continue;
      sieve[j]=i;
    }
  }
}
vector<int> PrimeFactors(int x){
  if(x==1) return {};
  unordered_set<int> primes;
  while(sieve[x]){
    primes.insert(sieve[x]);
    x/=sieve[x];
  }
  primes.insert(x);
  return {primes.begin(),primes.end()};
}
void solve(){
  int n; cin>>n;
  vector<int> mp(1000001,0);
  vector<ll> po(n+1);
  po[0]=1;
  for(int i=1;i<=n;i++) po[i]=(po[i-1]*2)%mod;
  for(int i=0;i<n;i++){
    int a; cin>>a;
    vector<int> p = PrimeFactors(a);
    for(int j=1;j<(1<<p.size());j++){
      int b=j,aux=1;
      for(int k=0;k<p.size();k++){
        if(b&1) aux*=p[k];
        b>>=1;
      }
      mp[aux]++;
    }
  }
  int q,a,pow; cin>>q;
  for(int i=0;i<q;i++){
    cin>>a;
    if(a==1){
      cout<<po[n]<<'\n';
      continue;
    }
    pow=0;
    vector<int> p=PrimeFactors(a);
    for(int j=1;j<(1<<p.size());j++){
      int b=j,aux=1,e=0;
      for(int k=0;k<p.size();k++){
        if(b&1){
          aux*=p[k];
          e++;
        }
        b>>=1;
      }
      if(e%2) pow+=mp[aux];
      else pow-=mp[aux];
    }
    cout<<po[n-pow]<<'\n';
  }
}
int main(){
  primes();
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t=1; for(int T=0;T<t;T++) solve();
}