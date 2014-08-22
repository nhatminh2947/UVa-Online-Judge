//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11057 - Exact Sum
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

int n,m;
int A[10005];

int BS(int x)
{
    int lo=0,hi=n-1;
    int mid;
    
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        
        if(A[mid]==(m-A[x]) && mid!=x)
            return mid;
        
        if(A[mid]>(m-A[x]))
            hi=mid-1;
        else lo=mid+1;
    }
    return -1;
}

int main()
{
    //freopen("11057.INP","r",stdin);
    //freopen("11057.OUT","w",stdout);
    while(scanf(" %d ",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf(" %d ",&A[i]);
        sort(A,A+n);
        scanf(" %d ",&m);
        int b1,b2;
        int d=INF;
        for(int i=0;i<n;i++)
        {
            int tmp1=i;
            int tmp2=BS(tmp1);
            if(tmp2==-1) continue;
            if(d>abs(A[tmp1]-A[tmp2]))
            {
                b1=A[tmp1];
                b2=A[tmp2];
                if(b1>b2)
                    swap(b1,b2);
                d=abs(A[tmp1]-A[tmp2]);
            }
        }
        
        printf("Peter should buy books whose prices are %d and %d.\n\n",b1,b2);
    }
    return 0;
}
