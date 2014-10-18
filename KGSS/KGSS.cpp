/*
SPOJ Problem Set (classical)
3693. Maximum Sum
Problem code: KGSS

You are given a sequence A[1], A[2], ..., A[N] ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.

U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.

Output
Output the maximum sum mentioned above, in a separate line, for each Query.

Example
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:
7
9
11
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

struct max2 {
    s64 first;
    s64 second;
};

void update_tree(max2 *tree, s64 node, s32 a, s32 b, s32 i, s32 j, s32 value) {
    if(a > b || a > j || b < i)
        return;
    
    if(a==b) {
        tree[node].first = value;
        return;
    }
    s32 mid = (a+b)/2;
    update_tree(tree, 1+node*2, a, mid, i, j, value);
    update_tree(tree, 2+node*2, 1+mid, b, i, j, value);
 
    if(tree[2*node+1].second > tree[2*node+2].first) {
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+1].second;
    } else if(tree[2*node+1].first < tree[2*node+2].second) {
        tree[node].first = tree[2*node+2].first;
        tree[node].second = tree[2*node+2].second;
    } else if(tree[2*node+1].first > tree[2*node+2].first) {
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+2].first;
    } else {
        tree[node].first = tree[2*node+2].first;
        tree[node].second = tree[2*node+1].first;
    }
}

max2 query_tree(max2 *tree, s64 node, s32 a, s32 b, s32 i, s32 j) {    
    if(a > b || a > j || b < i) {
        max2 q;
        q.first = -1;
        q.second = -1;
        return q;
    }

    if(a >= i && b <= j)
        return tree[node];
 
    max2 q1 = query_tree(tree, 1+node*2, a, (a+b)/2, i, j);
    max2 q2 = query_tree(tree, 2+node*2, 1+(a+b)/2, b, i, j);
    max2 q;
    if(q1.second > q2.first) {
        q.first = q1.first;
        q.second = q1.second;
    } else if(q1.first < q2.second) {
        q.first = q2.first;
        q.second = q2.second;
    } else if(q1.first > q2.first) {
        q.first = q1.first;
        q.second = q2.first;
    } else {
        q.first = q2.first;
        q.second = q1.first;
    }
    return q;
}

int main() {
    s32 N;
    scanl(N);
    max2 *arr;
    s64 numElems = 2 * pow(2, ceil(log10(N)/log10(2))) - 1;
    arr = new max2[numElems];
    s32 i, j;
    REP(j, numElems) {
        arr[j].first = -1;
        arr[j].second = -1;
    }
    REP(i, N) {
        s32 x;
        scanl(x);
        update_tree(arr, 0, 0, N-1, i, i, x);
    }
    s32 Q;
    scanl(Q);
    while(Q--) {
        s8 query;
        s32 a, b;
        scanf("%c", &query);
        scanl(a);
        scanl(b);
        a--;
        if(query == 'U') {
            update_tree(arr, 0, 0, N-1, a, a, b);
        } else {
            b--;
            max2 ans = query_tree(arr, 0, 0, N-1, a, b);
            printf("%lld\n", ans.first+ans.second);
        }
    }
    return 0;
}