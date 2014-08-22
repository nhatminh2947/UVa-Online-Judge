//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11405 - Can U Win?
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

char data[10][10];
int cnt[10][10];
int tcs,n,P;
int step[10][10][300];

bool inside(int y,int x)
{
    return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

int BFS(int kx,int ky)
{
    int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
    int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};
    
    queue< pair< pair<int,int>, int> > q;
    q.push(mp(mp(ky,kx),0));
    
    for(int i = 1 ; i <= 8 ; i++)
        for(int j = 1 ; j <= 8 ; j++)
            for(int k = 0 ; k <= P ; k++)
                step[i][j][k] = 0;
    
    step[ky][kx][0] = 1;
    
    while(!q.empty())
    {
        int y = q.front().ff.ff;
        int x = q.front().ff.ss;
        int st = q.front().ss;
        
        if(st == P) return step[y][x][st];
        q.pop();
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int stt = st;
            if(inside(yy,xx) && !step[yy][xx][stt] && data[yy][xx] != 'K' && data[yy][xx] != 'p')
            {
                if(data[yy][xx] == 'P')
                    stt = (1 << cnt[yy][xx]) | st;
                step[yy][xx][stt] = step[y][x][st] + 1;
                q.push(mp(mp(yy,xx),stt));
            }
        }
    }
    
    return INF;
}

int main()
{
    //freopen("11405 - Can U Win.INP","r",stdin);
    //freopen("11405 - Can U Win.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        P = 0;
        int kx,ky;
        for(int i = 1 ; i <= 8 ; i++)
            for(int j = 1 ; j <= 8 ; j++)
            {
                scanf(" %c ",&data[i][j]);
                if(data[i][j] == 'P')
                {
                    cnt[i][j] = P;
                    P++;
                }
                else if(data[i][j] == 'k')
                {
                    kx = j;
                    ky = i;
                }
            }
        P = (1 << P) - 1;
        
        int res = BFS(kx,ky);
        if(res-1 <= n)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
