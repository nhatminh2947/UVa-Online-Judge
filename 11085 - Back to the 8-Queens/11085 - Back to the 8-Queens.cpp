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

struct Chess
{
    int a[10];
};

vector<Chess> v;
int a[10];
Chess c;
bool row[100], diaLeft[100], diaRight[100];

void solve(int k)
{
    if(k == 9)
    {
        //fr(i,1,8) printf("%d ",c.a[i]);
        //printf("\n");
        v.pb(c);
        return;
    }
    
    for(int i = 1 ; i <= 8 ; i++)
    {
        if(!row[i] && !diaLeft[i+k] && !diaRight[i-k+50])
        {
            row[i] = diaLeft[i+k] = diaRight[i-k+50] = true;
            c.a[k] = i;
            solve(k+1);
            row[i] = diaLeft[i+k] = diaRight[i-k+50] = false;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11085.INP","r",stdin);
    freopen("11085.OUT","w",stdout);
    #endif
    
    fr(i,0,100) row[i] = diaLeft[i] = diaRight[i] = false;
    solve(1);
    int tcs = 1;
    while(scanf("%d %d %d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8]) == 8)
    {
        int ans = INF;
        rep(i,sz(v))
        {
            int sum = 0;
            fr(k,1,8)
            {
                //DEBUG(v[i].a[k]);
                //DEBUG(a[k]);
                if(abs(v[i].a[k] - a[k])) sum++;
            }
            //DEBUG(sum);
            ans = min(ans,sum);
        }
        
        printf("Case %d: %d\n",tcs++,ans);
    }
    
    return 0;
}
