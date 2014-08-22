//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number:
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

int main()
{
    //freopen("10035.INP","r",stdin);
    //freopen("10035.OUT","w",stdout);
    long long num1,num2;
    int n1[20],n2[20];
    int sum[20];
    while (scanf(" %lld %lld ",&num1,&num2) && (num1 || num2))
    {
        for(int i=0;i<20;i++)
        {
            sum[i]=0;
            n1[i]=0;
            n2[i]=0;
        }
        int count=0;
        int d=19;
        while(num1 || num2)
        {
            n1[d]=num1%10;
            num1/=10;
            n2[d]=num2%10;
            num2/=10;
            d--;
        }
        for(int i=19;i>d;i--)
        {
            sum[i]=n1[i]+n2[i]+sum[i];
            if(sum[i]>9)
            {
                sum[i-1]=sum[i]/10;
                sum[i]=sum[i]%10;
                count++;
            }
        }
        if (count==0) printf("No carry operation.\n");
        else printf("%d carry %s.\n",count,count>1?"operations":"operation");
    }
}
