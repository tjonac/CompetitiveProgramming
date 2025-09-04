#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll binexp(ll a, ll b){
  ll res=1;
  while(b>0){
    if(b&1){
      res*=a;
      res%=mod;
    }
    a*=a;
    a%=mod;
    b>>=1;
  }
  return res;
}
//binary matrix exponentation
//performs mxp pxn matrix mult
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