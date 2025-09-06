#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 998244353
#define mod 1000000007

void solve(){
    int r,c; cin>>r>>c;
    vector<vector<int>> mat(r,vector<int> (c)), left(r,vector<int> (c)), cols(r,vector<int> (c));
    for(int i=0;i<r;i++){
        string s; cin>>s;
        for(int j=0;j<c;j++) mat[i][j]=s[j]-'0';
    }
    for(int j=0;j<c;j++){
        cols[0][j]=mat[0][j];
        for(int i=1;i<r;i++){
            if(mat[i][j]) cols[i][j]=cols[i-1][j]+1;
        }
    }

    int ans=0;
    for(int i=0;i<r;i++){
        stack<pair<int,int>> st;
        for(int j=0;j<c;j++){
            while(!st.empty() && st.top().first>=cols[i][j]) st.pop();
            if(st.empty()) left[i][j]=cols[i][j]*(j+1);
            else left[i][j]=cols[i][j]*(j-st.top().second);
            st.push({cols[i][j],j});
        }
    }

    for(int i=0;i<r;i++){
        stack<pair<int,int>> st;
        for(int j=c-1;j>-1;j--){
            while(!st.empty() && st.top().first>=cols[i][j]) st.pop();
            if(st.empty()) left[i][j]+=cols[i][j]*(c-j-1);
            else left[i][j]+=cols[i][j]*(st.top().second-j-1);
            st.push({cols[i][j],j});
            ans=max(ans,left[i][j]);
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int t=1; for(int T=0;T<t;T++) solve();
    return 0;
}
