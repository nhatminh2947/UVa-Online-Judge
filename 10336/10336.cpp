//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10336 - Rank the Languages
// Verdict: Accepted
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

int cnt[30];
char data[105][105];
char letter;
int tcs,r,c;
vector< pair<char,int> > res;

void init()
{
    for(int i=0;i<30;i++)
        cnt[i]=0;
    res.clear();
}

bool inside(int y,int x)
{
    return (0<=x && x<c && 0<=y && y<r);
}

int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};

void DFS(int y,int x)
{
    data[y][x]='#';
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(inside(yy,xx) && data[yy][xx]==letter)
            DFS(yy,xx);
    }
}

bool cmp(pair<char,int> a,pair<char,int> b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}

int main()
{
    //freopen("10336.INP","r",stdin);
    //freopen("10336.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        init();
        scanf(" %d %d ",&r,&c);
        for(int p=0;p<r;p++)
            gets(data[p]);
        for(int p=0;p<r;p++)
            for(int q=0;q<c;q++)
            {
                if(data[p][q]!='#')
                {
                    letter=data[p][q];
                    DFS(p,q);
                    cnt[letter-'a']++;
                }
            }
        for(int k=0;k<30;k++)
            if(cnt[k])
                res.push_back(make_pair(k+'a',cnt[k]));
        sort(res.begin(),res.end(),cmp);
        int sz=res.size();
        printf("World #%d\n",i);
        for(int k=0;k<sz;k++)
            printf("%c: %d\n",res[k].first,res[k].second);
    }
    return 0;
}
