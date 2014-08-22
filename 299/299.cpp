//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 299 - Train Swapping
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

int tcs;
int train[55];

int main()
{
    //freopen("299.INP","r",stdin);
    //freopen("299.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        int l,cnt=0;
        scanf(" %d ",&l);
        for(int j=0;j<l;j++)
            scanf(" %d ",&train[j]);
        for(int j=0;j<l-1;j++)
            for(int k=j+1;k<l;k++)
                if(train[j]>train[k])
                {
                    cnt++;
                    swap(train[j],train[k]);
                }
        printf("Optimal train swapping takes %d swaps.\n",cnt);
    }
    return 0;
}
