//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11391 - Blobs in the Board
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
#include <cctype>
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

const int lim = (1 << 16);

int board[10][10];
int st;
bool F[30][70000];
int r,c;

int dx[] = { 1, 1,-r, 0, 0,-1,-1,-1};
int dy[] = { r, 0,-r, r,-r, r, 0, r};
bool inside(int p)
{
    int row = p/c;
    int col = p%r;
    
    return (0 <= row && row < r && 0 <= col && col < c);
}

void check(int step, int k,int state)
{
    for(int i = 0 ; i < 8 ; i++)
    {
        int b1 = k+dx[i]+dy[i];
        int b2 = b1+dx[i]+dy[i];
        if(inside(b1) && inside(b2) && (state & b1) && !(state & b2))
        {
            int tmp = state;
            tmp ^= (1 << k);
            tmp ^= (1 << b1);
            tmp ^= (1 << b2);
            
            F[step][tmp] = true;
        }
    }
}

int main()
{
    freopen("11391 - Blobs in the Board.INP","r",stdin);
    freopen("11391 - Blobs in the Board.OUT","w",stdout);
    int tcs,n;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d %d %d ",&r,&c,&n);
        for(int i = 0 ; i < r ; i++)
            fill(board[i],board[i]+c,0);
        for(int i = 0 ; i < n ; i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            board[u-1][v-1] = 1;
        }
        
        st = 0;
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                st = st*2 + board[i][j];
        
        for(int i = 0 ; i < n ; i++)
            fill(F[i],F[i]+lim+10,0);
        
        F[0][st] = true;
        int bit = r*c;
        
        for(int i = 1 ; i < n ; i++)
            for(int j = 0 ; j < lim ; j++)
                if(F[i-1][j])
                    for(int k = 0 ; k < bit ; k++)
                        if((1 << k) & j)
                            check(i,k,j);
        int cnt = 0;
        for(int j = 0 ; j < lim ; j++)
            if(F[n-1][j])
                cnt++;
        
        cout << cnt << endl;
    }
    return 0;
}
