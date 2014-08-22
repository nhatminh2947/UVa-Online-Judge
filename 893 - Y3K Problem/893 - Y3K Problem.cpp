//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 893 - Y3K Problem
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

bool checkYear(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("893 - Y3K Problem.INP","r",stdin);
    freopen("893 - Y3K Problem.OUT","w",stdout);
    #endif
    int n,d,m,y;
    while(scanf(" %d %d %d %d ",&n,&d,&m,&y) && d)
    {
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        n += d;
        while(1)
        {
            if(checkYear(y))
                days[2] = 29;
            else days[2] = 28;
            
            if(n > days[m])
            {
                n -= days[m];
                m++;
                if(m > 12)
                {
                    m = 1;
                    y++;
                }
            }
            else break;
        }
        
        cout << n << " " << m << " " << y << endl;
    }
    
    return 0;
}
