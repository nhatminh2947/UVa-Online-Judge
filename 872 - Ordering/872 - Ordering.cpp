//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 872 - Ordering
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

vi adj[300],run,ans;
int mark[300];
bool check;

void solve(int i)
{
    if(i == sz(run))
    {
        check = true;
        rep(i,sz(ans))
        {
            if(i) printf(" ");
            printf("%c",ans[i]);
        }
        printf("\n");
        return;
    }
    
    rep(n,sz(run))
    {
        if(!mark[run[n]])
        {
            bool con = false;
            rep(k,sz(adj[run[n]]))
            {
                int v = adj[run[n]][k];
                if(!mark[v])
                {
                    con = true;
                    break;
                }
            }
            if(con) continue;
                
            mark[run[n]] = true;
            ans.pb(run[n]);
            solve(i+1);
            ans.pop_back();
            mark[run[n]] = false;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("872 - Ordering.INP","r",stdin);
    freopen("872 - Ordering.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf("%d",&tcs);
    getchar();
    rep(t,tcs)
    {
        if(t) printf("\n");
        char s[1000];
        getchar();
        gets(s);
        //DEBUG(s);
        run.clear();
        ans.clear();
        int len = strlen(s);
        for(int i = 0 ; i < len ; i++)
            if(s[i] != ' ')
            {
                mark[i] = false;
                run.pb(s[i]);
                adj[i].clear();
            }
        
        gets(s);
        len = strlen(s);
        for(int i = 0 ; i < len ; i+=4)
            adj[s[i+2]].pb(s[i]);
        
        //sort(all(run));
        check = false;
        solve(0);
        
        if(!check) puts("NO");
    }
    
    return 0;
}
