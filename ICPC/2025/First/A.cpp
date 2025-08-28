#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    string s; cin>>s;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        bool bad=false;
        string p; cin>>p;
        if(p.size()%s.size()){
            cout<<"NO\n";
            continue;
        }
        for(int j=0;j<p.size();j++){
            if(s[j%s.size()]!=p[j]){
                cout<<"NO\n";
                bad=true;
                break;
            }
        }
        if(!bad) cout<<"YES\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
