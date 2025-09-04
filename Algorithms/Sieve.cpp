//O(nloglogn)
const int kMaxV=1e6;
int sieve[kMaxV+1];
//Array with the smallest prime that divides i, 0 if i is prime.
void primes(){
  for(int i=4;i<=kMaxV;i+=2) sieve[i]=2;
  for(int i=3;i<=kMaxV/i;i++){
    if(sieve[i]) continue;
    for(int j=i*i;j<=kMaxV;j+=i){
      if(sieve[j]) continue;
      sieve[j]=i;
    }
  }
}

//Vector with all prime factors that divides x (without their exponents)
//logn
vector<int> PrimeFactors(int x){
  if(x==1) return {};
  unordered_set<int> primes;
  while(sieve[x]){
    primes.insert(sieve[x]);
    x/=sieve[x];
  }
  primes.insert(x);
  return {primes.begin(),primes.end()};
}


//linear sieve.
vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}