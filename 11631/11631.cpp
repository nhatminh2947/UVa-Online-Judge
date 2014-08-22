//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11631 - Dark roads
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

typedef struct
{
    int u,v,c;
}edge;

edge save[200005];
int lab[200005];
int m,n;
char s[30];

int getRoot(int u)
{
    if(u==lab[u]) return u;
    return lab[u]=getRoot(lab[u]);
}

int unionset(int a,int b)
{
    return lab[a]=b;
}

bool cmp(edge a,edge b)
{
    return a.c<b.c;
}

int convert(const char *s,int &n,int &m)
{
    int i = 0;
    m = n = 0;
    while (s[i] != ' ') n = n * 10 + s[i++] - 48;
    i++;
    while (s[i] != 0) m = m * 10 + s[i++] - 48;
    return (m + n);
}
void convert(const char *s,int &u,int &v,int &w)
{
    int i = 0;
    u = v = w = 0;
    while (s[i] != ' ') u = u * 10 + s[i++] - 48;
    i++;
    while (s[i] != ' ') v = v * 10 + s[i++] - 48;
    i++;
    while (s[i] != 0) w = w * 10 + s[i++] - 48;
}

int main()
{
    //freopen("11631.INP","r",stdin);
    //freopen("11631.OUT","w",stdout);
    while (gets(s) && convert(s,n,m))
    {
        int l = 0,total = 0;
        for (int i = 0 ; i <= n ; i++)
            lab[i] = i;
        for (int i = 0 ; i < m ; i++)
        {
            gets(s);
            convert(s,save[i].u,save[i].v,save[i].c);
            total += save[i].c;
        }
        sort(save,save+m,cmp);
        
        for (int i = 0 , br = 0; i < m && br < n - 1 ; i++)
        {
            int ru = getRoot(save[i].u),rv = getRoot(save[i].v);
            if (ru != rv)
                lab[rv] = ru , l += save[i].c , br++;
        }
        printf("%d\n",total - l);
        
    }
    return 0;
}
