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