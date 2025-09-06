#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    ll a,b; cin>>a,b;
    if(b>a) cout<<2LL*(a+b);
    else if(a==b) cout<<3LL*a;
    else if(b==a-1) cout<<2LL*a-1;
    else if(b==a-2) cout<<3LL*b+3;
    else cout<<2LL*(a+b);
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
