//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 108 - Maximum Sum
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

int arr[105][105];
int sum[105][105];
int n;

int main()
{
    freopen("108.INP","r",stdin);
    freopen("108.OUT","w",stdout);
    while(scanf(" %d ",&n)==1)
    {
        int max=-INF,tmp;
        int S=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf(" %d ",&arr[i][j]);
                S+=arr[i][j];
                if(max<arr[i][j]) max=arr[i][j];
            }
        if(max<S)
            max=S;
        for(int z=1;z<n;z++)
        {
            tmp=z-1;
            for(int i=0;i<n;i++)
                sum[tmp][i]=arr[tmp][i];
            for(int i=z;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    sum[i][j]=sum[i-1][j]+arr[i][j];
                    if(max<sum[i][j]) max=sum[i][j];
                }
                tmp=n-1;
                for(int j=0;j<tmp;j++)
                {
                    int t=sum[i][j];
                    for(int k=j;k<tmp;k++)
                    {
                        t+=sum[i][k+1];
                        if(max<t) max=t;
                    }
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
