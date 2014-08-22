//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10258 - Contest Scoreboard
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

int total[105];
int solved[105];
int penal[105][15];
bool stAC[105][15],vis[105];
vi ans;

bool cmp(int a, int b)
{
    if(solved[a] == solved[b])
    {
        if(total[a] == total[b])
            return a < b;
        return total[a] < total[b];
    }
    return solved[a] > solved[b];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10258 - Contest Scoreboard.INP","r",stdin);
    freopen("10258 - Contest Scoreboard.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        if(t != 1) printf("\n");
        
        //init
        ans.clear();
        fr(i,1,100)
        {
            fr(j,1,9)
                penal[i][j] = stAC[i][j] = 0;
            solved[i] = total[i] = vis[i] = 0;
        }
        
        //solve
        char s[1000];
        while(gets(s) && s[0] != '\0')
        {
            int c,p,t;
            char L;
            sscanf(s,"%d %d %d %c",&c,&p,&t,&L);
            
            if(L == 'C')
            {
                if(!stAC[c][p])
                {
                    //DEBUG(t);
                    stAC[c][p] = true;
                    total[c] += penal[c][p] + t;
                    solved[c]++;
                }
            }
            else if(L == 'I')
                penal[c][p] += 20;
            
            if(!vis[c])
            {
                ans.pb(c);
                vis[c] = true;
            }
        }
        
        sort(all(ans),cmp);
        
        rep(i,sz(ans))
            printf("%d %d %d\n",ans[i],solved[ans[i]],total[ans[i]]);
    }
    
    return 0;
}
