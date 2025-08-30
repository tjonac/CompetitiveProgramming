#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Find the number of multiples of k primes less than or equal to n
ll solve(){
  ll n,ans=0,a; cin>>n;
  int k,m,ones,j; cin>>k;
  vector<ll> v(k);
  for(auto&u:v) cin>>u;
  for(int i=1;i<(1<<k);i++){
    m=i;
    ones=0;
    a=n;
    j=0;
    while(m>0){
      ones+=m&1;
      if(m&1){
        a/=v[j];
      }
      m>>=1;
      j++;
    }
    if(ones%2) ans+=a;
    else ans-=a;
  }
  return ans;
}