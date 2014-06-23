//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 272 - TEX Quotes
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
    //freopen("272.INP","r",stdin);
    //freopen("272.OUT","w",stdout);
    char s[1000];
    bool lock=false;
    while(gets(s))
    {
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='"')
            {
                if(lock==false) 
                {
                    lock=true;
                    printf("``");
                }
                else 
                {
                    lock=false;
                    printf("''");
                }
            }
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
