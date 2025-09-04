#include<bits/stdc++.h>
using namespace std;

//Disjoint set union implementation.
const int NMAX=2e6;
int parent[NMAX],sz[NMAX];

void make_set(int v) { //O(1)
  parent[v] = v;
  sz[v] = 1;
}

int find_set(int v) { //O(logn)
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) { //O(logn)
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b])
      swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
  }
}