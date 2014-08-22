//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 562 - Dividing coins
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

int data[105];
int n,tcs;
int S,sum,res;

void backtrack(int i)
{
    if(i>=n)
        return;
    if(sum>=(S/2))
    {
        res=sum;
        return;
    }
    else
    {
        sum+=data[i];
        backtrack(i+1);
        sum-=data[i];
        backtrack(i+1);
    }
}

int main()
{
    freopen("562.INP","r",stdin);
    freopen("562.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for (int i = 0; i < tcs; i++)
    {
        scanf(" %d ",&n);
        S=0;
        sum=0;
        for (int j = 0; j < n;j++)
        {
            scanf(" %d ",&data[j]);
            S+=data[j];
        }
        backtrack(0);
        printf("%d\n",(S-2*res));
    }
    return 0;
}
