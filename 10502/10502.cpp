//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10502 - Counting Rectangles
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
#define PI 3,1415926535

using namespace std;

int n,m;
int data[105][105];

int main()
{
    //freopen("10502.INP","r",stdin);
    //freopen("10502.OUT","w",stdout);
    while(scanf(" %d %d ",&n,&m)==2)
    {
        char tmp;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                scanf(" %c ",&tmp);
                data[i][j]=tmp-'0';
            }
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(data[i][j]!=0)
                    data[i][j]+=data[i-1][j];
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int k=j;
                int min=data[i][j];
                while(data[i][k] && k+1)
                {
                    res+=min;
                    k--;
                    if(min>data[i][k])
                        min=data[i][k];
                }
            }
        printf("%d\n",res);
    }
    return 0;
}
