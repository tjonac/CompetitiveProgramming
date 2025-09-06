#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    int ans=0;
    for(int i=1;i<2500*2500+1;i++){
        int count=0;
        for(int j=1;j*j*j*j<=i;j++){
            if(i%(j*j)==0){
                if(i/(j*j)!=j*j && int(sqrt(i))*int(sqrt(i)) == i) count+=2;
                else count++;
            }
        }
        ans=max(ans,count);
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
}
