//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number:
// Verdict:
//******************************************************************
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

char Toup(char c)
{
    if (c < 91) return c;
    return (c - 32);
}


int main()
{
    freopen("12243.INP","r",stdin);
    freopen("12243.OUT","w",stdout);
    
    char s[10000];
    while (gets(s))
    {
        if (s[0] == '*' && s[1] == 0) break;
        int p = 0;
        int len = strlen(s);
        char c = -1;
        bool IS = true;
        while (p < len)
        {
            if (c == -1) c = s[p];
            if (Toup(s[p]) != Toup(c))
            {
                IS = false;
                break;
            }
            while (p < len && s[p] != 32) p++;
            while (p < len && s[p] == 32) p++;
        }
        printf("%c\n",IS?'Y':'N');
         
        
        
    }
    
    
    return 0;
}
