//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11588 - Image Coding
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

map<char,int> cnt;
map<char,int>::iterator it;
int X,r,c,m,n;

int main()
{
    //freopen("11588.INP","r",stdin);
    //freopen("11588.OUT","w",stdout);
    string data;
    scanf(" %d ",&X);
    for(int i=1;i<=X;i++)
    {
        cnt.clear();
        scanf(" %d %d %d %d ",&r,&c,&m,&n);
        for(int j=0;j<r;j++)
        {
            cin>>data;
            for(int u=0;u<data.length();u++)
                cnt[data[u]]++;
        }
        int max=-INF;
        it=cnt.begin();
        while(it!=cnt.end())
        {
            if(max<(*it).second) max=(*it).second;
            it++;
        }
        int res=0;
        it=cnt.begin();
        while(it!=cnt.end())
        {
            if((*it).second<max) res+=(*it).second*n;
            else if((*it).second==max) res+=(*it).second*m;
            it++;
        }
        printf("Case %d: %d\n",i,res);
    }
    return 0;
}
