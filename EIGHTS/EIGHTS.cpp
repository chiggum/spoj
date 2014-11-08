/*
SPOJ Problem Set (classical)
1030. Triple Fat Ladies
Problem code: EIGHTS

Pattern Matchers have been designed for various sorts of patterns. Mr. HKP likes to observe patterns in numbers. After completing his extensive research on the squares of numbers, he has moved on to cubes. Now he wants to know all numbers whose cube ends in 888.

Given a number k, help Mr. HKP find the kth number (indexed from 1) whose cube ends in 888.

Input
The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of a single line containing a single integer k (1 <= k <= 2000000000000).

Output
For each test case, output a single integer which denotes the kth number whose cube ends in 888. The result will be less than 263.

Example
Input:
1
1

Output:
192
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

int main() {
    s64 T;
    scanll(T);
    s64 i;
    REP(i, T) {
        s64 k;
        scanll(k);
        s32 ans;
        if((k-1)%4==0) {
            ans = 192;
        } else if((k-1)%4==1) {
            ans = 442;
        } else if((k-1)%4==2) {
            ans = 692;
        } else {
            ans = 942;
        }
        if(k <= 4) {
            printf("%ld\n", ans);
        } else {
            printf("%lld%ld\n", (k-1)/4, ans);
        }
    }
    return 0;
}