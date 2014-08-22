//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12160 - Unlock the Lock
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

int st,ed,n;
int b[15];
int step[10005];

int BFS()
{
    queue<int> q;
    fill(step,step+10000,-1);
    q.push(st);
    step[st] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        if(cur == ed) return step[cur];
        
        q.pop();
        
        for(int i = 0 ; i < n ; i++)
        {
            int tmp = cur + b[i];
            tmp %= 10000;
            
            if(step[tmp] == -1)
            {
                step[tmp] = step[cur] + 1;
                q.push(tmp);
            }
        }
    }
    return INF;
}

int main()
{
    //freopen("12160 - Unlock the Lock.INP","r",stdin);
    //freopen("12160 - Unlock the Lock.OUT","w",stdout);
    int tcs = 1;
    while(scanf(" %d %d %d ",&st,&ed,&n) && n)
    {
        for(int i = 0 ; i < n ; i++)
            scanf(" %d ",&b[i]);
        
        int ans = BFS();
        if(ans == INF) printf("Case %d: Permanently Locked\n",tcs++);
        else printf("Case %d: %d\n",tcs++,ans);
    }
    return 0;
}
