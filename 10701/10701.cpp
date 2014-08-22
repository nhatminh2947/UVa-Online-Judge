//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10701 - Pre, in and post
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
    Node(char c){lf = -1,rg = -1,lb = c;}
};

int tcs,len;
vector<Node> tree;
string pre,in;
map<char,int> m;

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
    //freopen("10701.INP","r",stdin);
    //freopen("10701.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        tree.clear();
        scanf(" %d ",&len);
        cin>>pre>>in;
        
        int sz_in=in.size();
        int sz_pre=pre.size();
        for(int i=0;i<sz_in;i++)
            m[in[i]]=i;
        
        newNode(pre[0]);
        
        for(int i=1;i<sz_pre;i++)
        {
            int k = newNode(pre[i]);
            int p = 0,pos = 0;
            while (pos != -1)
            {
                p = pos;
                if (m[pre[i]] < m[tree[p].lb])
                    pos = tree[p].lf;
                else pos = tree[p].rg;
            }
            
            if (m[pre[i]] < m[tree[p].lb])
                   tree[p].lf = k;
            else tree[p].rg = k;
        }
        
        post(0);
        printf("\n");
    }
    return 0;
}
