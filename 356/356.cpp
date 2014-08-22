//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 356 - Square Pegs And Round Holes
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

using namespace std;

int n;
float r;

int main()
{
    //freopen("356.INP","r",stdin);
    //freopen("356.OUT","w",stdout);
    bool lock=false;
    while(scanf(" %d ",&n)==1)
    {
        if(lock) printf("\n");
        r=n-0.5;
        int cnt=0;
        for(int x=1;x<n;x++)
            for(int y=1;y<n;y++)
            {
                if(sqrt(x*x+y*y)<=r) cnt++;
            }
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n,(2*n-1)*4); 
        printf("There are %d cells completely contained in the circle.\n",cnt*4);
        lock=true;
    }
    return 0;
}
