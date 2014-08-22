//==============================================================
// Name: Huynh Nhat Minh
// Number problem: 10107 - What is the Median?
//==============================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
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

using namespace std;

int n[10005];

int main()
{
    freopen("10107.INP","r",stdin);
    freopen("10107.OUT","w",stdout);
    int check=1;
    int i=1;
    while(scanf("%d",&n[i]) == 1)
    {
        sort(n,n+check+1);
        if(check%2==1) printf("%d\n",n[check/2+1]);
        else printf("%d\n",(n[check/2]+n[check/2+1])/2);
        check++;
        i++;
    }
    return 0;
}
