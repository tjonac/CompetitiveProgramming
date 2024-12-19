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
  ifstream f("input.txt");
  vector<ll> a,b;
  int i=0; ll x;
  while(f>>x){
    if(i%2) b.pb(x);
    else a.pb(x);
    i++;
  }
  x=0;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(int i=0;i<a.size();i++){
    x+=abs(a[i]-b[i]);
  }
  cout<<x;
}
int main(){
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t=1; for(int T=0;T<t;T++) solve();
}
