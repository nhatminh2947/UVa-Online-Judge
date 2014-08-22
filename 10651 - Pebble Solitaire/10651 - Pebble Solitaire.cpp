//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10651 - Pebble Solitaire
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

char inp[15];
int tcs;
int F[5000];

int BFS(int cur)
{
    fill(F,F+4500,INF);
    
    queue<int> q;
    
    q.push(cur);
    F[cur] = 0;
    int m = 0;
    
    while(!q.empty())
    {
        int st = q.front();
        
        q.pop();
        for(int i = 1 ; i < 11 ; i++)
        {
            if(st & (1 << i))
            {
                if((st & (1 << (i+1))) && (!(st & (1 << (i-1)))))
                {
                    int tmp = st;
                    tmp ^= (1 << i);
                    tmp ^= (1 << (i+1));
                    tmp ^= (1 << (i-1));
                    F[tmp] = F[st] + 1;
                    q.push(tmp);
                    m = max(m,F[tmp]);
                }
                if(!(st & (1 << (i+1))) && (st & (1 << (i-1))))
                {
                    int tmp = st;
                    tmp ^= (1 << i);
                    tmp ^= (1 << (i+1));
                    tmp ^= (1 << (i-1));
                    F[tmp] = F[st] + 1;
                    q.push(tmp);
                    m = max(m,F[tmp]);
                }
            }
        }
    }
    return m;
}

int main()
{
    freopen("10651 - Pebble Solitaire.INP","r",stdin);
    freopen("10651 - Pebble Solitaire.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        gets(inp);
        int cur = 0;
        int cnt = 0;
        for(int i = 0 ; i < 12 ; i++)
        {
            int tmp = 1;
            if(inp[i] == '-') tmp = 0;
            else cnt++;
            cur = cur*2 + tmp;
        }
        
        int ans = BFS(cur);
        ans = cnt - ans;
        printf("%d\n",ans);
    }
    return 0;
}
