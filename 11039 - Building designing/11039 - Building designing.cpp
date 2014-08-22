//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11039 - Building designing
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

vi v[5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11039 - Building designing.INP","r",stdin);
    freopen("11039 - Building designing.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    rep(t,tcs)
    {
        v[0].clear();
        v[1].clear();
        int n;
        read(n);
        if(n == 0)
        {
            puts("0");
            continue;
        }
        rep(i,n)
        {
            int k;
            read(k);
            
            if(k < 0) v[0].pb(-k);
            else v[1].pb(k);
        }
        
        if(v[0].empty() || v[1].empty())
        {
            puts("1");
            continue;
        }
        
        sort(all(v[0]));
        sort(all(v[1]));
        
        int ans = 1;
        
        int p[2];
        p[0] = 0;
        p[1] = -1;
        int stt = 1;
        
        if(v[0][0] > v[1][0])
        {
            p[0] = -1;
            p[1] = 0;
            stt = 0;
        }
        
        vector<int>::iterator it;
        while(1)
        {
            it = upper_bound(all(v[stt]),v[1-stt][p[1-stt]]);
            if(it == v[stt].end()) break;
            p[stt] = it-v[stt].begin();
            //printf("p[%d] = %d\n",stt,p[stt]);
            ans++;
            stt = 1 - stt;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
