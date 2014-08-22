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

int main()
{
    freopen("159.INP","r",stdin);
    freopen("159.OUT","w",stdout);
    char s[10000];
    char h1[10000],h2[10000],v1[10000],v2[10000];
    int first = 0;
    while (gets(s))
    {
        if (s[0] =='#') break;
        if (first) printf("\n");
        first++;
        
        sscanf(s,"%s %s %s %s",h1,v1,h2,v2);
        
        int lh1 = strlen(h1),lv1 = strlen(v1), lh2 = strlen(h2), lv2 = strlen(v2);
        int i = 0,j = 0,y = 0,z = 0;
        bool fp = false;
        
        for (; i < lh1 && (!fp); i++)
            for (j = 0; j < lv1 ; j++)
                if (h1[i] == v1[j])
                {
                    fp = true;
                    break;
                }
        i--;
        if (!fp)
        {
           printf("Unable to make two crosses\n");
           continue;
        }
        fp = false;
        for (; y < lh2  && !fp; y++)
            for (z = 0; z < lv2 ; z++)
                if (h2[y] == v2[z])
                {
                    fp = true;
                    break;
                }
        y--;
        if (!fp)
        {
           printf("Unable to make two crosses\n");
           continue;
        }
        int mx1 = max(j,z);
        
        for (int k = 0 ; k < mx1 ; k++)
        {
            if (k + j - mx1 >= 0)
            {
                for (int l = 0 ; l < i ; l++)
                    printf(" ");
                printf("%c",v1[k + j - mx1]);
            }
            if (k + z - mx1 >= 0)
            {
                if (k + j - mx1 >= 0)
                    for (int l = i + 1 ; l < lh1 + 3; l++)
                        printf(" ");
                else 
                    for (int l = 0 ; l < lh1 + 3; l++)
                        printf(" ");
                        
                for (int l = 0 ; l < y ; l++)
                    printf(" ");
                    
                printf("%c",v2[k + z - mx1]);
            }
            printf("\n");
        }
        printf("%s   %s\n",h1,h2);
        int r1 = lv1 - (j + 1) , r2 = lv2 - (z + 1);
        int mx2 = max(r1,r2);
        for (int k = 0 ; k < mx2 ; k++)
        {
            if (k + j + 1 < lv1)
            {
                for (int l = 0 ; l < i ; l++)
                    printf(" ");
                printf("%c",v1[j + k + 1]);
            }
            //cout<<z<<" "<<lv2<<endl;
            if (k + z + 1 < lv2)
            {
                if (k + j + 1 < lv1)
                    for (int l = i + 1 ; l < lh1 + 3; l++)
                        printf(" ");
                else 
                    for (int l = 0 ; l < lh1 + 3; l++)
                        printf(" ");
                        
                for (int l = 0 ; l < y ; l++)
                    printf(" ");
                    
                printf("%c",v2[z + k + 1]);
            }
            printf("\n");
        }
    }
    return 0;
}
