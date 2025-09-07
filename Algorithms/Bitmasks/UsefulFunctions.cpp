#include<bits/stdc++.h>
using namespace std;

int a,bit=__builtin_clz(a); //count the number of leading zeros in a integer a;
int ones = __builtin_popcount(a); // count the number of ones on a
