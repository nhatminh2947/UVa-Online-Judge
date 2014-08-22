//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 11513 - 9 Puzzle
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

int cnt=0;
string puzzle;
map<string, pair<string,string> > path;
map<string,int> dist;

void sp(char &a,char &b)
{
    int t=a;
    a=b;
    b=t;
}

int bfs()
{
    string tmp;
    path.clear();
    dist.clear();
    queue<string> q;
    q.push("123456789");
    dist["123456789"]=0;
    while(!q.empty())
    {
        string str=q.front();
        q.pop();
        for(int i=0;i<3;i++)
        {
            tmp=str;
            sp(tmp[i*3],tmp[i*3+1]);
            sp(tmp[i*3+1],tmp[i*3+2]);
            if(!dist[tmp] && tmp!="123456789")
            {
                q.push(tmp);
                if(i==0) 
                    path[tmp]=make_pair(str,"H1");
                else if(i==1) 
                    path[tmp]=make_pair(str,"H2");
                else if(i==2) 
                    path[tmp]=make_pair(str,"H3");
                dist[tmp]=dist[str]+1;
            }
            tmp=str;
            sp(tmp[i+3],tmp[i+6]);
            sp(tmp[i],tmp[i+3]);
            if(!dist[tmp] && tmp!="123456789")
            {
                q.push(tmp);
                if(i==0) 
                    path[tmp]=make_pair(str,"V1");
                else if(i==1) 
                    path[tmp]=make_pair(str,"V2");
                else if(i==2) 
                    path[tmp]=make_pair(str,"V3");
                dist[tmp]=dist[str]+1;
            }
        }
        cnt++;
    }
}

int main()
{
    //freopen("11513.INP","r",stdin);
    //freopen("11513.OUT","w",stdout);
    char data[10];
    char tmp1,tmp2,tmp3;
    bfs();
    while(gets(data) && data[0]!='0')
    {
        sscanf(data,"%c %c %c",&tmp1,&tmp2,&tmp3);
        puzzle+=tmp1;
        puzzle+=tmp2;
        puzzle+=tmp3;
        for(int i=0;i<2;i++)
        {
            gets(data);
            sscanf(data,"%c %c %c",&tmp1,&tmp2,&tmp3);
            puzzle+=tmp1;
            puzzle+=tmp2;
            puzzle+=tmp3;
        }
        if(puzzle=="123456789") printf("0\n");
        else if(dist[puzzle]==0) printf("Not solvable\n");
        else
        {
            printf("%d ",dist[puzzle]);
            string move=puzzle;
            while(move!="123456789")
            {
                cout<<path[move].second;
                move=path[move].first;
            }
            printf("\n");
        }
        
        puzzle.clear();
    }
    return 0;
}
