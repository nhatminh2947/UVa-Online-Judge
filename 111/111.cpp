//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 111 - History Grading
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

int tmp[25],order[25],data[25];
int n;

void LIS()
{
    for(int i=0;i<=n;i++)
        tmp[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(data[i]==order[j])
                tmp[j]=tmp[j-1]+1;
            else
                tmp[j]=max(tmp[j],tmp[j-1]);
        }
    }
    printf("%d\n",tmp[n]);
}

int main()
{
    //freopen("111.INP","r",stdin);
    //freopen("111.OUT","w",stdout);
    scanf(" %d ",&n);
    for(int i=1;i<=n;i++)
    {
        scanf(" %d ",&tmp[i]);
        order[tmp[i]]=i;
    }
    int t;
    while(scanf(" %d ",&t)==1)
    {
        data[t]=1;
        for(int i=2;i<=n;i++)
        {
            scanf(" %d ",&tmp[i]);
            data[tmp[i]]=i;
        }
        LIS();
    }
    return 0;
}
