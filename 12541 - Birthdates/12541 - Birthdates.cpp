//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12541 - Birthdates
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
typedef pair< pair<string,int> , ii> psii;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

psii p[105];

bool cmp(psii u, psii v)
{
    if(u.ss.ss == v.ss.ss)
    {
        if(u.ss.ff == v.ss.ff) return u.ff.ss < v.ff.ss;
        return u.ss.ff < v.ss.ff;
    }
    return u.ss.ss < v.ss.ss;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12541 - Birthdates.INP","r",stdin);
    freopen("12541 - Birthdates.OUT","w",stdout);
    #endif
    
    int n;
    read(n);
    
    rep(i,n)
    {
        read(p[i].ff.ff);
        scanf("%d %d %d",&p[i].ff.ss,&p[i].ss.ff,&p[i].ss.ss);
    }
    
    sort(p,p+n,cmp);
    cout << p[n-1].ff.ff << endl;
    cout << p[0].ff.ff << endl;
    
    return 0;
}
