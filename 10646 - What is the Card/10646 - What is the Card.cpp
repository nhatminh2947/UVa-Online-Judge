//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10646 - What is the Card
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

int m[300];

void init()
{
    m['A'] = m['K'] = m['Q'] = m['J'] = m['T'] = 10;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10646 - What is the Card.INP","r",stdin);
    freopen("10646 - What is the Card.OUT","w",stdout);
    #endif
    init();
    int tcs;
    scanf(" %d ",&tcs);
    char c[55][5];
    rep(t,tcs)
    {
        fr(i,1,27)
        {
            scanf("%s",&c[i]);
            //DEBUG(c[i]);
        }
        int y = 0;
        int top = 27;
        rep(i,3)
        {
            int x = m[c[top][0]];
            //DEBUG(c[top]);
            //DEBUG(x);
            y += x;
            top--;
            top -= (10-x);
            //DEBUG(top);
        }
        //cout << "AAAAAAAA" << endl;
        //DEBUG(y);
        fr(i,top+1,top+25)
        {
            scanf("%s",&c[i]);
            //DEBUG(c[i]);
        }
        
        cout << "Case " << t+1 << ": " << c[y] << endl;
    }

    return 0;
}