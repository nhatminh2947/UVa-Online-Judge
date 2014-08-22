/***********************************************
/ Coded by: Huynh Nhat Minh
/ Problem Number: 10036 - Divisibility
/ Verdict: Accepted
/**********************************************/
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

int data[10005];
bool cal[10005][105];
int n,k,tcs;

int dp()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cal[i][j]=false;
    cal[0][abs(data[0]%k)]=true;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<k;j++)
            if(cal[i-1][j])
            {
                cal[i][abs(( data[i]+j)%k)]=true;
                cal[i][abs((-data[i]+j)%k)]=true;
            }
    }
    if(cal[n-1][0]) return true;
    return false;
}

int main()
{
    freopen("10036.INP","r",stdin);
    freopen("10036.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %d %d ",&n,&k);
        for(int j=0;j<n;j++)
            scanf(" %d ",&data[j]);
        if(dp()) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
