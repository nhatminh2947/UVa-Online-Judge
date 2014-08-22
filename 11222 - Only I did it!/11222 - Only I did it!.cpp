//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11222 - Only I did it!
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
#define maxN 1000

int a[5][maxN+5];
int c[5];
int cnt[10*maxN+5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11222 - Only I did it!.INP","r",stdin);
    freopen("11222 - Only I did it!.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        fill(cnt,cnt+10001,0);
        c[1] = c[2] = c[3] = 0;
        
        fr(i,1,3)
        {
            scanf(" %d ",&a[i][0]);
            //DEBUG(a[i][0]);
            fr(j,1,a[i][0])
            {
                scanf(" %d ",&a[i][j]);
                cnt[a[i][j]]++;
            }
            
            sort(a[i]+1,a[i]+a[i][0]+1);
        }
        
        int maxi = -1;
        fr(i,1,3)
        {
            fr(j,1,a[i][0])
                c[i] += (cnt[a[i][j]] == 1);
            maxi = max(maxi,c[i]);
        }
        
        printf("Case #%d:\n",t);
        
        fr(i,1,3)
        {
            if(c[i] == maxi)
            {
                printf("%d %d",i,c[i]);
                fr(j,1,a[i][0]) if(cnt[a[i][j]] == 1) printf(" %d",a[i][j]);
                puts("");
            }
        }
    }
    
    return 0;
}
