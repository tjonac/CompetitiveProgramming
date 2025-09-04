#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    ll a,b,c,d; cin>>a>>b>>c>>d;
    if(c<=a){
        if(d<=a) cout<<0;
        else if(a<=d && d<=b) cout<<d-a;
        else cout<<b-a;
    }
    else if(c>=a && c<=b){
        if(d<=b) cout<<d-c;
        else cout<<b-c;
    }
    else cout<<0;
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t; cin>>t; for(int T=0;T<t;T++) solve();
}
