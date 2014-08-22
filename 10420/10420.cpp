//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10420 - List of Conquests
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

int tcs;

char country[2005][80];
map<string,int> m;
map<string,int>::iterator it;

int main()
{
    //freopen("10420.INP","r",stdin);
    //freopen("10420.OUT","w",stdout);
    scanf("%d",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf("%s",&country[i]);
        m[country[i]]++;
        char a[200];
        gets(a);
    }
    it=m.begin();
    while(it!=m.end())
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
        it++;
    }
    return 0;
}
