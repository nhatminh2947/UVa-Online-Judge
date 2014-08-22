//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10462 - Is There A Second Way Left
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

int n,m;
vector< pair<ii,int> > lst;
bool used[205];
int pSet[205];

void initSet(int k)
{
    fr(i,1,n)
        pSet[i] = i;
}

int findSet(int u)
{
    if(pSet[u] == u) return u;
    return pSet[u] = findSet(pSet[u]);
}

bool cmp(pair<ii,int> u, pair<ii,int> v)
{
    return u.ss < v.ss;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10462 - Is There A Second Way Left.INP","r",stdin);
    freopen("10462 - Is There A Second Way Left.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        lst.clear();
        printf("Case #%d : ",t);
        read2(n,m);
        
        rep(i,m)
        {
            int u,v,w;
            read3(u,v,w);
            
            lst.pb(mp(mp(u,v),w));
        }
        
        vi v;
        sort(all(lst),cmp);
        initSet(n);
        int best = 0;
        int done = 0;
        rep(i,sz(lst))
        {
            int fu = findSet(lst[i].ff.ff);
            int fv = findSet(lst[i].ff.ss);
            
            if(fu != fv)
            {
                v.pb(i);
                pSet[fu] = fv;
                done++;
                best += lst[i].ss;
            }
            
            if(done == n-1)
                break;
        }
        //DEBUG(done);
        //DEBUG(n);
        if(done != n-1)
        {
            puts("No way");
            continue;
        }
        
        int ans = INF;
        rep(i,sz(v))
        {
            done = 0;
            int sdWay = 0;
            initSet(n);
            //DEBUG(i);
            //DEBUG(v[i]);
            
            rep(k,sz(lst))
            {
                //DEBUG(k);
                if(k == v[i]) continue;
                //cout << "AAA" << endl;
                int fu = findSet(lst[k].ff.ff);
                int fv = findSet(lst[k].ff.ss);
                
                if(fu != fv)
                {
                    pSet[fu] = fv;
                    done++;
                    sdWay += lst[k].ss;
                }
                
                if(done == n-1)
                    break;
            }
            //DEBUG(done);
            if(done == n-1)
                ans = min(ans,sdWay);
            else done++;
        }
        
        if(ans == INF) puts("No second way");
        else printf("%d\n",ans);
    }
    
    return 0;
}
