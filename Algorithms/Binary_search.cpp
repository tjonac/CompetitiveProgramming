#include<bits/stdc++.h>
using namespace std;
#define ll long long

//returns upper_bound for a non decreasing vector
int bin_search(int target,vector<int>& a, int l, int r){
  int res=-1;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(a[mid]<=target){
      l=mid+1;
    }
    else{
      res=mid;
      r=mid-1;
    }
  }
  return res;
}
//returns lower_bound for a non decreasing vector
int bin_search(int target,vector<int>& a, int l, int r){
  int res=-1;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(a[mid]<target){
      l=mid+1;
    }
    else{
      res=mid;
      r=mid-1;
    }
  }
  return res;
}
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
//Binary search on the answer (11...10..0)
bool check(int l, int r,int k, vector<vector<int>>& prefix){
  int s=0;
  for(int i=0;i<31;i++){
    if((prefix[r][i]-prefix[l-1][i])==r-l+1) s+=(1<<i);
  }
  if(s>=k) return 1;
  else return 0;
}
int bin_search(int a,int k, vector<vector<int>>& prefix){
  int l=a, r=prefix.size()-1,res=-1;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(check(a,mid,k,prefix)){
      res=mid;
      l=mid+1;
    }
    else r=mid-1;
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