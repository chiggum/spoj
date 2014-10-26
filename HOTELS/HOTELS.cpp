/*
SPOJ Problem Set (classical)
9861. Hotels Along the Croatian Coast
Problem code: HOTELS
There are N hotels along the beautiful Adriatic coast. Each hotel has its value in Euros.
Sroljo has won M Euros on the lottery. Now he wants to buy a sequence of consecutive hotels, such that the sum of the values of these consecutive hotels is as great as possible - but not greater than M.

You are to calculate this greatest possible total value.
Input
In the first line of the input there are integers N and M (1 ≤ N ≤ 300 000, 1 ≤ M < 231).
In the next line there are N natural numbers less than 106, representing the hotel values in the order they lie along the coast.

Output
Print the required number (it will be greater than 0 in all of the test data).

Example
input
5 12
2 1 3 4 5
output
12
input
4 9
7 3 5 6
output
8
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
    s32 N, M;
    scanl(N);
    scanl(M);
    s32 i;
    s32 val[N];
    REP(i, N) {
        scanl(val[i]);
    }
    s32 start = 0;
    s32 end = 0;
    s32 maxsum = -1;
    s32 sumSoFar = 0;
    while(start < N) {
        if(sumSoFar == M) {
            maxsum = M;
            break;
        } else if(sumSoFar > M) {
            sumSoFar -= val[start];
            start++;
            if(sumSoFar > maxsum && sumSoFar <= M)
                maxsum = sumSoFar;
        } else {
            if(end == N)
                break;
            sumSoFar += val[end];
            end++;
            if(sumSoFar > maxsum && sumSoFar <= M)
                maxsum = sumSoFar;
        }
    }
    printf("%ld\n", maxsum);
    return 0;
}