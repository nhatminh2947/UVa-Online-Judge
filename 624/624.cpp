//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 624 - CD
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

int n,k,S,m;
int track[25];
deque<int> dq,res;

int backtrack(int i)
{
    if(i<=n)
    {
        int t=S;
        S+=track[i];
        dq.push_back(track[i]);
        if(m<S && S<=k)
        {
            int sz=dq.size();
            m=S;
            res.clear();
            for(int i=0;i<sz;i++)
                res.push_back(dq[i]);
        }
        backtrack(i+1);
        dq.pop_back();
        S=t;
        backtrack(i+1);
    }
}

int main()
{
    freopen("624.INP","r",stdin);
    freopen("624.OUT","w",stdout);
    while(scanf(" %d ",&k)==1)
    {
        S=0;
        scanf(" %d ",&n);
        for(int i=1;i<=n;i++)
        {
            scanf(" %d ",&track[i]);
            S+=track[i];
        }
        if(S<k)
        {
            for(int i=1;i<=n;i++)
                printf("%d ",track[i]);
            printf("sum:%d\n",S);
        }
        else
        {
            m=-INF;
            for(int i=1;i<=n;i++)
            {
                dq.clear();
                S=0;
                backtrack(i);
            }
            int sz=res.size();
            for(int i=0;i<sz;i++)
                printf("%d ",res[i]);
            printf("sum:%d\n",m);
        }   
    }
    return 0;
}
