#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    long double h1,h2,b; cin>>h1>>h2>>b;
    cout<<ceil(log(h1/h2)/(log(b/(b-1))))<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t; cin>>t; for(int T=0;T<t;T++) solve();
}
