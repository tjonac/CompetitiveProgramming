#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000000000
#define f first 
#define s second
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
	int m=a.size(),p=a[0].size(),n=b[0].size();
    vector<vector<ll>> res(m,vector<ll> (n,0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < p; k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}
vector<vector<ll>> matexp(vector<vector<ll>> a, int k){
    int n=a.size(),t=k;
    vector<vector<ll>> ans(n,vector<ll> (n,0)),aux=a;
    for(int i=0;i<n;i++) ans[i][i]=1;
    while(t>0){
        if(t&1) ans=mul(ans,aux);
        t>>=1;
        aux=mul(aux,aux);
    }
    return ans;
}
void solve(){
    int n; cin>>n;
    vector<int> v((1<<n)-1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<n)-1;j++){
            if(v[j]) continue;
            for(int k=0;k<(1<<n)-1;k+=(1<<i)) v[k+j]=i;
            break;
        }
    }
    for(auto&u:v) cout<<u<<' ';
}
int main() {
  ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int t=1; for(int T=0;T<t;T++) solve();
}
