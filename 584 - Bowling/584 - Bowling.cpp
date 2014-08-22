//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 584 - Bowling
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

ii f[50];
bool strike[50], square[50];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("584 - Bowling.INP","r",stdin);
    freopen("584 - Bowling.OUT","w",stdout);
    #endif
    
    char s[100];
    while(gets(s) && s[0] != 'G')
    {
        int cnt = 0;
        rep(i,12) f[i].ff = f[i].ss = -1, strike[i] = square[i] = false;
        
        int szs = strlen(s);
        rep(i,szs)
        {
            if(s[i] == ' ') continue;
            
            if(s[i] == 'X')
            {
                f[cnt].ff = 10;
                f[cnt].ss = 0;
                strike[cnt] = true;
                cnt++;
            }
            else if(s[i] == '/')
            {
                f[cnt].ss = 10 - f[cnt].ff;
                square[cnt] = true;
                cnt++;
            }
            else
            {
                if(f[cnt].ff != -1)
                {
                    f[cnt].ss = s[i] - '0';
                    cnt++;
                }
                else f[cnt].ff = s[i] - '0';
            }
        }
        
        int sum = 0;
        rep(i,10)
        {
            
            sum += f[i].ff + f[i].ss;
            if(square[i]) sum += f[i+1].ff;
            if(strike[i])
            {
                sum += f[i+1].ff;
                if(strike[i+1]) sum += f[i+2].ff;
                else sum += f[i+1].ss;
            }
        }
        
        printf("%d\n",sum);
    }

    return 0;
}