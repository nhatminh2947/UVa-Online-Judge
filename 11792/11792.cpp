//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11792 - Krochanska is Here!
//==============================================================

#include <iostream>
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

int t,n,s;
int cnt[10005];
int step[10005];
vector<int> sta[10005];

int bfs(int in)
{
    for(int i=0;i<=n;i++)
        step[i]=0;
    step[in]=1;
    queue<int> q;
    q.push(in);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(int i=0;i<sta[tmp].size();i++)
            if(step[sta[tmp][i]]==0)
            {
                step[sta[tmp][i]]=step[tmp]+1;
                q.push(sta[tmp][i]);
            }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(cnt[i]>=2) sum+=step[i];
    return sum;
}

int main()
{
    //freopen("11792.INP","r",stdin);
    //freopen("11792.OUT","w",stdout);
    int prev,cur;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d",&n,&s);
        for(int j=0;j<=n;j++)
            sta[j].clear();
        for(int j=0;j<s;j++)
        {
            scanf("%d",&cur);
            cnt[cur]++;
            prev=cur;
            while(scanf("%d",&cur) && cur)
            {
                cnt[cur]++;
                sta[cur].push_back(prev);
                sta[prev].push_back(cur);
                prev=cur;
            }
        }
        int min=9999999;
        int result;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]>=2)
            {
                int sum=bfs(i);
                if(sum<min)
                {
                    min=sum;
                    result=i;
                }
            }
        }
        printf("Krochanska is in: %d\n",result);
    }
    return 0;
}
