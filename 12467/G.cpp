/* Trân Vu Lâm */
/*             */
/*             */
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstring>
#include <set>
#include <math.h>
#define ii pair<int, int>
using namespace std;

char s[1000005];

int cutted(int st,int ed)
{
    
}


int main()
{
    freopen("12467.INP","r",stdin);
    freopen("12467.OUT","w",stdout);
    int n;
    scanf("%d ",&n);
    deque < char > ts, ans;
    deque <int> next;
    while (n--)
    {
        gets(s);
        ts.clear();
        ans.clear();
        
        ans.push_front(s[0]);
        int len = strlen(s);
        int k = 1;
        int i = len - 1;
        for (; i >= 0 && s[i] != s[0] ; i--);
        i--;
        while (i >= 0 && k < len && s[k] == s[i])
        {
            ans.push_front(s[i]);
            i--;
            k++;
        }
        i++;

        while (i >=0 && k< len)
        {
            for ( ; i >= 0; i--)
            {
                ts.clear();
                if (k < len && s[i] == s[k])
                {
                    int ct = 0;
                    for (int j = i ; j < ans.size() + 1 + i && s[j] == s[k - ct] ; ct++, j++)
                      ts.push_back(s[j]);
                   
                }
                if (ts.size() > ans.size())
                {
                    ans = ts;
                    k++;
                }
            }
            
        }
        for (int i = 0 ; i < ans.size() ; i++)
           printf("%c",ans[i]);
        printf("\n");
    }
    
    
    
    
    
    
    return 0;
}
