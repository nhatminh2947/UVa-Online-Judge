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
#define INF 4294967295

using namespace std;

char n[100];

int main()
{
    //freopen("575.INP","r",stdin);
    //freopen("575.OUT","w",stdout);
    while(scanf(" %s ",&n) && n[0]!='0')
    {
        int len=strlen(n);
        int cnt=len;
        long long sum=0;
        for(int i=0;i<strlen(n);i++)
        {
            int p=1;
            for(int j=1;j<=cnt;j++)
                p*=2;
            sum+=((n[i]-'0')*(p-1));
            cnt--;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
