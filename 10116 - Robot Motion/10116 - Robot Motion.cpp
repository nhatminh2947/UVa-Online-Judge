//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10116 - Robot Motion
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

string a[15];
int step[15][15];
int n,m,k;
int loop;
bool check;
map<char, pair<int,int> > d;

bool inside(int y, int x)
{
    return (0 <= y && y < n && 0 <= x && x < m);
}

int DFS(int y, int x)
{
    //printf("y = %d x = %d c = %c\n",y,x,a[y][x]);
    int dx = d[a[y][x]].ss;
    int dy = d[a[y][x]].ff;
    
    int yy = y + dy;
    int xx = x + dx;
    
    if(!inside(yy,xx))
    {
        //cout << "BBBB" << endl;
        return step[y][x];
    }
    
    if(step[yy][xx])
    {
        check = true;
        //cout << "AAAAA" << endl;
        loop = step[yy][xx]-1;
        return step[y][x];
    }
    
    step[yy][xx] = step[y][x] + 1;
    return DFS(yy,xx);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10116 - Robot Motion.INP","r",stdin);
    freopen("10116 - Robot Motion.OUT","w",stdout);
    #endif
    d.clear();
    d['N'].ff = -1; d['S'].ff =  1;
    d['N'].ss =  0; d['S'].ss =  0;
    
    d['E'].ff =  0; d['W'].ff =  0;
    d['E'].ss =  1; d['W'].ss = -1;
    
    while(read3(n,m,k))
    {
        if(n == 0 && m == 0 && k == 0) break;
        
        fr(i,0,10) fr(j,0,10) step[i][j] = 0;
        check = false;
        loop = 0;
        for(int i = 0 ; i < n ; i++)
        {
            read(a[i]);
            //cout << a[i] << endl;
        }
        step[0][k-1] = 1;
        int ans = DFS(0,k-1);
        
        if(check) printf("%d step(s) before a loop of %d step(s)\n",loop,ans-loop);
        else printf("%d step(s) to exit\n",ans);
    }
    
    return 0;
}
