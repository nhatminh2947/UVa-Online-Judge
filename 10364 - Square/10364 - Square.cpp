//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10364 - Square
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

int data[25];
bool vis[2000000];
int sum;
int n;

bool BFS()
{
    queue< pair<int,int> > q;
    q.push(mp(0,0));
    int ed = (1 << n) - 1;
    fill(vis,vis+ed+1,false);
    vis[0] = true;
    while(!q.empty())
    {
        int st = q.front().ff;
        int len = q.front().ss;
        
        if(st == ed)
            return true;
        
        q.pop();
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!(st & (1 << i)))
            {
                int tmp = st ^ (1 << i);
                if(!vis[tmp] && len + data[i] <= sum)
                {
                    int d = len + data[i];
                    if(d == sum) d = 0;
                    q.push(mp(tmp,d));
                    vis[tmp] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("10364 - Square.INP","r",stdin);
    freopen("10364 - Square.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf(" %d ",&data[i]);
            sum += data[i];
        }
        
        if(sum % 4 == 0)
        {
            sum /= 4;
            if(BFS()) puts("yes");
            else puts("no");
        }
        else puts("no");
        
    }
    return 0;
}
