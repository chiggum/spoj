/*
SPOJ Problem Set (classical)
61. Brackets
Problem code: BRCKTS

We will call a bracket word any word constructed out of two sorts of characters: the opening bracket "(" and the closing bracket ")". Among these words we will distinguish correct bracket expressions. These are such bracket words in which the brackets can be matched into pairs such that every pair consists of an opening bracket and a closing bracket appearing further in the bracket word
for every pair the part of the word between the brackets of this pair has equal number of opening and closing brackets
On a bracket word one can do the following operations:
replacement -- changes the i-th bracket into the opposite one
check -- if the word is a correct bracket expression
Task
Write a program which
reads (from standard input) the bracket word and the sequence of operations performed,
for every check operation determines if the current bracket word is a correct bracket expression,
writes out the outcome (to standard output).
Input
Ten test cases (given one under another, you have to process all!). Each of the test cases is a series of lines. The first line of a test consists of a single number n (1<=n<=30000) denoting the length of the bracket word. The second line consists of n brackets, not separated by any spaces. The third line consists of a single number m -- the number of operations. Each of the following m lines carries a number k denoting the operation performed. k=0 denotes the check operation, k>0 denotes replacement of k-th bracket by the opposite.

Output
For every test case your program should print a line:
Test i:
where i is replaced by the number of the test and in the following lines, for every check operation in the i-th test your program should print a line with the word YES, if the current bracket word is a correct bracket expression, and a line with a word NO otherwise. (There should be as many lines as check operations in the test.)

Example
Input:
4
()((
4
4
0
2
0
[and 9 test cases more]
Output:
Test 1:
YES
NO
[and 9 test cases more]
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

struct paren {
    s32 sum;
    s32 minsum;
};

void update_tree(paren *tree, s64 node, s32 a, s32 b, s32 i, s32 j, s32 value) {
    if(a > b || a > j || b < i)
        return;
    
    if(a==b) {
        tree[node].sum=tree[node].minsum=value*tree[node].sum;
        return;
    }
    s32 mid = (a+b)/2;
    update_tree(tree, 1+node*2, a, mid, i, j, value);
    update_tree(tree, 2+node*2, 1+mid, b, i, j, value);

    tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
    tree[node].minsum = min(tree[2*node+1].minsum, tree[2*node+1].sum+tree[2*node+2].minsum);
}

int main() {
    s32 iter=10,T=10;
    while(T--) {
        s32 n;
        scanl(n);
        string inp;
        cin >> inp;
        s64 numElems = 2 * pow(2, ceil(log10(n)/log10(2))) - 1;
        paren *tree = new paren[numElems];
        s64 i;
        REP(i, numElems) {
            tree[i].sum=tree[i].minsum=1;
        }
        REP(i, n){
            if(inp[i]=='(') {
                update_tree(tree, 0, 0, n-1, i, i, 1);
            } else {
                update_tree(tree, 0, 0, n-1, i, i, -1);
            }
        }
        printf("Test %ld:\n", iter-T);
        s32 C;
        scanl(C);
        s32 j;
        REP(j, C) {
            s32 q;
            scanl(q);
            if(q != 0) {
                q--;
                update_tree(tree, 0, 0, n-1, q, q, -1);
            } else {
                paren ans = tree[0];
                if(ans.sum == 0 && ans.minsum ==0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
}