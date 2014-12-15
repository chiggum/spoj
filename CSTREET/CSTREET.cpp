/*
SPOJ Problem Set (classical)
368. Cobbled streets
Problem code: CSTREET

The municipal chronicals of an unbelievable lordly major town in a land far, far away tell the following story:
Once upon a time the new crowned king Günther decided to visit all towns in his kingdom. The people of the unbelievable lordly major town expected that king Günther would like to see some of the most famous buildings in their town. For the lordly citizens it seemed neccessary that all streets in the town that the king would have to use had to be cobbled with stone. Unfortunately the unbelievable lordly major town had not much money at that time as they used most of their savings to erect the highest cathedral the world had ever seen.
Roumours were afloat that the real reason for their thriftiness was not that the town treasury was empty but that many people believed that king Günther came to the throne by deceiving his father king Erwin and that in his youth he made a pact with the devil. But anyway, the citizens of the unbelievable lordly major town decided to pave only as much streets as were absolutely necessary to reach every major building.
Can you help the citizens of the unbelievable lordly major town to find out which streets should be paved?
It might be usefull to know that all major buildings are either at the end of a street or at an intersection. In addition to that you can assume that all buildings are connected by the given streets.
Input

t [number of testcases (1 <= t <= 100)]
p [price to pave one furlong of street (positive integer)]
n [number of main buildings in the town (1 <= n <= 1000)]
m [number of streets in the town (1 <= m <= 300000)]
a b c [street from building a to building b with length c (lengths are given in furlong and the buildings are numbered from 1 to n)]
Output

For each testcase output the price of the cheapest possibility to reach all main buildings in the city on paved streets. You can assume that the result will be smaller than 2^32.
Example

Input:
1
2
5
7
1 2 1
2 3 2
2 4 6
5 2 1
5 1 3
4 5 2
3 4 3

Output:
12

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

struct Edge{
	long left, right, len;
};

bool func(Edge a, Edge b) {
	return (a.len < b.len);
}

class Dis_DS{
	private:
		long n;
		long *id, *sz;
	public:
		Dis_DS(long x) {
			n = x;
			id = new long[n];
			sz = new long[n];
			long i;
			REP(i, n) {
				id[i] = i;
				sz[i] = 1;
			}
		}
		long findset(long x_) {
			long x = x_;
			while(id[x]!=x) {
				x = id[x];
			}
			long p = x;
			while(p!=x) {
				long newp = p;
				p = id[p];
				id[p] = x;
				p=newp;
			}
			return x;
		}
		void unite(long x, long y) {
			long ax = findset(x);
			long ay = findset(y);
			if(ax==ay)
				return;
			if(sz[ax]>sz[ay]) {
				id[ay] = ax;
				sz[ax] += sz[ay];
			} else {
				id[ax] = ay;
				sz[ay]+=sz[ax];
			}
			n--;
		}
		bool isConnected(long a, long b) {
			return (findset(a) == findset(b));
		}
		long count() {
			return n;
		}
};

int main() {
	long t, i;
	scanl(t);
	REP(i, t) {
		long p, n, m;
		scanl(p);
		scanl(n);
		scanl(m);
		long j;
		Edge *edge = new Edge[m];
		Dis_DS *vert = new Dis_DS(n);
		REP(j, m) {
			long a, b, c;
			scanl(a);
			scanl(b);
			scanl(c);
			edge[j].left = a-1;
			edge[j].right = b-1;
			edge[j].len = c*p;
		}
		sort (edge, edge+m, func);
		long ans = 0;
		REP(j, m) {
			if(!vert->isConnected(edge[j].left, edge[j].right)) {
				ans+=edge[j].len;
				vert->unite(edge[j].left, edge[j].right);
			}
		}
		printf("%ld\n", ans);
	}
    return 0;
}
