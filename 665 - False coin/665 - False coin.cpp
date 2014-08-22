//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 665 - False coin
// Verdict: 
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

int coin[105];
int n,k,m;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("665 - False coin.INP","r",stdin);
    freopen("665 - False coin.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    fr(t,1,tcs)
    {
        if(t != 1) puts("");
        read2(n,k);
        
        fr(i,1,n) coin[i] = 1000;
        
        rep(i,k)
        {
            read(m);
            
            vi a,b;
            rep(j,m)
            {
                int x;
                read(x);
                a.pb(x);
            }
            
            rep(j,m)
            {
                int x;
                read(x);
                b.pb(x);
            }
            char c;
            read(c);
            
            if(c == '=')
            {
                rep(i,sz(a))
                    coin[a[i]] = coin[b[i]] = min(coin[a[i]],coin[b[i]]);
            }
            else if(c == '<')
            {
                rep(i,sz(a))
                    coin[a[i]] = coin[b[i]] - 1;
            }
            else if(c == '>')
            {
                rep(i,sz(a))
                    coin[b[i]] = coin[a[i]] - 1;
            }
            //DEBUG(c);
        }
        
        if(n == 2)
        {
            puts("0");
            continue;
        }
        
        bool ok[2005];
        int ans = 0;
        int val = -INF;
        int same = 0;
        fr(i,0,2000) ok[i] = false;
        int dif = 0;
        
        fr(i,1,n)
        {
            //DEBUG(coin[i]);
            
            if(!ok[coin[i]])
            {
                dif++;
                ok[coin[i]] = true;
            }
            
            if(coin[i] > val)
            {
                val = coin[i];
                ans = i;
                same = 1;
            }
            else if(coin[i] == val)
                same++;
            //DEBUG(same);
        }
        //DEBUG(dif);
        //DEBUG(same);
        if(same != 1 || dif != 2)
        {
            puts("0");
        }
        else printf("%d\n",ans);
    }
    
    return 0;
}
