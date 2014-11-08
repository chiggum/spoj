/*
SPOJ Problem Set (classical)
17707. Constructible Regular Polygons
Problem code: POLCONST

The investigation of which regular polygons can be constructed only with compass and straightedge is a classical problem in mathematics. Triangle, square, hexagon can easily be constructed, but, can we construct a regular heptagon? It was the German mathematician Gauss (1777-1855) who first proved that one could construct a 17-sided regular polygon and later, in one the of the most beautiful math works of all time (Disquisitiones Arithmeticae, 1798), he gave sufficient conditions to decide which regular polygons can be constructed.

Input 
In the first line, an integer T<50000 representing the number of test cases; then, T integer numbers representing the number of sides of a non-degenerated regular polygon, up to 1000000 (10^6).
Output 
Print “Yes” if the regular polygon can be constructed with compass and straightedge or “No” otherwise.

Example
Input 
5 
5 
6 
7 
8 
9

Output 
Yes 
Yes 
No 
Yes 
No
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
    s32 T;
    scanl(T);
    s32 fermat[] = {3, 5, 17, 257, 65537};
    s32 i;
    REP(i, T) {
        s32 n;
        scanl(n);
        s32 j;
        REP(j, 5) {
            if(n%fermat[j]==0)
                n=n/fermat[j];
        }
        bool check = false;
        REP(j, 5) {
            if(n%fermat[j]==0)
                check=true;
        }
        if(check || !(n&&(!(n&(n-1)))))
            printf("No\n");
        else
            printf("Yes\n");

        
    }
    return 0;
}