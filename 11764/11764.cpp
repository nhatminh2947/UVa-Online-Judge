//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11764 - Jumping Mario
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

int main()
{
    //freopen("11764.INP","r",stdin);
    //freopen("11764.OUT","w",stdout);
    int tcs,n;
    int walls[55];
    scanf("%d",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        int up=0,down=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf("%d",&walls[j]);
        
        for(int j=0;j<n-1;j++)
            if(walls[j]>walls[j+1]) down++;
            else if(walls[j]<walls[j+1]) up++;
        
        printf("Case %d: %d %d\n",i,up,down);
    }
    return 0;
}
