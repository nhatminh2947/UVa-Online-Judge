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

bool check[25];
int n,m,k;

int main()
{
    //freopen("133.INP","r",stdin);
    //freopen("133.OUT","w",stdout);
    while(scanf(" %d %d %d ",&n,&k,&m) && n)
    {
        int cnt=0;
        int tmp1,tmp2,pk=1,pm=n;
        for(int i=1;i<=n;i++)
            check[i]=true;
        while(cnt!=n)
        {
            tmp1=pk;
            int c=0;
            while(c!=k)
            {
                if(tmp1>n) tmp1=1;
                if(check[tmp1])
                    c++;
                tmp1++;
            }
            --tmp1;
            pk=tmp1+1;
            
            tmp2=pm;
            c=0;
            while(c!=m)
            {
                if(tmp2<1)
                    tmp2=n;
                
                if(check[tmp2])
                    c++;
                    tmp2--;
            }
            ++tmp2;
            pm=tmp2-1;
            
            if(cnt) printf(",");
            if(tmp1==tmp2)
            {
                printf("%3d",tmp1);
                cnt++;
            }
            else
            {
                printf("%3d%3d",tmp1,tmp2);
                cnt+=2;
            }
            check[tmp2]=false;
            check[tmp1]=false;
        }
        printf("\n");
    }
    return 0;
}
