#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 998244353
struct sum_t{
  ll val;
  static const long long null_v = 0;

  sum_t(): val(null_v) {}
  sum_t(long long v): val(v) {}

  sum_t operator + (const sum_t &a) const {
    sum_t ans;
    ans.val = val + a.val;
    return ans;
  }
};

//linear function f=ax+b
struct linear_f{
  ll a,b;
  linear_f(){
    a=1; b=0;
  }
  linear_f(ll x, ll y){
    a=x; b=y;
  }
  linear_f operator + (const linear_f &g) const {
    linear_f ans;
    ans.a=((a*g.a)%MOD+MOD)%MOD;
    ans.b=((a*g.b%MOD+b)%MOD+MOD)%MOD;
    return ans;
  }

  ll eval(ll x){
    return ((inv(a)*x-b*inv(a))%MOD+MOD)%MOD;
  }
  ll inv(ll a) {
    a%=MOD;
    return a <= 1 ? a : MOD- (long long)( MOD/a) * inv(MOD % a) % MOD;
  }

};