//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 200 - Rare Order
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

char order[10000][25];
map<char,bool> vis;
vector<char> s;

int main()
{
    freopen("200.INP","r",stdin);
    freopen("200.OUT","w",stdout);
    vis.clear();
    s.clear();
    int line=0;
    int max=0;
    while(gets(order[line]) && order[line][0]!='#')
    {
        int len=strlen(order[line]);
        if(max<len) 
            max=len;
        line++;
    }
    for(int j=0;j<max;j++)
        for(int i=0;i<line;i++)
            if(!vis[order[i][j]] && j<strlen(order[i]))
            {
                s.push_back(order[i][j]);
                vis[order[i][j]]=true;
            }
    for(int k=0;k<s.size();k++)
        printf("%c",s[k]);
    printf("\n");
    return 0;
}
