//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11958-Coming Home
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

int tcs,k,q,ch,cm,ah,am;

int main()
{
    //freopen("11958.INP","r",stdin);
    //freopen("11958.OUT","w",stdout);
    char data[15];
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        int min=INF;
        gets(data);
        sscanf(data,"%d %d:%d",&k,&ch,&cm);
        for(int j=0;j<k;j++)
        {
            gets(data);
            sscanf(data,"%d:%d %d",&ah,&am,&q);
            int time=(ah-ch)*60+(am-cm);
            if(time<0)
            {
                ah+=24;
                am+=60;
                ah-=1;
                time=(ah-ch)*60+(am-cm)+q;
            }
            else time=(ah-ch)*60+(am-cm)+q;
            if(min>time) min=time;
        }
        printf("Case %d: %d\n",i,min);
    }
    return 0;
}
