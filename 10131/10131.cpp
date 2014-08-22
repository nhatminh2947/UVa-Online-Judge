//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10131 - Is Bigger Smarter?
// Verdict: Accepted
//**********************************************
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
#define INF 999999999
#define PI 3,1415926535

using namespace std;

pair<int,int> e[1005];
int path[1005],T[1005];
int L[1005];
int n=1;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}

bool cmpp(int a,int b)
{
    if(e[a].first==e[b].first) return e[a].second>e[b].second;
    return e[a].first<e[b].first;
}

void DP()
{
    L[0]=1;
    e[0].second=INF;
    e[n+1].second=-INF;
    T[0]=0;
    for(int i=1;i<=n;i++)
        L[i]=0;
    for(int i=1;i<=n+1;i++)
    {
        int m=0;
        for(int j=i-1;j>=0;j--)
            if(e[j].second>e[i].second && L[m]<L[j] && e[j].first!=e[i].first)
                m=j;
        L[i]=L[m]+1;
        T[i]=m;
    }
}

int main()
{
    freopen("10131.INP","r",stdin);
    freopen("10131.OUT","w",stdout);
    while(scanf(" %d %d ",&e[n].first,&e[n].second)==2)
    {
        path[n]=n;
        n++;
    }
    n--;
    sort(path+1,path+n+1,cmpp);
    sort(e+1,e+n+1,cmp);
    
    DP();
    stack<int> s;
    int t=T[n+1];
    while(t)
    {
        s.push(path[t]);
        t=T[t];
    }
    
    printf("%d\n",L[n+1]-2);
    while(!s.empty())
    {
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}
