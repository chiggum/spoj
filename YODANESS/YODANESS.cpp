/*
SPOJ Problem Set (classical)
6294. Yodaness Level
Problem code: YODANESS
Yoda is the wisest, and perhaps the most powerful Jedi of his time. Yoda is a mysterious figure and he has many oddities. One of them is that Yoda often changes the order of words in the sentence. For example, one of such phrases is "Or I will help you not." Let's call the yodaness level of any statement the number of pairs of words that changed their order, as to the order in which they were supposed to go in a normal statement. Write a program that determines the yodaness level of different statement of Yoda.

Input
The first line of input contains the number t - the number of tests. Next comes the description of t tests. Each test consists of three rows. The first line of the test contains an integer n - number of words in the statement. The next line contains n words separated by spaces - the statement as Yoda says it. The next line is n words separated by spaces - the same statement as it should be said normally. All the words in the statement are different and consist of small latin letters.
Constraints
1 <= t <= 10
1 <= n <= 30000
the length of each word does not exceed 20 characters

Output
For each test print the yodaness level of the statement.

Example
Input:
2
6
in the force strong you are
you are strong in the force
6
or i will help you not
or i will not help you

Output:
11
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

#define INFINITY 30005

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
        string *sarr = new string[N];
        map<string, int> smap;
        s32 i;
        REP(i, N) {
            cin >> sarr[i];
        }
        REP(i, N) {
            string x;
            cin >> x;
            smap[x] = i;
        }
        REP(i, N) {
            arr[i]=smap[sarr[i]];
        }
        s64 invcnt = modifMergeSort(arr, 0, N-1);
        printf("%lld\n", invcnt);
    }
}