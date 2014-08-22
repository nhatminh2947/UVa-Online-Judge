//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 924 - Spreading The News
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

vi adj[2505];
int step[2505];
int cnt[5000];
int n,val;

void BFS(int st)
{
    rep(i,n) step[i] = -1;
    queue<int> q;
    
    q.push(st);
    step[st] = 0;
    val = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        
        cnt[step[u]]++;
        val = step[u];
        
        int len = adj[u].size();
        
        rep(i,len)
        {
            int v = adj[u][i];
            
            if(step[v] == -1)
            {
                step[v] = step[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("924 - Spreading The News.INP","r",stdin);
    freopen("924 - Spreading The News.OUT","w",stdout);
    #endif
    
    scanf(" %d ",&n);
    
    rep(i,n)
    {
        int m,tmp;
        scanf(" %d ",&m);
        rep(j,m)
        {
            scanf(" %d ",&tmp);
            adj[i].pb(tmp);
        }
    }
    
    int tcs;
    scanf(" %d ",&tcs);
    //rep(i,2501) cnt[i] = 0;
    rep(i,tcs)
    {
        int st;
        scanf(" %d ",&st);
        
        BFS(st);
        
        if(val == 0) puts("0");
        else
        {
            int m,d;
            m = -INF;
            fr(i,1,val)
            {
                if(m < cnt[i])
                {
                    m = cnt[i];
                    d = i;
                }
                cnt[i] = 0;
            }
            
            printf("%d %d\n",m,d);
        }
    }
    
    return 0;
}