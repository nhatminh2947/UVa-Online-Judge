//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 612 - DNA Sorting
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
#define sz(s) s.size()
#define read(x) scanf("%d",&x)
#define read2(x,y) scanf(" %d %d ",&x,&y)
#define read3(x,y,z) scanf(" %d %d %d ",&x,&y,&z)
#define out(x) printf("%d",x)
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

int tcs;
int n,m;
pair<string,int> p[105];

int main()
{
    freopen("612 - DNA Sorting.INP","r",stdin);
    freopen("612 - DNA Sorting.OUT","w",stdout);

    read(tcs);
    
    rep(t,tcs)
    {
        if(t) printf("\n");
        read2(n,m);
        rep(j,m)
        {
            cin >> p[j].ff;
            p[j].ss = 0;
            rep(u,n-1)
                for(int v = u+1 ; v < n ; v++)
                    if(p[j].ff[u] > p[j].ff[v])
                        p[j].ss++;
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            int pp;
            int k = INF;
            for(int j = i ; j < m ; j++)
                if(k > p[j].ss)
                {
                    pp = j;
                    k = p[j].ss;
                }
            for(int j = pp ; j > i ; j--)
                swap(p[j],p[j-1]);
        }
        
        rep(j,m)
            cout << p[j].ff << endl;
    }

    return 0;
}