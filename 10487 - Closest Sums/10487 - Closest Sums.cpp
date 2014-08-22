//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10487 - Closest Sums
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int n,m;
int a[1005];
vi v;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10487 - Closest Sums.INP","r",stdin);
    freopen("10487 - Closest Sums.OUT","w",stdout);
    #endif
    int tcs = 1;
    while(read(n) && n)
    {
        printf("Case %d:\n",tcs++);
        v.clear();
        rep(i,n) read(a[i]);
        
        for(int i = 0 ; i < n-1 ; i++)
            for(int j = i + 1 ; j < n ; j++)
                v.pb(a[i] + a[j]);
                
        sort(all(v));
        
        vi::iterator it;
        
        read(m);
        rep(i,m)
        {
            int x;
            read(x);
            it = lower_bound(all(v),x);
            
            int ans = *it;
            int u = *(it+1);
            int k = *(it-1);
            
            //DEBUG(u);
            //DEBUG(v);
            
            if(((it+1) != v.end()) && abs(ans - x) > abs(u - x)) ans = u;
            else if(it != v.begin() && abs(ans-x) > abs(k - x)) ans = k;
            
            //cout << *it << endl;
            printf("Closest sum to %d is %d.\n",x,ans);
        }
    }
    
    return 0;
}
