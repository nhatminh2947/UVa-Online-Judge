//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 490 - Rotating Sentences
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

char sen[105][105],res[105][105];

int main()
{
    freopen("490.INP","r",stdin);
    freopen("490.OUT","w",stdout);
    int line=0;
    for(int i=0;i<=100;i++)
        sen[i][0]='\0';
    int maxlen=-INF;
    while(gets(sen[line]))
    {
        int l=strlen(sen[line]);
        if(maxlen<l) 
            maxlen=l;
        line++;
    }
    for(int i=0;i<line;i++)
        for(int j=0;j<maxlen;j++)
            res[j][line-i-1]=sen[i][j];
    for(int i=0;i<maxlen;i++)
        for(int j=line-1;j>=0;j--)
            if(res[i][j]!='\0' && res[i][j-1]=='\0') res[i][j-1]=' ';
    for(int i=0;i<maxlen;i++)
        puts(res[i]);
    return 0;
}
