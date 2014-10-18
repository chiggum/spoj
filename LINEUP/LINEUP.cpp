/*
SPOJ Problem Set (classical)
6828. Lineup
Problem code: LINEUP

On June 13th team Germany has its first match in the FIFA world cup against team Australia. As the coach of team Germany, it is your duty to select the lineup for the game. Given this is your first game in the cup, naturally you want to make a good impression. Therefore you'd like to play with the strongest lineup possible.
 
You have already decided on the tactical formation you wish to use, so now you need to select the players who should fill each of the 11 positions in the team. Your assistant has selected the 11 strongest players from your squad, but this still leaves the question where to put which player.

Most players have a favoured position on the field where they are strongest, but some players are proficient in different positions. Your assistant has rated the playing strength of each of your 11 players in each of the 11 available positions in your formation, where a score of 100 means that this is an ideal position for the player and a score of 0 means that the player is not suitable for that position at all. Find the lineup which maximises the sum of the playing strengths of your players for the positions you assigned them. All positions must be occupied, however, do not put players in positions they are not proficient with (i.e.\ have a score of 0).

Input
The input consists of several test cases. The first line of input contains the number C of test cases. For each case you are given 11 lines, one for each player, where the i-th line contains 11 integer numbers sij between 0 and 100. sij describes the i-th player's strength on the j-th position. No player will be proficient in more than five different positions.

Output
For each test case output the maximum of the sum of player strengths over all possible lineups. Each test case result should go on a separate line. There will always be at least one valid lineup.

Example
Input:
1
100 0 0 0 0 0 0 0 0 0 0
0 80 70 70 60 0 0 0 0 0 0
0 40 90 90 40 0 0 0 0 0 0
0 40 85 85 33 0 0 0 0 0 0
0 70 60 60 85 0 0 0 0 0 0
0 0 0 0 0 95 70 60 60 0 0
0 45 0 0 0 80 90 50 70 0 0
0 0 0 0 0 40 90 90 40 70 0
0 0 0 0 0 0 50 70 85 50 0
0 0 0 0 0 0 66 60 0 80 80
0 0 0 0 0 0 50 50 0 90 88

Output:
970
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

#define INFINITY 100000
#define N 11
s32 cost[N][N];
s32 store[N][1<<11];

s32 dpLineUp(s32 pos, s32 mask) {
    if(pos == 11) {
        if(mask != (1<<11)-1)
            return -INFINITY;
        else
            return 0;
    }
    if(store[pos][mask] > -1)
        return store[pos][mask];
    store[pos][mask] = -INFINITY;
    s32 i;
    REP(i, N) {
        if(cost[pos][i] && !(mask&(1<<i))) {
            s32 val = cost[pos][i] + dpLineUp(pos+1, mask|(1<<i));
            store[pos][mask] = max(store[pos][mask], val);
        }
    }
    return store[pos][mask];
}

int main() {
    s32 T;
    scanl(T);
    while(T--) {
        s32 i, j;
        REP(i, N) {
            REP(j, N) {
                scanl(cost[i][j]);   
            }
        }
        memset(store, -1, sizeof(store));
        printf("%ld\n", dpLineUp(0, 0));
    }
    return 0;
}