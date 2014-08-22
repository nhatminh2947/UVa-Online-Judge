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

vector<string> u,v;
char a[205],b[205];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E.INP","r",stdin);
    freopen("E.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        u.clear();
        v.clear();
        gets(a);
        //DEBUG(a);
        string tmp = "";
        int lenA = strlen(a);
        rep(i,lenA)
        {
            if(a[i] == ' ')
            {
                u.pb(tmp);
                tmp = "";
            }
            else tmp += a[i];
        }
        u.pb(tmp);
        
        gets(b);
        tmp = "";
        int lenB = strlen(b);
        rep(i,lenB)
        {
            if(b[i] == ' ')
            {
                v.pb(tmp);
                tmp = "";
            }
            else tmp += b[i];
        }
        v.pb(tmp);
        
        rep(i,sz(v))
        {
            if(i) printf(" ");
            bool ok = false;
            rep(j,sz(u))
            {
                if(sz(u[j]) == sz(v[i]))
                {
                    string x = v[i];
                    string y = u[j];
                    int k = sz(x);
                    
                    if((x[0] == y[0]) && (x[k-1] == y[k-1]))
                    {
                        sort(all(x));
                        sort(all(y));
                        
                        if(x == y)
                        {
                            ok = true;
                            cout << u[j];
                            break;
                        }
                    }
                }
            }
            if(!ok) cout << v[i];
        }
        puts("");
    }
    
    return 0;
}
