/*
SPOJ Problem Set (classical)
8002. Horrible Queries
Problem code: HORRIBLE
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -

* 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
* 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)

Input
In the first line you'll be given T, number of test cases.
Each test case will start with N (N<=100 000) and C (C<=100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p,q <= N and 1 <= v <= 10^7.

Output
Print the answers of the queries.
Example
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8

Output:
80
508
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#define rep(i, a, b) for(i = (a); i < (b); ++i)
#define REP(i, a) rep(i, 0, a)

#define gc getchar_unlocked

inline void scani(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

inline void scanl(long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

inline void scanll(long long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

using namespace std;

typedef char s8;
typedef unsigned char u8;
typedef long s32;
typedef unsigned long u32;
typedef long long s64;
typedef unsigned long long u64;

inline int toInt(string s) {int i;stringstream (s)>>i;return i;}
inline string toString(int i) {string s;stringstream ss;ss<<i;ss>>s;return s;}

void update_tree(s64 *tree, s64* lazy, s64 node, s32 a, s32 b, s32 i, s32 j, s32 value) {
	if(a > b || a > j || b < i)
		return;
    
    if(a >= i && b <= j) {
    	lazy[node]+=value;
    	return;
    }
    s32 mid = (a+b)/2;
	update_tree(tree, lazy, 1+node*2, a, mid, i, j, value);
	update_tree(tree, lazy, 2+node*2, 1+mid, b, i, j, value);
 
	tree[node] = tree[node*2+1]+tree[node*2+2] + (mid-a+1)*lazy[2*node+1] + (b-mid)*lazy[2*node+2];
}

s64 query_tree(s64 *tree, s64 *lazy, s64 node, s32 a, s32 b, s32 i, s32 j) {	
	if(a > b || a > j || b < i)
		return 0;

	s64 ret = (min(b,j)-max(a,i)+1)*lazy[node];

	if(a >= i && b <= j)
		return ret+tree[node];
 
	s64 q1 = query_tree(tree, lazy, 1+node*2, a, (a+b)/2, i, j);
	s64 q2 = query_tree(tree, lazy, 2+node*2, 1+(a+b)/2, b, i, j);

	s64 res = ret + q1 + q2;
	return res;
}

int main() {
	s64 T;
	s64 t;
	scanll(T);
	REP(t, T) {
		s32 N;
		s32 C;
		s32 i, n;
		scanl(N);
		scanl(C);
		s64 numElems = 2 * pow(2, ceil(log10(N)/log10(2))) - 1;
		s64 *myArray = new s64[numElems];
		s64 *lazy = new s64[numElems];
		memset(lazy, 0, numElems * sizeof(s64));
		memset(myArray, 0, numElems * sizeof(s64));
		REP(n, C) {
			s32 type, a, b, v;
			scanl(type);
			scanl(a);
			scanl(b);
			a--;
			b--;
			if(type == 0) {
				scanl(v);
				update_tree(myArray, lazy, 0, 0, N-1, a, b, v);
			} else {
				u64 sum;
				sum=query_tree(myArray, lazy, 0, 0, N-1, a, b);
				printf("%lld\n", sum);
			}
		}
	}
	return 0;
}