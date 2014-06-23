//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 429 - Word Transformation
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

typedef struct
{
    string s;
    int id;
}data;

data dic[210];
bool vis[210];
map<string,int> tran;
int tcs,n;

bool oneword(string a,string b)
{
    int la=a.size();
    int lb=b.size();
    if(la!=lb)
        return false;
    
    int cnt=0;
    for(int i=0;i<la;i++)
        if(a[i]!=b[i])
        {
            cnt++;
            if(cnt==2) return false;
        }
    
    return true;
}

int BFS(string s,string e)
{
    queue< pair<string,int> > q;
    q.push(make_pair(s,0));
    for(int i=0;i<n;i++)
        vis[i]=false;
    vis[tran[s]]=true;
    
    while(!q.empty())
    {
        string str=q.front().first;
        int cnt=q.front().second;
        if(str==e) return cnt;
        q.pop();
        
        for(int i=1;i<n;i++)
        {
            if(!vis[dic[i].id] && oneword(dic[i].s,str))
            {
                q.push(make_pair(dic[i].s,cnt+1));
                vis[dic[i].id]=true;
            }
        }
    }
}

bool cmp(data a,data b)
{
    return a.s<b.s;
}

int main()
{
    //freopen("429.INP","r",stdin);
    //freopen("429.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=0;t<tcs;t++)
    {
        if(t) printf("\n");
        string s,e;
        n=1;
        while(cin>>dic[n].s && dic[n++].s!="*");
        sort(dic+1,dic+n-1,cmp);
        for(int i=1;i<n;i++)
        {
            dic[i].id=i;
            tran[dic[i].s]=i;
        }
        char str[25];
        getchar();
        while(gets(str) && strlen(str))
        {
            char a[15],b[15];
            sscanf(str,"%s %s",&a,&b);
            int cnt=BFS(a,b);
            printf("%s %s %d\n",a,b,cnt);
        }
    }
    return 0;
}
