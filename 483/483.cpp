//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 483 - Word Scramble
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

char s[2000];

int main()
{
    //freopen("483.INP","r",stdin);
    //freopen("483.OUT","w",stdout);
    while(gets(s))
    {
        int len=strlen(s);
        int pos=0;
        for(int i=0;i<len;i++)
            if(s[i]==' ')
            {
                for(int j=i-1;j>=pos;j--)
                        printf("%c",s[j]);
                pos=i+1;
                printf(" ");
            }
        for(int j=len-1;j>=pos;j--)
            printf("%c",s[j]);
        printf("\n");
    }
    return 0;
}
