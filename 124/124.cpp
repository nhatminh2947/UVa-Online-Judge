//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 124 - Following Orders
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

int cnt;
map<char,int> constraints,check;
map<char,int>::iterator it;
vector<int> lk[50];

void reset()
{
    for(int i=0;i<50;i++)
        lk[i].clear();
    constraints.clear();
    check.clear();
    cnt=0;
}

void topo(string str,map<char,int> maps)
{
    map<char,int>::iterator itm,ittmp;
    map<char,int> maptmp;
    maps[str[str.length()-1]]=-1;
    for(int i=0;i<lk[str[str.length()-1]-'a'].size();i++)
        maps[lk[str[str.length()-1]-'a'][i]+'a']--;
    itm=maps.begin();
    while(itm!=maps.end())
    {
        maptmp[(*itm).first]=(*itm).second;
        itm++;
    }
    itm=maps.begin();
    while(itm!=maps.end())
    {
        if((*itm).second==0) 
        {
            string save;
            save=str+(*itm).first;
            if(save.length()==cnt)
            {
                cout<<save<<endl;
                break;
            }
            topo(save,maps);
        }
        ittmp=maptmp.begin();
        while(ittmp!=maptmp.end())
        {
            maps[(*ittmp).first]=(*ittmp).second;
            ittmp++;
        }
        itm++;
    }
}

int main()
{
    //freopen("124.INP","r",stdin);
    //freopen("124.OUT","w",stdout);
    char data[500];
    bool lock=false;
    while(gets(data))
    {
        if(lock==true) printf("\n");
        lock=true;
        reset();
        char tmp1,tmp2;
        for(int i=0;i<strlen(data);i+=2)
        {
            constraints[data[i]]=0;
            if(check[data[i]]==0) 
            {
                cnt++;
                check[data[i]]=1;
            }
        }
        gets(data);
        for(int i=0;i<strlen(data);i+=4)
        {
            sscanf(data+i," %c %c ",&tmp1,&tmp2);
            lk[tmp1-'a'].push_back(tmp2-'a');
            constraints[tmp2]++;
        }
        map<char,int> maptmp;
        map<char,int>::iterator itm;
        it=constraints.begin();
        while(it!=constraints.end())
        {
            maptmp[(*it).first]=(*it).second;
            it++;
        }
        it=constraints.begin();
        while(it!=constraints.end())
        {
            if((*it).second==0) 
            {
                string save;
                save+=(*it).first;
                topo(save,maptmp);
                
                itm=maptmp.begin();
                while(itm!=maptmp.end())
                {
                    constraints[(*itm).first]=(*itm).second;
                    itm++;
                }
            }
            it++;
        }
    }
    return 0;
}
