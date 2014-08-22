//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 536 - Tree Recovery
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

struct Node
{
    char lb;
    int lf,rg;
    Node(char c)
    {
        lf=rg=-1;
        lb=c;
    }
};

char pre[30],in[30];
int pos[30];
vector<Node> tree;

int newNode(char lb)
{
    tree.push_back(Node(lb));
    return tree.size()-1;
}

void post(int n)
{
    if(n==-1) return;
    post(tree[n].lf);
    post(tree[n].rg);
    printf("%c",tree[n].lb);
}

int main()
{
    //freopen("536.INP","r",stdin);
    //freopen("536.OUT","w",stdout);
    while(scanf(" %s %s ",&pre,&in)==2)
    {
        tree.clear();
        newNode(pre[0]);
        
        int sz_pre=strlen(pre);
        int sz_in=strlen(in);
        
        for(int i=0;i<sz_in;i++)
            pos[in[i]-'A']=i;
        //int k=tree.size();
        int p,v;
        for(int i=1;i<sz_pre;i++)
        {
            p=v=0;
            while(v!=-1)
            {
                p=v;
                if(pos[pre[i]-'A']<pos[tree[v].lb-'A'])
                    v=tree[v].lf;
                else v=tree[v].rg;
            }
            int k=newNode(pre[i]);
            if(pos[pre[i]-'A']<pos[tree[p].lb-'A'])
                tree[p].lf=k;
            else
                tree[p].rg=k;
        }
        
        post(0);
        printf("\n");
    }
    return 0;
}
