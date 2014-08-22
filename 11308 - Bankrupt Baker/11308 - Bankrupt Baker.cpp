//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11308 - Bankrupt Baker
// Verdict: SubmissionErr
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

map<string,int> ingredient;

bool cmp(pair<string,int> u, pair<string,int> v)
{
    if(u.ss == v.ss) return u.ff < v.ff;
    return u.ss < v.ss;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11308 - Bankrupt Baker.INP","r",stdin);
    freopen("11308 - Bankrupt Baker.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    getchar();
    fr(t,1,tcs)
    {
        ingredient.clear();
        string s;
        getline(cin,s);
        rep(i,sz(s))
        {
            if('a' <= s[i] && s[i] <= 'z')
                s[i] -= ('a'-'A');
            
            cout << s[i];
        }
        printf("\n");
        
        int m,n,b;
        read3(m,n,b);
        
        rep(i,m)
        {
            int val;
            read2(s,val);
            ingredient[s] = val;
        }
        
        vector< pair<string,int> > ans;
        
        getchar();
        rep(i,n)
        {
            int k,val;
            ll sum = 0;
            getline(cin,s);
            read(k);
            rep(j,k)
            {
                string tmp;
                ll x;
                read2(tmp,x);
                sum += ingredient[tmp]*x;
            }
            
            if(sum <= b)
                ans.pb(mp(s,sum));
            getchar();
        }
        if(ans.empty())
        {
            puts("Too expensive!");
            printf("\n");
            continue;
        }
        
        sort(all(ans),cmp);
        rep(i,sz(ans))
            cout << ans[i].ff << endl;
        printf("\n");
    }
    
    return 0;
}
