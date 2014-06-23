//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 488 - Triangle Wave
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
#define INF 999999999
#define PI 3,1415926535

using namespace std;

int tcs,n,f;

int main()
{
    //freopen("488.INP","r",stdin);
    //freopen("488.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        if(i) printf("\n");
        scanf(" %d %d ",&n,&f);
        for(int j=0;j<f;j++)
        {
            if(j) printf("\n");
            for(int p=1;p<=n;p++)
            {
                for(int q=1;q<=p;q++)
                    printf("%d",p);
                printf("\n");
            }
            for(int p=n-1;p>=1;p--)
            {
                for(int q=1;q<=p;q++)
                    printf("%d",p);
                printf("\n");
            }
        }
    }
    return 0;
}
