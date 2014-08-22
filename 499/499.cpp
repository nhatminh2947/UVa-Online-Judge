//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 499 - What's The Frequency, Kenneth?
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

char s[5005];
int c[30];
int C[30];

int main()
{
    //freopen("499.INP","r",stdin);
    //freopen("499.OUT","w",stdout);
    while(gets(s))
    {
        for(int i=0;i<30;i++)s
            c[i]=C[i]=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if('a'<=s[i] && s[i]<='z')
                c[s[i]-'a']++;
            else if('A'<=s[i] && s[i]<='Z')
                C[s[i]-'A']++;
        }
        int m=-INF;
        for(int i=0;i<26;i++)
            m=max(m,max(c[i],C[i]));
        for(int i=0;i<26;i++)
            if(C[i]==m)
                printf("%c",i+'A');
        for(int i=0;i<26;i++)
            if(c[i]==m)
                printf("%c",i+'a');
        printf(" %d\n",m);
    }
    return 0;
}
