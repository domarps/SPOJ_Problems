#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <limits>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }  
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

int main()
{
   int n;
   int gameId = 1;
   while(scanf("%d",&n))
   {
      if(n == 0) break;
      vector<int> card(n);
      int sum = 0;
      for(int i = 0; i < n; i++)
      {
         scanf("%d",&card[i]);
         sum += card[i];
      }
      vector<vector<int> > dp(n,vector<int>(n,0));
      for(int i = 0; i < n; i++)
      {
         dp[i][i] = card[i];
      }
      for(int len = 2; len <= n; len++)
      {
         for(int i = 0; i <= n-len; i++)
         {
            int j = i+len-1;
            if(len == 2)
            {
               dp[i][j] = max(card[i],card[j]);
            }
            else
            {
               dp[i][j] = max(card[i] + min(dp[i+2][j],dp[i+1][j-1]),card[j] + min(dp[i+1][j-1],dp[i][j-2]));
            }
         }
      }
      cout << "In game "<< gameId << ", the greedy strategy might lose by as many as " << (2 * dp[0][n-1] - sum) <<" points." << endl;
      gameId++;
   }
   return 0;
}