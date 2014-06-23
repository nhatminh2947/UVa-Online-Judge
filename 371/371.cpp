//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 371 - Continued Fractions
// Verdict: Accepted
//******************************************************************
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
#define INF 999999999
#define PI 3.1415926535
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

long long L,H,V,S,X;
int cnt;

void solve(long long x)
{
    if(x==1) return;    
    if(x%2==0)
        x/=2;
    else x=3*x+1;
    solve(x);
    cnt++;
}

int main()
{
    //freopen("371.INP","r",stdin);
    //freopen("371.OUT","w",stdout);
    while(scanf(" %lld %lld ",&L,&H) && L)
    {
        if(L>H)
            swap(L,H);
        int m=-INF;
        for(long long i=L;i<=H;i++)
        {
            cnt=1;
            long long x=i;
            if(x%2==0) x/=2;
            else x=3*x+1;
            solve(x);
            if(m<cnt)
            {
                m=cnt;
                S=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %d values.\n",L,H,S,m);
    }
    return 0;
}
