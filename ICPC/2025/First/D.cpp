#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    int k; cin>>k;
    vector<ll> v(k), sum(k,0);
    for(auto&u:v) cin>>u;
    int n; cin>>n;
    vector<vector<ll>> mat(n,vector<ll> (k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>mat[i][j];
            sum[j]+=mat[i][j];
        }
    }
    ll d=1e18;
    for(int i=0;i<k;i++){
        if(sum[i]==0) continue;
        d=min(d,v[i]/sum[i]);
    }
    for(int i=0;i<k;i++) v[i]-=d*sum[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            v[j]-=mat[i][j];
            if(v[j]<0){
                cout<<d+1<<' '<<i+1;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
