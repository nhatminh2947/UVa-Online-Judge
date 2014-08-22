//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11974 - Switch The Lights
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

int n,m;
int lamps[105];
int step[40000];

int BFS()
{
    int st = (1 << n) - 1;
    queue<int> q;
    fill(step,step+38000,-1);
    step[st] = 0;
    q.push(st);
    
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        
        if(tmp == 0) return step[tmp];
        
        for(int i = 0 ; i < m ; i++)
        {
            int stt = tmp ^ lamps[i];
            if(step[stt] == -1)
            {
                step[stt] = step[tmp] + 1;
                q.push(stt);
            }
        }
    }
    return -1;
}

int main()
{
    freopen("11974 - Switch The Lights.INP","r",stdin);
    freopen("11974 - Switch The Lights.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("Case %d: ",t);
        
        scanf(" %d %d ",&n,&m);
        for(int i = 0 ; i < m ; i++)
        {
            lamps[i] = 0;
            for(int j = 0 ; j < n ; j++)
            {
                int tmp;
                scanf(" %d ",&tmp);
                lamps[i] = lamps[i]*2 + tmp;
            }
        }
        
        int res = BFS();
        if(res == -1)
            puts("IMPOSSIBLE");
        else printf("%d\n",res);
    }
    return 0;
}
