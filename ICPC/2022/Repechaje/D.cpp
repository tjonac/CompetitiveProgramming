#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    int m; cin>>m;
    vector<ll> index(m+1),v;
    for(int i=0;i<m;i++){
        int x; cin>>x;
        if(x==1){
            ll y; cin>>y;
            index[i+1]=y;
            auto it= lower_bound(v.begin(),v.end(),y);
            v.insert(it,y);
        }
        else if(x==2){
            ll y;cin>>y;
            v.erase(lower_bound(v.begin(),v.end(),index[y]));
        }
        else if(x==3){
            ll y,z; cin>>y>>z;
            v.erase(lower_bound(v.begin(),v.end(),index[y]));
            index[y]+=z;
            auto it= lower_bound(v.begin(),v.end(),index[y]);
            v.insert(it,index[y]);
        }
        else{
            ll y; cin>>y;
            cout<<lower_bound(v.begin(),v.end(),index[y])-v.begin()<<'\n';
        }

    }
}

int main(){ 
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
