//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10635 - Prince and Princess
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
#include <cctype>
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

int pos[70000];
int A[70000];
int L[70000];
int StartOf[70000];
int tcs,n,q,p,m,len;

int bSearch(int x)
{
    int lo = 1;
    int hi = m+1;
    int mid;
    int res;
    while(lo <= hi)
    {
        mid = (lo + hi)/2;
        if(A[x] < A[StartOf[mid]])
        {
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return StartOf[res];
}

int DP()
{
    fill(L,L+n*n+2,0);
    fill(StartOf,StartOf+n*n+2,0);
    StartOf[1] = len+1;
    A[0] = -INF;
    A[len+1] = INF;
    L[len+1] = 1;
    m = 1;
    
    for(int i = len ; i >= 0 ; i--)
    {
        int j = bSearch(i);
        L[i] = L[j] + 1;
        if(L[i] > m)
        {
            m = L[i];
            StartOf[m] = i;
        }
        else if(A[StartOf[L[i]]] < A[i])
            StartOf[L[i]] = i;
    }
    return m - 2;
}        

int main()
{
    freopen("10635 - Prince and Princess.INP","r",stdin);
    freopen("10635 - Prince and Princess.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d %d %d ",&n,&p,&q);
        p++;
        q++;
        fill(pos,pos+n*n+2,0);
        for(int i = 1 ; i <= p ; i++)
        {
            int tmp;
            scanf(" %d ",&tmp);
            pos[tmp] = i;
        }
        len = 0;
        for(int i = 1 ; i <= q ; i++)
        {
            int tmp;
            scanf(" %d ",&tmp);
            if(pos[tmp] != 0)
                A[++len] = pos[tmp];
        }
        
        printf("Case %d: %d\n",t,DP());
    }
    return 0;
}
