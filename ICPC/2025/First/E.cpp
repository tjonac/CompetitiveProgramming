#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    int n,m; cin>>n>>m;
    vector<int> v(n);
    for(auto&u:v) cin>>u;
    for(int i=0;i<n;i++){
        if(v[i]>=m){
            cout<<i+1;
            return;
        }
    }
    cout<<-1;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
