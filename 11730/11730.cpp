//==============================================================
// Name: Huynh Nhat Minh
// Problem Number: 11730-Number Transformation
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

int s,t,tcs=1;
int numprime[1100];
bool prime[1100];

int sieve()
{
    int k=0;
    for(int i=0;i<=1100;i++)
        prime[i]=true;
    for(int i=2;i<=1100;i++)
        if(prime[i]==true)
        {
            numprime[k++]=i;
            for(int j=i;i*j<=1100;j++)
                prime[i*j]=false;
        }
    prime[1]=false;
}

int bfs(int s,int t)
{
    if(s==t) return 0;
    if(prime[s]==true) return -1;
    queue<int> q;
    bool check[2000];
    q.push(s);
    int tmp;
    int step[2000];
    for(int i=0;i<=2000;i++)
    {
        step[i]=0;
        check[i]=false;
    }
    check[s]=true;
    while(q.front()<t && !q.empty())
    {
        tmp=q.front();
        q.pop();
        int i=0;
        while(numprime[i]<=tmp/2)
        {
            if(tmp%numprime[i]==0 && tmp+numprime[i]<=t && check[tmp+numprime[i]]==false)
            {
                step[tmp+numprime[i]]=step[tmp]+1;
                if(tmp+numprime[i]==t) return step[tmp+numprime[i]];
                check[tmp+numprime[i]]=true;
                q.push(tmp+numprime[i]);
            }
            i++;
        }
    }
    return -1;
}

int main()
{
    freopen("11730.INP","r",stdin);
    freopen("11730.OUT","w",stdout);
    sieve();
    int result;
    while(scanf("%d%d",&s,&t) && s)
    {
        printf("Case %d: %d\n",tcs,bfs(s,t));
        tcs++;
    }
    return 0;
}
