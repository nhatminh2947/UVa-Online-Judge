//==============================================================
// Name: Huynh Nhat Minh
// Problem Number: 10926 - How Many Dependencies?
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

int n,t;
int l[105];
bool check[105];

vector< pair<int,int> > ss;
vector<int> depend[105];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}

int dfs(int a,int save)
{
    check[a]=true;
    l[save]++;
    for(int i=0;i<depend[a].size();i++)
    {
        if(check[depend[a][i]]==false && depend[depend[a][i]].size()==0)
        {
            check[depend[a][i]]=true;
            l[save]++;
        }
        else if(check[depend[a][i]]==false && depend[depend[a][i]].size()!=0)
            dfs(depend[a][i],save);
    }
}

int main()
{
    //freopen("10926.INP","r",stdin);
    //freopen("10926.OUT","w",stdout);
    int save,temp;
    while(scanf("%d",&n) && n)
    {
        ss.clear();
        for(int i=0;i<=105;i++)
            l[i]=0;
        for(int i=0;i<=105;i++)
            depend[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            for(int j=1;j<=t;j++)
            {
                scanf("%d",&temp);
                depend[i].push_back(temp);
            }
        }
        for(int i=1;i<=n;i++)
        {
            memset(check,false,sizeof(check));
            save=i;
            if(check[i]==false && depend[i].size()!=0)
            {
                check[i]=true;
                dfs(i,save);
                ss.push_back(make_pair(i,l[save]));
            }
        }
        sort(ss.begin(),ss.end(),cmp);
        printf("%d\n",ss.front().first);
    }
    return 0;
}
