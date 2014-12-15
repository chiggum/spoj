/*
SPOJ Problem Set (classical)
6818. Capital City
Problem code: CAPCITY

There are N cities in Flatland connected with M unidirectional roads. The cities are numbered from 1 to N. The Flat Circle of Flatland (FCF) wants to set up a new capital city for his kingdom. For security reasons, the capital must be reachable from all other cities of Flatland. FCF needs the list of all candidate cities. You are the chief programmer at FACM (Flat Association for Computing Machinery) responsible for providing the list to FCF as soon as possible.

Input
The first line of the input file contains two integers։ 1≤N≤100,000 and 1≤M≤200,000. Each of the following M lines contains two integers 1≤A, B≤N denoting a road from A to B.
Output 
The output file contains an integer denoting the number of candidate cities followed by the list of candidate cities in increasing order.

Example
Input:

4 4
1 2
3 2
4 3
2 1

Output:
2
1 2
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

struct vertex{
    long id;
    vector<long> nodes;
    long color;
    long conn;
};

vector<long> *connCmp;
vector<long> *dirConnCmp;
long numCC;

stack<long> S;

void dfs_visit(vertex *g, long i, int type) {
    long j;
    REP(j, g[i].nodes.size()) {
        if(g[g[i].nodes[j]].color==0) {
            g[g[i].nodes[j]].color=1;
            if(type) {
                g[g[i].nodes[j]].conn = g[i].conn;
            }
            dfs_visit(g, g[i].nodes[j], type);
        }
    }
    if(type==0)
        S.push(i);
}
void dfs(vertex *g, long n, int type) {
    long i;
    if(type == 0) {
        REP(i, n) {
            if(g[i].color == 0) {
                g[i].color = 1;
                dfs_visit(g, i, type);
            }
        }
    } else{
        long count = 0;
        while(!S.empty()) {
            i = S.top();
            S.pop();
            if(g[i].color == 0) {
                g[i].color = 1;
                g[i].conn = count++;
                dfs_visit(g, i, type);
            }
        }
        numCC = count;
    }
}

int main() {
    long n, m;
    scanl(n);
    scanl(m);
    vertex *g, *gT;
    connCmp = new vector<long>[n];
    dirConnCmp = new vector<long>[n];
    g = new vertex[n];
    gT = new vertex[n];
    long i;
    REP(i, n) {
        g[i].id = i;
        gT[i].id = i;
        g[i].color = gT[i].color = 0;
    }
    REP(i, m) {
        long a, b;
        scanl(a);
        scanl(b);
        a--;
        b--;
        g[a].nodes.push_back(b);
        gT[b].nodes.push_back(a);
    }

    dfs(g, n, 0);
    dfs(gT, n, 1);

    long *in = new long[numCC];
    REP(i, numCC) {
        in[i] = 0;
    }
    REP(i, n) {
        long j;
        REP(j, g[i].nodes.size()) {
            if(gT[i].conn != gT[g[i].nodes[j]].conn) {
                in[gT[i].conn] += 1;
            }
        }
    }

    long cnt = 0;
    REP(i, numCC) {
        if(in[i] == 0)
            ++cnt;
    }

    if(cnt == 1) {
        long num = 0;
        REP(i, n) {
            if(in[gT[i].conn]==0)
                ++num;
        }
        printf("%ld\n", num);
        REP(i, n) {
            if(in[gT[i].conn]==0) {
                printf("%ld ", i+1);
            }
        }
        printf("\n");
    } else {
        printf("0\n");
    }
    return 0;
}