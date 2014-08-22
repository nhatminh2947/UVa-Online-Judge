//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10305 – Ordering Tasks
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
#define INF 99999999

using namespace std;
map<int,int> nlink;
vector<int> relate[105];
bool lock;

int topo(int in)
{
    if(!lock)
        printf("%d",in);
    else printf(" %d",in);
    nlink[in]=-1;
    for(int i=0;i<relate[in].size();i++)
        nlink[relate[in][i]]--;
    lock=true;
}

int main()
{
    //freopen("10305.INP","r",stdin);
    //freopen("10305.OUT","w",stdout);
    int a,b,n,m;
    while(scanf("%d%d",&n,&m) && n)
    {
        nlink.clear();
        for(int i=1;i<=n;i++)
            relate[i].clear();
        lock=false;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            nlink[b]++;
            relate[a].push_back(b);
        }
        int cnt=0;
        while(cnt<n)
            for(int i=1;i<=n;i++)
                if(nlink[i]==0)
                {
                    topo(i);
                    cnt++;
                }
        printf("\n");
    }
    return 0;
}
