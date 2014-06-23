//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 424 - Integer Inquiry
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

char vli[105];
int res[105];
int len=-INF;

int main()
{
    //freopen("424.INP","r",stdin);
    //freopen("424.OUT","w",stdout);
    for(int i=0;i<=100;i++)
        res[i]=0;
    int len=INF;
    while(scanf(" %s ",&vli) && vli[0]!='0')
    {
        int length=strlen(vli);
        int num=100;
        for(int i=length-1;i>=0;i--)
        {
            res[num]=res[num]+(vli[i]-'0');
            if(res[num]>=10)
            {
                res[num-1]=res[num-1]+(res[num]/10);
                res[num]=res[num]%10;
            }
            num--;
        }
        if(len>num) len=num;
    }
    if(res[len]==0) len++;
    for(int i=len;i<=100;i++)
        printf("%d",res[i]);
    printf("\n");
    return 0;
}
