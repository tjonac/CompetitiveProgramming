//returns the index of the first element less than target, when sorted extricly decreasing
int bin_search(int target,vector<int>& a){
  int l=0, r=a.size()-1,res=-1;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(a[mid]==target) return mid;
    if(a[mid]<target){
      r=mid-1;
      res=mid;
    }
    else l=mid+1;
  }
  return res;
}
//returns the biggest value n st f(n)<target, when f is supposed increasing
ll f(ll n){
  return n*(n-1)/2;
}
ll bin_search(ll target){
  ll l=1, r=4*target+1,res=-1;
  while(l<=r){
    ll mid=l+(r-l)/2;
    if(f(mid)==target) return mid;
    if(f(mid)<target){
      l=mid+1;
      res=mid;
    }
    else r=mid-1;
  }
  return res;
}