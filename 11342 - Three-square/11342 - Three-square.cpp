//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11342 - Three-square
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
#define sz(s) (int)s.size()
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



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11342 - Three-square.INP","r",stdin);
    freopen("11342 - Three-square.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    rep(t,tcs)
    {
        int n;
        read(n);
        bool ok = true;
        bool ans = false;
        for(int i = 0 ; i <= 233 && ok ; i++)
        {
            for(int j = i ; j <= 233 ; j++)
            {
                //DEBUG(i);
                //DEBUG(j);
                int k = i*i + j*j;
                if(k > n)
                    break;
                
                k = n - k;
                
                if(j*j > k)
                    break;
                
                int tmp = sqrt(k);
                //DEBUG(k);
                if(tmp * tmp == k)
                {
                    printf("%d %d %d\n",i,j,tmp);
                    ans = true;
                    ok = false;
                    break;
                }
                
            }
        }
        
        if(!ans) puts("-1");
    }
    
    return 0;
}
