//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
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
#define maxN 100000



int main()
{
    freopen("H.INP","r",stdin);
    freopen("H.OUT","w",stdout);

    int tcs;
    read(tcs);
    rep(t,tcs)
    {
        string s;
        cin >> s;
        
        if(s[0] == 'W' || s[sz(s)-1] == 'B')
        {
            puts("IMPOSSIBLE");
            continue;
        }
        
        vector<int> b,w;
        int cnt = 0;
        rep(i,sz(s))
        {
            if(s[i] == 'W') w.pb(i+1);
            else b.pb(i+1);
        }
        rep(i,sz(s)-1)
            if(s[i] == 'B' && s[i+1] == 'W')
                cnt++;
        if(cnt == 1)
        {
            puts("1");
            printf("%d",sz(s));
            rep(i,sz(s))
                printf(" %d",i+1);
            printf("\n");
        }
        else
        {
            puts("2");
            vector<int> v;
            int i,j;
            i = j = 0;
            while(b[i] < w[0])
            {
                v.pb(b[i]);
                i++;
            }
            
            for(j;j < sz(w)-1 ; j++)
            {
                //DEBUG(w[j]);
                v.pb(w[j]);
            }
            
            printf("%d",sz(v));
            for(int k = 0 ; k < sz(v) ; k++)
                printf(" %d",v[k]);
            printf("\n");
            
            printf("%d",sz(s)-sz(v));
            for(i; i < sz(b) ; i++)
                printf(" %d",b[i]);
            printf(" %d\n",sz(s));
        }
    }

    return 0;
}