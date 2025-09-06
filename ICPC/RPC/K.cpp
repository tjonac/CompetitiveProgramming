#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    long double n; cin>>n;
    long double ans=0, s=0, curr=0;
    vector<long double> v(n);
    for(auto&u:v) cin>>u;
    for(auto&u:v) s+=u;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(long double i=1;i<=n;i++){
        curr+=v[i-1];
        ans=max(ans, curr/s-i/n);
    }
    cout<<fixed<<setprecision(8)<<ans*(double(100));
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
    return 0;
}
