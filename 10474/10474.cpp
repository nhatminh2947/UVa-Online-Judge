//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10474 - Where is the Marble?
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
#define E 2,71828183
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int n,q;
int A[10005];

int BS(int x)
{
    int lo=1,hi=n;
    int pos = -1;
    
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        
        if(A[mid]<x)
            lo = mid + 1;
        else
        {
            hi=mid-1;
            if(A[mid] == x) pos = mid;
        }
    }
    
    return pos;
}

int main()
{
    //freopen("10474.INP","r",stdin);
    //freopen("10474.OUT","w",stdout);
    int t=1;
    while(scanf(" %d %d ",&n,&q))
    {
        if(n==0 && q==0) break; 
        for(int i=1;i<=n;i++)
            scanf(" %d ",&A[i]);
        
        sort(A+1,A+n+1);
        
        printf("CASE# %d:\n",t++);
        for(int i=0;i<q;i++)
        {
            int tmp;
            scanf(" %d ",&tmp);
            int pos = BS(tmp);
            
            if(pos == -1) printf("%d not found\n",tmp);
            else printf("%d found at %d\n",tmp,pos);
        }
    }
    return 0;
}
