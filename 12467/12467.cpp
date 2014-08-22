//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 12467 - Secret Word
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
char str[1000005],res[1000005],tmp[1000005];

int main()
{
    //freopen("12467.INP","r",stdin);
    //freopen("12467.OUT","w",stdout);
    scanf(" %d ",&n);
    for(int i=0;i<n;i++)
    {
        tmp[0]='\0';
        scanf(" %s ",&str);
        res[0]=str[0];
        int len=strlen(str);
        int i=len-1,k=1;
        int l=1;
        for(;i>=0 && str[i]!=str[0];i--);
        i--;
        while (i>=0 && k<len && str[k]==str[i])
        {
            res[l++]=str[i];
            i--;
            k++;
        }
        res[l]='\0';
        i++;
        
        while (i>=0 && k<len)
        {
            for (;i>=0;i--)
            {
                if(k<len && str[i]==str[k])
                {
                    int cnt = 0;
                    for (int j = i ; j < l + 1 + i && str[j] == str[k - cnt] ; cnt++, j++)
                        tmp[cnt]=str[j];
                    tmp[cnt+1]='\0';
                }
                if (strlen(tmp)>l)
                {
                    res[l]=tmp[0];
                    res[++l]='\0';
                    k++;
                }
            }
            
        }
        int length=strlen(res);
        for(int i=length-1;i>=0;i--)
            printf("%c",res[i]);
        printf("\n");
    }
    return 0;
}
