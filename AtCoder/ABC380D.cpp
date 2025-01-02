#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
//#define f first
//#define s second
char inv(char c){
  if((int) c>=97){
    return (char) c-32;
  }
  else return (char) c+32;
}
bool check(ll n,int m,ll q){
  ll ans=n;
  for(int i=0;i<=m;i++){
    if(ans+1>q) return 0;
    ans*=2;
  }
  return 1;
}
int bin_search(ll n, ll q){
  if(q<=n) return -1;
  int res=0, l=0,r=63;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(check(n,mid,q)){
      l=mid+1;
      res=mid;
    }
    else r=mid-1;
  }
  return res;
}
void solve(){
  string s; cin>>s;
  int q; cin>>q;
  ll n=s.size();
  for(int i=0;i<q;i++){
    ll k; cin>>k;
    int j=0;
    ll a=k;
    while(a>n){
      j++;
      a=a-(n*((1LL)<<bin_search(n,a)));
    }
    if(j%2) cout<<inv(s[a-1])<<' ';
    else cout<<s[a-1]<<' ';
  }
  cout<<endl;

}

int main(){
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t=1; for(int T=0;T<t;T++) solve();
}
