//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 382 - Perfection
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

int n;

int main()
{
    //freopen("382.INP","r",stdin);
    //freopen("382.OUT","w",stdout);
    printf("PERFECTION OUTPUT\n");
    while(scanf(" %d ",&n) && n)
    {
        printf("%5d  ",n);
        int tmp=n/2;
        int sum=0;
        for(int i=1;i<=tmp;i++)
            if(n%i==0) sum+=i;
        if(sum==n) printf("PERFECT\n");
        else if(sum<n) printf("DEFICIENT\n");
        else if(sum>n) printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
