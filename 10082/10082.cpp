//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10082 - WERTYU
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

map<char,char> m;
char s[50];

char tb1[50]={"1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./ "};
char tb2[50]={"`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. "};

void init()
{
    m.clear();
    for(int i=0;i<44;i++)
        m[tb1[i]]=tb2[i];
}

int main()
{
    //freopen("10082.INP","r",stdin);
    //freopen("10082.OUT","w",stdout);
    init();
    while(gets(s))
    {
        int l=strlen(s);
        for(int i=0;i<l;i++)
            printf("%c",m[s[i]]);
        printf("\n");
    }
    return 0;
}
