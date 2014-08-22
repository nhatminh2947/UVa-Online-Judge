//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10354 - Avoiding Your Boss
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

int n,m,BH,OF,YH,M;
int dist[105][105], tmp[105][105];
bool check[105];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10354 - Avoiding Your Boss.INP","r",stdin);
    freopen("10354 - Avoiding Your Boss.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %d %d %d %d %d ",&n,&m,&BH,&OF,&YH,&M) == 6)
    {
        fr(i,1,n)
        {
            check[i] = true;
            fr(j,1,n)
                dist[i][j] = tmp[i][j] = (i == j) ? 0 : INF;
        }
        
        rep(i,m)
        {
            int u,v,w;
            scanf(" %d %d %d ",&u,&v,&w);
            dist[u][v] = dist[v][u] = tmp[u][v] = tmp[v][u] = w;
        }
        
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        
        int best = dist[BH][OF];
        //DEBUG(best);
        fr(k,1,n)
        {
            //printf("dist[%d][%d] = %d\n",BH,k,dist[BH][k]);
            //printf("dist[%d][%d] = %d\n",k,OF,dist[k][OF]);
            if(best != INF && best == (dist[BH][k] + dist[k][OF]))
            {
                //DEBUG("AAAA");
                check[k] = false;
            }
        }
        check[BH] = check[OF] = false;
        
        fr(k,1,n)
            fr(i,1,n)
                fr(j,1,n)
                    if(check[i] && check[j] && check[k])
                        tmp[i][j] = min(tmp[i][j],tmp[i][k]+tmp[k][j]);
        
        if(tmp[YH][M] != INF && check[YH] && check[M]) printf("%d\n",tmp[YH][M]);
        else puts("MISSION IMPOSSIBLE.");
    }
    
    return 0;
}
