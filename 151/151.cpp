//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 151 - Power Crisis
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

int n;
bool check[1000];

int cal(int a)
{
    for(int k=1;k<=15000;k++)
    {
        for(int i=1;i<=a;i++)
            check[i]=false;
        check[1]=true;
        int cnt=0;
        int i=0;
        int cut=0;
        while(cut!=(a-2))
        {
            if(!check[(i%a)+1])
                cnt++;
            if(cnt==k)
            {
                if((i%a)+1==13)
                    break;
                check[(i%a)+1]=true;
                cut++;
                cnt=0;
            }
            i++;
        }
        if(cut==(a-2)) return k;
    }
}

int main()
{
    freopen("151.INP","r",stdin);
    freopen("151.OUT","w",stdout);
    printf("int res[]={0,1,2,3,4,5,6,7,8,9,10,11,12");
    while(scanf(" %d ",&n) && n)
    {
        printf(",%d",cal(n));
    }
    printf("}");
    return 0;
}
