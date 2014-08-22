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

char s[1000];
pair<char,int> cnt[30];

bool cmp(pair<char,int> a,pair<char,int> b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}

int main()
{
    //freopen("10008.INP","r",stdin);
    //freopen("10008.OUT","w",stdout);
    int len,n;
    for(int i=0;i<30;i++)
    {
        cnt[i].first=i+'A';
        cnt[i].second=0;
    }
    scanf(" %d ",&n);
    for(int i=0;i<n;i++)
    {
        gets(s);
        len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if('a'<=s[i] && s[i]<='z')
            {
                cnt[s[i]-'a'].second++;
            }
            if('A'<=s[i] && s[i]<='Z')
            {
                cnt[s[i]-'A'].second++;
            }
        }
    }
    sort(cnt,cnt+('z'-'a'),cmp);
    for(int i=0;i<30;i++)
    {
        if(cnt[i].second!=0)
        printf("%c %d\n",cnt[i].first,cnt[i].second);
    }
    return 0;
}
