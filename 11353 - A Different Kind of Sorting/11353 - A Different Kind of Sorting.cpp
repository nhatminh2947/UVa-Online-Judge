//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11353 - A Different Kind of Sorting
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
#define maxN 2000000

bool check[maxN+5];
ii a[maxN+5];
int n;

bool cmp(ii u, ii v)
{
    if(u.ss == v.ss) return u.ff < v.ff;
    return u.ss < v.ss;
}

void sieve()
{
    rep(i,maxN+1)
    {
        check[i] = true;
        a[i].ff = i;
    }
    a[1].ss = 0;
    
    for(ll i = 2 ; i <= maxN ; i++)
        if(check[i])
        {
            for(ll j = i ; j <= maxN ; j+=i)
            {
                check[j] = false;
                a[j].ss = a[j/i].ss + 1;
            }
        }
        
    sort(a+1,a+maxN+1,cmp);
}

int main()
{
    freopen("11353 - A Different Kind of Sorting.INP","r",stdin);
    freopen("11353 - A Different Kind of Sorting.OUT","w",stdout);

    sieve();
    int tcs = 1;
    while(scanf(" %d ",&n) && n)
    {
        printf("Case %d: %d\n",tcs++,a[n].ff);
    }

    return 0;
}