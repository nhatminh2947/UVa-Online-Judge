//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11235 - Frequent values
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
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int r = 100000;

pair<int,int> lim[200005];
int A[100005];
int cnt[100005];
int tree[500000];
int n,q;

void bTree(int node,int a,int b)
{
    if(a==b)
        tree[node]=a;
    else
    {
        bTree(node*2,a,(a+b)/2);
        bTree(node*2+1,(a+b)/2+1,b);
        
        if(cnt[tree[node*2]] >= cnt[tree[node*2+1]])
            tree[node]=tree[node*2];
        else tree[node]=tree[node*2+1];
    }
}

int sTree(int node,int a,int b,int i,int j)
{
    int p1,p2;
    
    if(j<a || b<i)
        return -1;
    
    if(i<=a && b<=j)
        return tree[node];
        
    p1=sTree(node*2,a,(a+b)/2,i,j);
    p2=sTree(node*2+1,(a+b)/2+1,b,i,j);
    
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    if(cnt[p1]>=cnt[p2]) return p1;
    return p2;
}

int main()
{
    freopen("11235.INP","r",stdin);
    freopen("11235.OUT","w",stdout);
    while(scanf(" %d %d ",&n,&q) && n)
    {
        int save = -INF;
        for(int i=0;i<n;i++)
        {
            scanf(" %d ",&A[i]);
            if(A[i] != save)
            {
                save = A[i];
                lim[A[i]+r].ff = i;
                if (i>0) lim[A[i-1]+r].ss = i-1;
            }
        }
        lim[A[n-1]+r].ss = n-1;
        
        for (int i=0; i<n; i++) cnt[i]= lim[A[i]+r].ss - lim[A[i]+r].ff + 1;
        
        //cout << lim[10+r].ff << " " << lim[10+r].ss << endl;
        bTree(1,0,n-1);
        
        for(int i=0;i<q;i++)
        {
            int a,b;
            scanf(" %d %d ",&a,&b);
            a--;
            b--;
            int res;
            if(A[a] == A[b])
                res = b-a+1;
            else
            {
                // ---> a -- aa aaa -- bbb bb -- b
                int aa = lim[A[a]+r].ss; 
                int aaa = lim[A[a]+r].ss+1;
                int bbb = lim[A[b]+r].ff-1;
                int bb = lim[A[b]+r].ff;
                
                res=sTree(1,0,n-1,aaa,bbb);
                res = max(max(aa-a+1,b-bb+1),cnt[res]);
            }
            cout << res << endl;
        }
    }
    return 0;
}
