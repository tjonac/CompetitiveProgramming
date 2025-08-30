#include<bits/stdc++.h>
using namespace std;


int x[400000] = {1000000001};
int k; //k is the least exp of 2 st 1<<k>=n
//sets b in pos a
void update(int a, int b) 
{
  a += (1<<k);
  x[a] = b;
  for (a /= 2; a >= 1; a /= 2)
  {
    x[a] = min(x[a * 2], x[a * 2 + 1]);
  }
}
//Find range a,b inclusive
int find(int a, int b)
{
  a += (1<<k);
  b += (1<<k);
  int s = 1000000000;
  while (a <= b)
  {
    if (a % 2 == 1)
      s = min(s, x[a++]);
    if (b % 2 == 0)
      s = min(s, x[b--]);
    a /= 2;
    b /= 2;
  }
  return s;
}
//segtree struct with associativity operation +.
template <typename num_t>
struct segtree
{
  int n, k;
  vector<num_t> tree;

  void init(int s, vector<pair<ll,ll>> arr)
  {
    n = s;
    k = 0;
    while ((1 << k) < n) k++;
    tree = vector<num_t>(2 * (1 << k) + 1);
    for (int i = 0; i < n; i++)
    {
      tree[(1 << k) + i] = num_t(arr[i].first,arr[i].second);
    }
    for (int i = (1 << k) - 1; i > 0; i--)
    {
      tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
  }

  void update(int a, pair<ll,ll> b)
  {
    a += (1 << k);
    tree[a] = num_t(b.first,b.second);
    for (a /= 2; a >= 1; a /= 2)
    {
      tree[a] = tree[a * 2] + tree[a * 2 + 1];
    }
  }

  num_t find(int a, int b)
  {
    queue<num_t> q;
    stack<num_t> qst;
    a += (1 << k);
    b += (1 << k);
    num_t s;
    while (a <= b)
    {
      if (a % 2 == 1)
        qst.push(tree[a++]);
      if (b % 2 == 0)
        q.push(tree[b--]);
      a /= 2;
      b /= 2;
    }
    while(!q.empty()){
      s=q.front()+s;
      q.pop();
    }
    while(!qst.empty()){
      s=qst.top()+s;
      qst.pop();
    }
    return s;
  }
};