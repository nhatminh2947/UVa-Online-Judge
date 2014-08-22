//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 458 - The Decoder
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
    //freopen("458.INP","r",stdin);
    //freopen("458.OUT","w",stdout);
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c!='\n')
            printf("%c",c-7);
        else printf("\n");
    }
    return 0;
}
