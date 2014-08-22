//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10401 - Injured Queen Problem
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

string s;
int n;
ll cnt[20][20];
int row[20];
bool check[20][20];
bool a[20][20];

int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

bool inside(int y, int x)
{
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

ll DFS(int x)
{
    if(x == n+1) return 1;
    ll res = 0;
    
    if(row[x])
    {
        if(a[row[x]][x]) return 0;
        ll sum = 0;
        if(check[row[x]][x]) sum += cnt[row[x]][x];
        else
        {
            vii v;
            rep(k,8)
            {
                int yy = row[x]+dy[k];
                int xx = x+dx[k];
                if(inside(yy,xx))
                {
                    if(!a[yy][xx]) v.pb(mp(yy,xx));
                    a[yy][xx] = true;
                }
            }
            
            check[row[x]][x] = true;
            sum += DFS(x+1);
            
            rep(k,sz(v)) a[v[k].ff][v[k].ss] = false;
            
            cnt[row[x]][x] = sum;
        }
        
        return sum;
    }
    
    fr(i,1,n)
    {
        ll sum = 0;
        if(a[i][x]) continue;
        
        if(check[i][x]) sum += cnt[i][x];
        else
        {
            vii v;
            rep(k,8)
            {
                int yy = i+dy[k];
                int xx = x+dx[k];
                if(inside(yy,xx))
                {
                    if(!a[yy][xx]) v.pb(mp(yy,xx));
                    a[yy][xx] = true;
                }
            }
            
            check[i][x] = true;
            sum += DFS(x+1);
            
            rep(k,sz(v)) a[v[k].ff][v[k].ss] = false;
            
            cnt[i][x] = sum;
        }
        res += cnt[i][x];
    }
    
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10401 - Injured Queen Problem.INP","r",stdin);
    freopen("10401 - Injured Queen Problem.OUT","w",stdout);
    #endif
    
    while(cin >> s)
    {
        n = sz(s);
        
        fr(i,1,n) fr(j,1,n)
        {
            cnt[i][j] = 0;
            a[i][j] = check[i][j] = false;
        }
        
        fr(i,1,n) 
        {
            row[i] = 0;
            if('0' <= s[i-1] && s[i-1] <= '9')
            {
                row[i] = s[i-1] - '0';
                fr(j,1,n) check[j][i] = true;
                check[row[i]][i] = false;
            }
            else if('A' <= s[i-1] && s[i-1] <= 'F')
            {
                row[i] = s[i-1] - 'A' + 10;
                fr(j,1,n)  check[j][i] = true;
                check[row[i]][i] = false;
            }
        }
        
        printf("%lld\n",DFS(1));
    }
    
    return 0;
}