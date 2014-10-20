/*
SPOJ Problem Set (classical)
21357. Crucial Equation
Problem code: CEQU

Let us see the following equation,
             ax+by=c

Given three positive integers a, b and c. You have to determine whether there exists at least one solution for some integers value of x and y where x, y may be negative or non-negative integers.
For example if a=2, b=4 and c=8 then the equation will be 2x+4y=8, and hence, for x=2 and y=1, there exists a solution.
Let us see another example for a=3, b=6 and c=7, so the equation will become 3x+6y=7 and there exists no solution satisfying this equation.

Input
Input starts with an integer T (1<=T<=105) denoting the number of test cases. Each test case contains three integers a, b, and c. (1<=a, b, c<=106).

Output
For each test case of input print the case number and “Yes” if there exists at least one solution, print “No” otherwise.

2
2 4 8
3 6 7

Case 1: Yes
Case 2: No
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

s32 GCD(s32 a, s32 b) {
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main() {
    s32 T, iter;
    scanl(T);
    iter = T;
    while(T--) {
        s32 a, b, c;
        scanl(a);
        scanl(b);
        scanl(c);
        s32 gcd = GCD(a,b);
        if(c%gcd == 0)
            printf("Case %ld: Yes\n", iter-T);
        else
            printf("Case %ld: No\n", iter-T);
    }
    return 0;
}