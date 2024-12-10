#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
//#define f first
//#define s second
const int kMaxV=1e6;
int sieve[kMaxV+1];
//Array with the smallest prime that divides i, 0 if i is prime.
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

void solve(){
  int n; cin>>n; 
  vector<int> v(n); 
  for(auto&u:v) cin>>u;
  sort(v.begin(),v.end());
  for(int i=1;i<n;i++){
    if(sieve[v[i]]==0){
      cout<<-1<<'\n';
      return;
    }
  }
  if(sieve[v[0]]){
    cout<<2<<'\n';
    return;
  }
  int p=v[0];
  for(int i=1;i<n;i++){
    int q=sieve[v[i]];
    if(q==2){
      if(2*p>v[i]){
        cout<<-1<<'\n';
        return;
      }
    }
    else if(p==q){
      continue;
    }
    else if(2*(p/q+1)*q>v[i]){
      cout<<-1<<'\n';
      return;
    }
      
  }
  cout<<p<<'\n';
}


int main(){
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  primes();
  int t; cin>>t; for(int T=0;T<t;T++) solve();
}
