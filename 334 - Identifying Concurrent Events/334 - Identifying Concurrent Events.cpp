//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 334 - Identifying Concurrent Events
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

int n;
map<string,int> m;
string a[205];
bool adj[205][205];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("334 - Identifying Concurrent Events.INP","r",stdin);
    freopen("334 - Identifying Concurrent Events.OUT","w",stdout);
    #endif
    
    int n;
    int tcs = 1;
    
    fr(i,1,200) fr(j,1,200)
        adj[i][j] = (i==j);
    
    while(scanf(" %d ",&n) && n)
    {
        m.clear();
        
        int cnt = 0;
        fr(i,1,n)
        {
            int k;
            scanf(" %d ",&k);
            vi tmp;
            
            rep(j,k)
            {
                cnt++;
                cin >> a[cnt];
                m[a[cnt]] = cnt;
                
                tmp.pb(cnt);
            }
            
            fr(i,1,sz(tmp)-1)
                adj[tmp[i-1]][tmp[i]] = true;
        }
        
        scanf(" %d ",&n);
        rep(i,n)
        {
            string u,v;
            cin >> u >> v;
            adj[m[u]][m[v]] = true;
        }
        
        fr(k,1,cnt)
            fr(i,1,cnt)
                fr(j,1,cnt)
                    adj[i][j] = adj[i][j] || adj[i][k] && adj[k][j];
        
        int con = 0;
        string eve = "";
        fr(i,1,cnt)
            fr(j,i+1,cnt)
                if(!adj[i][j] && !adj[j][i])
                {
                    con++;
                    if(con <= 2) eve += "(" + a[i] + "," + a[j] + ") ";
                }
            
        if(con)
        {
            printf("Case %d, %d concurrent events:\n",tcs++,con);
            cout << eve << endl;
        }
        else printf("Case %d, no concurrent events.\n",tcs++);
        
        fr(i,1,cnt) fr(j,1,cnt) adj[i][j] = (i == j);
    }
    
    return 0;
}
