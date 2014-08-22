//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 101 - The Blocks Problem
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

int n;
int path[100];
char s[100];
stack<int> block[100],tmp;

void moveonto(int a,int b)
{
    while(block[path[a]].top()!=a)
    {
        int p=block[path[a]].top();
        block[p].push(p);
        path[p]=p;
        block[path[a]].pop();
    }
    while(block[path[b]].top()!=b)
    {
        int p=block[path[b]].top();
        block[p].push(p);
        path[p]=p;
        block[path[b]].pop();
    }
    block[path[b]].push(a);
    block[path[a]].pop();
    path[a]=path[b];
}

void moveover(int a,int b)
{
    while(block[path[a]].top()!=a)
    {
        int p=block[path[a]].top();
        block[p].push(p);
        path[p]=p;
        block[path[a]].pop();
    }
    block[path[b]].push(a);
    block[path[a]].pop();
    path[a]=path[b];
}

void pileonto(int a,int b)
{
    while(block[path[b]].top()!=b)
    {
        int p=block[path[b]].top();
        block[p].push(p);
        path[p]=p;
        block[path[b]].pop();
    }
    while(block[path[a]].top()!=a)
    {
        int p=block[path[a]].top();
        tmp.push(p);
        block[path[a]].pop();
    }
    block[path[a]].pop();
    tmp.push(a);
    while(!tmp.empty())
    {
        int t=tmp.top();
        block[path[b]].push(t);
        path[t]=path[b];
        tmp.pop();
    }
}

void pileover(int a,int b)
{
    while(block[path[a]].top()!=a)
    {
        int p=block[path[a]].top();
        tmp.push(p);
        block[path[a]].pop();
    }
    block[path[a]].pop();
    tmp.push(a);
    while(!tmp.empty())
    {
        int t=tmp.top();
        block[path[b]].push(t);
        path[t]=path[b];
        tmp.pop();
    }
}

int main()
{
    //freopen("101.INP","r",stdin);
    //freopen("101.OUT","w",stdout);
    scanf(" %d ",&n);
    for(int i=0;i<n;i++)
    {
        block[i].push(i);
        path[i]=i;
    }
    int a,b;
    char cmd1[100],cmd2[100];
    while(gets(s))
    {
        if(s[0]=='q')
            break;
        sscanf(s," %s %d %s %d ",&cmd1,&a,&cmd2,&b);
        if(a!=b && path[a]!=path[b])
        {
            if(cmd1[0]=='m')
            {
                if(cmd2[1]=='n')
                    moveonto(a,b);
                else moveover(a,b);
            }
            else
            {
                if(cmd2[1]=='n')
                    pileonto(a,b);
                else pileover(a,b);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        while(!block[i].empty())
        {
            int t=block[i].top();
            tmp.push(t);
            block[i].pop();
        }
        while(!tmp.empty())
        {
            printf(" %d",tmp.top());
            tmp.pop();
        }
        printf("\n");
    }
    return 0;
}
