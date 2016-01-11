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
   int scenarios;
   scanf("%d",&scenarios);
   int s = 1;
   while(s <= scenarios)
   {
      long long stamps;
      long long friends;
      cout << "Scenario #" << s << ":" << endl;
      scanf("%lld %lld",&stamps,&friends);
      cout << stamps << ' ' << friends << endl;
      vector<long long> offer(friends);
      for(int i = 0; i < stamps; i++)
      {
         scanf("%lld",&offer[i]);
      }
      sort(offer.begin(),offer.end(),greater<long long>());
      long long i = 0;
      cout << stamps << ' ' << friends << ' '<< offer[i] << endl;
      while(stamps > 0 && i < friends)
      {
         cout << stamps << ' ' << offer[i] << ' ' << i << endl;
         stamps -= offer[i++];
      }
      cout << stamps << ' ' << i << endl;
      if(i == friends)
      {
         cout << "impossible" << endl;
      }
      else
      {
         cout << i << endl;
      }
      cout << "---------------------------------------" << endl;
      s++;
   }
   return 0;
}