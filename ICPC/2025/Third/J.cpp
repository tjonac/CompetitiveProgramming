#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

struct STree{
    vector<int> st; int n;
    STree(int n): st(4*n+5,0), n(n){}

    void init(int k, int s, int e, int *a){
        if(s+1==e){st[k]=a[s]; return;}
        int m=(s+e)/2;
        init(2*k,s,m,a); init(2*k+1,m,e,a);
        st[k]=st[2*k]^st[2*k+1];
    }

    void upd(int k, int s, int e, int p, int v){
        if(s+1==e){st[k]=v; return;}
        int m=(s+e)/2;
        if(p<m) upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=st[2*k]^st[2*k+1];
    }

    int query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a) return 0;
        if(s>=a&&e<=b) return st[k];
        int m=(s+e)/2;
        return query(2*k,s,m,a,b)^query(2*k+1,m,e,a,b);
    }

    void init(int *a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
};

void solve(){
    int n,q; cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    STree st(n);
    st.init(a);
    for(int i=0;i<q;i++){
        char c; cin>>c;
        int x,y; cin>>x>>y;
        if(c=='P'){
            cout<<(st.query(x-1,y)==0 ? "JUAN":"FRANK")<<'\n';
        }
        else{
            a[x-1]+=y;
            st.upd(x-1,a[x-1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
