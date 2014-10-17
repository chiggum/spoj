/*
SPOJ Problem Set (classical)
6256. Inversion Count
Problem code: INVCNT
Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1
Output: 
2
5
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

#define INFINITY 10000001

s64 modifMerge(s32 *arr, s32 a, s32 mid, s32 b) {
    s32 n1 = mid - a + 1;
    s32 n2 = b - mid;
    s32 *l = new s32[n1+1];
    s32 *m = new s32[n2+1];
    s32 i;
    s64 invcnt = 0;
    REP(i, n1) {
        l[i] = arr[a+i];
    }
    REP(i, n2) {
        m[i] = arr[mid + 1 + i];
    }
    l[n1] = INFINITY;
    m[n2] = INFINITY;
    s32 j=0,k=0;
    rep(i, a, b+1) {
        if(l[j] < m[k]) {
            arr[i]=l[j++];
        } else {
            arr[i]=m[k++];
            invcnt += n1 - j;
        }
    }
    return invcnt;
}

s64 modifMergeSort(s32 *arr, s32 a, s32 b) {
    s64 invcnt = 0;
    if(a < b) {
        s32 mid = (a+b)/2;
        s64 invcnt1 = modifMergeSort(arr, a, mid);
        s64 invcnt2 = modifMergeSort(arr, mid + 1, b);
        invcnt = modifMerge(arr, a, mid, b);
        invcnt += invcnt1 + invcnt2;
    }
    return invcnt;
}

int main() {
    s32 T;
    scanl(T);
    while(T--) {
        s32 N;
        scanl(N);
        s32 *arr = new s32[N];
        s32 i;
        REP(i, N) {
            scanl(arr[i]);
        }
        s64 invcnt = modifMergeSort(arr, 0, N-1);
        printf("%lld\n", invcnt);
    }
}