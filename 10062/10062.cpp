//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10062 - Tell me the frequencies!
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

char s[1005];
bool check[150];
int cnt[150];

int main()
{
    freopen("10062.INP","r",stdin);
    freopen("10062.OUT","w",stdout);
    bool lock=false;
    while(scanf("%s",&s)==1)
    {
        if(lock==true) printf("\n");
        for(int i=0;i<150;i++)
        {
            check[i]=false;
            cnt[i]=0;
        }
        int l=strlen(s);
        for(int i=0;i<l;i++)
        {
            check[s[i]]=true;
            cnt[s[i]]++;
        }
        for(int i=150;i>0;i--)
            if(check[i]==true)
                printf("%d %d\n",i,cnt[i]);
        lock=true;
    }
    return 0;
}
