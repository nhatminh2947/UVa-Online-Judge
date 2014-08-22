//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 750 - 8 Queens Chess Problem
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

bool row[10];
bool ldiag[20];
bool rdiag[20];
int temp[10];
int res[100][10];
int cnt=0;

void backtrack(int c)
{
    if(c==9)
    {
        for(int i=1;i<=8;i++)
            res[cnt][i]=temp[i];
        cnt++;
        return;
    }
    
    for(int i=1;i<=8;i++)
    {
        if(!row[i] && !ldiag[c+i] && !rdiag[c-i+8])
        {
            row[i] = ldiag[c+i] = rdiag[c-i+8] = true;
            temp[c]=i;
            
            backtrack(c+1);
            
            row[i] = ldiag[c+i] = rdiag[c-i+8] = false;
        }
    }
}

int main()
{
    //freopen("750.INP","r",stdin);
    //freopen("750.OUT","w",stdout);
    int tcs,r,c;
    for(int i=0;i<10;i++)
    {
        row[i]=false;
        ldiag[i]=false;
        rdiag[i]=false;
    }
    backtrack(1);
    scanf("%d",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        int cs=0;
        scanf("%d%d",&r,&c);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        for(int j=0;j<cnt;j++)
            if(res[j][c]==r)
            {
                printf("%2d      ",++cs);
                printf("%d",res[j][1]);
                for(int k=2;k<=8;k++)
                    printf(" %d",res[j][k]);
                printf("\n");
            }
        if(i!=tcs) printf("\n");
    }
    return 0;
}
