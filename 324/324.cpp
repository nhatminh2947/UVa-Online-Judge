//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 324 - Factorial Frequencies
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

int num[400][800];

void cal()
{
    num[0][799]=1;
    num[0][798]=-1;
    for(int i=1;i<=366;i++)
    {
        int digit=799;
        int tmp;
        while(num[i-1][digit]!=-1)
        {
            num[i][digit]=num[i-1][digit]*i+num[i][digit];
            tmp=digit;
            while(num[i][tmp]>9)
            {
                num[i][tmp-1]=num[i][tmp]/10+num[i][tmp-1];
                num[i][tmp]=num[i][tmp]%10;
                tmp--;
            }
            digit--;
        }
        num[i][tmp-1]=-1;
    }
}

int main()
{
    freopen("324.INP","r",stdin);
    freopen("324.OUT","w",stdout);
    int digit[10];
    for(int i=0;i<400;i++)
        for(int j=0;j<800;j++)
            num[i][j]=0;
    int n;
    cal();
    while(scanf("%d",&n) && n)
    {
        for(int i=0;i<10;i++)
            digit[i]=0;
        int k=799;
        while(num[n][k]!=-1)
        {
            digit[num[n][k]]++;
            k--;
        }
        printf("%d! --\n",n);
        printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",digit[0],digit[1],digit[2],digit[3],digit[4]);
        printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",digit[5],digit[6],digit[7],digit[8],digit[9]);
    }
    return 0;
}
