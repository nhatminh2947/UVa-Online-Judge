//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11350 - Stern-Brocot Tree
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

struct frac
{
    long long a,b;
    frac(long long x,long long y)
    {
        a=x;
        b=y;
    }
    frac(){}
};

struct Node
{
    frac lb,lf,rg;
    Node(frac a,frac b)
    {
        lf=a;
        rg=b;
        lb.a=lf.a+rg.a;
        lb.b=lf.b+rg.b;
    }
    Node(){}
};

int tcs;

int main()
{
    //freopen("11350.INP","r",stdin);
    //freopen("11350.OUT","w",stdout);
    scanf("%d",&tcs);
    getchar();
    for(int t=1;t<=tcs;t++)
    {
        char input[100];
        gets(input);
        int len=strlen(input);
        Node n=Node(frac(0,1),frac(1,0));
        
        for(int i=0;i<len;i++)
        {
            if(input[i]=='R')
                n=Node(n.lb,n.rg);
            else n=Node(n.lf,n.lb);
        }
        
        printf("%lld/%lld\n",n.lb.a,n.lb.b);
    }
    return 0;
}
