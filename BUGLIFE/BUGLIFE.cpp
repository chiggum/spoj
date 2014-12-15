/*
SPOJ Problem Set (classical)
3377. A Bug’s Life
Problem code: BUGLIFE

Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs.

Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
Input

The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.
Output

The output for every scenario is a line containing “Scenario #i:”, where i is the number of the scenario starting at 1, followed by one line saying either “No suspicious bugs found!” if the experiment is consistent with his assumption about the bugs’ sexual behavior, or “Suspicious bugs found!” if Professor Hopper’s assumption is definitely wrong.
Example

Input:
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4


Output:
Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found!
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
    long t, i;
    scanl(t);
    REP(i, t) {
        long n, m, j;
        scanl(n);
        scanl(m);
        vector<long> *bug = new vector<long>[n];
        long *gender = new long[n];
        REP(j, n) {
            gender[j]=-1;
        }
        REP(j, m) {
            long a, b;
            scanl(a);
            scanl(b);
            a--;
            b--;
            bug[a].push_back(b);
            bug[b].push_back(a);
        }
        long iter;
        bool susp = false;
        REP(iter, n) {
            queue<long> Q;
            if(gender[iter]==-1) {
                Q.push(iter);
                gender[iter] = 0;
            }
            
            while(!Q.empty()) {
                long x = Q.front();
                Q.pop();
                long k;
                long curGender = gender[x];
                REP(k, bug[x].size()) {
                    if(gender[bug[x][k]]==-1) {
                        gender[bug[x][k]] = 1-curGender;
                        Q.push(bug[x][k]);
                    } else if(gender[bug[x][k]]==curGender) {
                        susp = true;
                        break;
                    }
                }
                if(susp)
                    break;
            }
            if(susp)
                break;
        }
        if(susp){
            printf("Scenario #%ld:\nSuspicious bugs found!\n", i+1);
        } else {
            printf("Scenario #%ld:\nNo suspicious bugs found!\n", i+1);
        }
        
    }
    return 0;
}