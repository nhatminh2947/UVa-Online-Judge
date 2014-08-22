//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10422 - Knights in FEN
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

//int dx[] = {-1, 0, 0, 1};
//int dy[] = { 0,-1, 1, 0};

int tcs;
char a[10][10];
int lim;

const char d[10][10] = 
    {
        {' ',' ',' ',' ',' ',' '},
        {' ','1','1','1','1','1'},
        {' ','0','1','1','1','1'},
        {' ','0','0',' ','1','1'},
        {' ','0','0','0','0','1'},
        {' ','0','0','0','0','0'},
    };

int numberMove(char state[10][10])
{
    int dif = 0;
    fr(i,1,5) fr(j,1,5) dif += (state[i][j] != d[i][j]);
    
    return dif/2;
}

bool inside(int y, int x)
{
    return (1 <= y && y <= 5 && 1 <= x && x <= 5);
}

void idaStar(int step, int y, int x, char state[10][10])
{
    int d = numberMove(state);
    
    if(d == 0)
    {
        lim = min(lim,step);
        return;
    }
    
    if(step + d > lim) return;
    
    rep(i,8)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(inside(yy,xx))
        {
            swap(state[y][x],state[yy][xx]);
            idaStar(step+1,yy,xx,state);
            swap(state[y][x],state[yy][xx]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10422 - Knights in FEN.INP","r",stdin);
    freopen("10422 - Knights in FEN.OUT","w",stdout);
    #endif
    
    read(tcs);
    getchar();
    fr(t,1,tcs)
    {
        int y,x;
        
        fr(i,1,5)
        {
            gets(a[i]+1);
            fr(j,1,5)
                if(a[i][j] == ' ')
                {
                    y = i;
                    x = j;
                }
        }
        
        lim = 11;
        
        idaStar(0,y,x,a);
        
        if(lim == 11) puts("Unsolvable in less than 11 move(s).");
        else printf("Solvable in %d move(s).\n",lim);
    }
    
    return 0;
}


