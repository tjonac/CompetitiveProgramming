vector<ll> factorial(1e6);

ll inv(ll a) {
  return a <= 1 ? a : mod- (long long)(mod/a) * inv(mod % a) % mod;
}
ll bin(int n, int k) {
  if(k>n) return 0;
  if(k==n) return 1;
  return factorial[n]*inv(factorial[k])%mod*inv(factorial[n - k]) % mod;
}
