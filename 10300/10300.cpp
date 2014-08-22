//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10300 - Ecological Premium
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
    //freopen("10300.INP","r",stdin);
    //freopen("10300.OUT","w",stdout);
    int n,f,s,a,e;
    scanf(" %d ",&n);
    for(int i=0;i<n;i++)
    {
        int sum=0;
        scanf(" %d ",&f);
        for(int j=0;j<f;j++)
        {
            scanf(" %d %d %d ",&s,&a,&e);
            sum+=s*e;
        }
        printf("%d\n",sum);
    }
    return 0;
}
