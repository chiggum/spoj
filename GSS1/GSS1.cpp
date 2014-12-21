/*
SPOJ Problem Set (classical)

1043. Can you answer these queries I

Problem code: GSS1

You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows: 
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
Given M queries, your program must output the results of these queries.

Input

The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output

Your program should output the results of the M queries, one query per line.
Example

Input:
3 
-1 2 3
1
1 2
Output:
2
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


void build_tree(s32 *tree, s32 node, s32 s, s32 e, s32 *arr) {
	if(s>e)
		return;
	if(s==e) {
		tree[node] = arr[s];
		return;
	}
	build_tree(tree, node*2+1, s, (s+e)/2, arr);
	build_tree(tree, node*2+2, (s+e)/2+1, e, arr);
	tree[node] = tree[node*2+1]+tree[node*2+2];
}

s32 get_max_sum(s32 *tree, s32 i, s32 j, s32 st, s32 en) {
	if(i>j || )
}

int main() {
	s32 N;
	scanl(N);
	s32 numElem = 2 << ceil(log2(N)) - 1;
	s32 *tree = new s32[numElem], *arr = new s32[N];
	s32 i;
	REP(i, N) {
		scanl(arr[i]);
	}
	build_tree(tree, 0, 0, N-1, arr);
	s32 M;
	scanl(M);
	REP(i, M) {
		s32 x, y;
		scanl(x);
		scanl(y);
	}
    return 0;
}