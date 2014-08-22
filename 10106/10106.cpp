//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10106 - Product
// Verdict: Accepted
//******************************************************************
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

char x[255],y[255];
int res[500];

void solve(char x[],char y[])
{
    res[505];
    for(int i=0;i<=500;i++)
        res[i]=0;
    int lenx=strlen(x);
    int leny=strlen(y);
    int cnt=0;
    for(int i=lenx-1;i>=0;i--)
    {
        int n=500-cnt;
        for(int j=leny-1;j>=0;j--)
        {
            res[n]+=((x[i]-'0')*(y[j]-'0'));
            if(res[n]>9)
            {
                res[n-1]+=res[n]/10;
                res[n]%=10;
            }
            n--;
        }
        cnt++;
    }
}

int main()
{
    //freopen("10106.INP","r",stdin);
    //freopen("10106.OUT","w",stdout);
    while(scanf(" %s %s ",&x,&y)==2)
    {
        solve(x,y);
        bool lock=false;
        for(int i=0;i<=500;i++)
            if(res[i])
            {
                lock=true;
                while(i!=501)
                {
                    printf("%d",res[i]);
                    i++;
                }
            }
        if(!lock) printf("0");
        printf("\n");
    }
    return 0;
}
