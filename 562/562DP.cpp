//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 562 - Dividing coins
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
#define INF 4294967295

using namespace std;

int data[105];
int n,tcs;
int S,M,sum,res;
int F[105][50000];

void DP()
{
    for(int j = 0; j <= M; j++)
        F[0][j]=0;
    for(int i = 1; i <= n; i++)
    {
        F[i][0]=0;
        for(int j = 1; j <= M; j++)
        {
            if(data[i] <= j)
                F[i][j] = max( F[i-1][j-data[i]]+data[i], F[i-1][j]);
            else F[i][j] = F[i-1][j];
        }
    }
}

int main()
{
    //freopen("562.INP","r",stdin);
    //freopen("562.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for (int i = 0; i < tcs; i++)
    {
        scanf(" %d ",&n);
        S=0;
        sum=0;
        for (int j = 1; j <= n;j++)
        {
            scanf(" %d ",&data[j]);
            S += data[j];
        }
        M=S/2;
        DP();
        printf("%d\n",(S-2*F[n][M]));
    }
    return 0;
}
