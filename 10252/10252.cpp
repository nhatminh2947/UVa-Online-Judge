//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10252 - Common Permutation
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

char s1[1005],s2[1005];
int cnt1[30],cnt2[30];

int main()
{
    //freopen("10252.INP","r",stdin);
    //freopen("10252.OUT","w",stdout);
    while(gets(s1))
    {
        gets(s2);
        int len1=strlen(s1);
        int len2=strlen(s2);
        for(int i=0;i<30;i++)
        {
            cnt1[i]=0;
            cnt2[i]=0;
        }
        for(int i=0;i<len1;i++)
        {
            cnt1[s1[i]-'a']++;
        }
        for(int i=0;i<len2;i++)
        {
            cnt2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            int res=min(cnt1[i],cnt2[i]);
            for (int j = 0 ; j < res ; j++)
            printf("%c",i+'a');
        }
        printf("\n");
    }
    return 0;
}
