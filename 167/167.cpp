//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 167 - The Sultan's Successors
// Verdict: Accepted
//**********************************************
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

typedef struct
{
    int b[10];
}chess;

int n;
int board[10][10];
int row[25];
int ld[25];
int rd[25];
chess tmp;
vector<chess> res;

void backtrack(int c)
{
    if(c==9)
    {
        res.push_back(tmp);
        return;
    }
    else
    {
        for(int i=1;i<=8;i++)
        {
            if(!row[i] && !ld[c+i] && !rd[c-i+8])
            {
                row[i]=ld[c+i]=rd[c-i+8]=true;
                tmp.b[c]=i;
                backtrack(c+1);
                row[i]=ld[c+i]=rd[c-i+8]=false;
            }
        }
    }
}

void init()
{
    for(int j=0;j<=20;j++)
        row[j]=ld[j]=rd[j]=false;
    backtrack(1);
}

int sum(int a)
{
    int S=0;
    chess t=res[a];
    for(int i=1;i<=8;i++)
        S+=board[t.b[i]][i];
    return S;
}

int main()
{
    //freopen("167.INP","r",stdin);
    //freopen("167.OUT","w",stdout);
    scanf(" %d ",&n);
    
    init();
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=8;j++)
            for(int k=1;k<=8;k++)
                scanf(" %d ",&board[j][k]);
        int sz=res.size();
        int ans=-INF;
        for(int i=0;i<sz;i++)
            ans=max(ans,sum(i));
        printf("%5d\n",ans);
    }
    return 0;
}
