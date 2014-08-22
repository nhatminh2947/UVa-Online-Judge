//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 231 - Testing the CATCHER
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
#define INF 999999999

using namespace std;

int mis[100005];
int L[100005];
int m=0,res,cnt,cur;

void DP()
{
    mis[0]=INF;
    mis[m]=-INF;
    for(int i=1;i<=m;i++)
        L[i]=0;
    L[0]=1;
    for(int i=1;i<=m;i++)
    {
        int jmin=0;
        for(int j=0;j<=i;j++)
            if((mis[j]>mis[i]) && (L[j]>L[jmin]))
                jmin=j;
        L[i]=L[jmin]+1;
    }
}

int main()
{
    //freopen("231.INP","r",stdin);
    //freopen("231.OUT","w",stdout);
    int tcs=0;
    while(scanf("%d",&mis[++m]) && mis[m]!=-1)
    {
        while(scanf("%d",&mis[++m]) && mis[m]!=-1);
        res=-INF;
        cnt=0;
        cur=INF;
        DP();
        if(tcs) printf("\n");
        printf("Test #%d:\n",++tcs);
        printf("  maximum possible interceptions: %d\n",L[m]-2);
        m=0;
    }
    return 0;
}
