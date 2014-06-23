//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 494 - Kindergarten Counting Game
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
    //freopen("494.INP","r",stdin);
    //freopen("494.OUT","w",stdout);
    char s[1000];
    while(gets(s))
    {
        bool lock=false;
        int cnt=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(isalpha(s[i]) && lock==false)
            {
                lock=true;
                cnt++;
            }
            else if(!isalpha(s[i])) lock=false;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
