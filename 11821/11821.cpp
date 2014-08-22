//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number:
// Verdict:
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

char num[35];
int tcs,decpt;
double ans;

double convert(char a[])
{
    double res=0;
    int sign=1;
    int len=strlen(a);
    int div=len;
    if(a[0]=='-')
    {
        div=len-1;
        sign*=-1;
    }
    decpt=div;
    for(int i=0;i<len;i++)
    {
        if('0'<=a[i] && a[i]<='9')
            res=res*10+(a[i]-'0');
        else if(a[i]=='.')
            decpt=i;
    }
    printf("%lf\n",res);
    div-=decpt;
    for(int i=0;i<div;i++)
        res=res/10;
    res*=sign;
    return res;
}

int main()
{
    freopen("11821.INP","r",stdin);
    freopen("11821.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        ans=0;
        while(scanf(" %s ",&num) && num[0]!='0')
        {
            ans+=convert(num);
        }
        printf("%lf\n",ans);
    }
    return 0;
}
