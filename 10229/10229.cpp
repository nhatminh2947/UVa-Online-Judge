//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10229 - Modular Fibonacci
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
    long long a,b,c,d;
}matrix;

matrix A;
int m,k;
long long n;

matrix mul(int i)
{
    if(i==0 || i==1) return A;
    matrix M,tmp;
    if(i%2==0)
    {
        M=mul(i/2);
        tmp.a = (((M.a%k)*(M.a%k))%k+((M.b%k)*(M.c%k)%k))%k;
        tmp.b = (((M.a%k)*(M.b%k))%k+((M.b%k)*(M.d%k)%k))%k;
        tmp.c = (((M.c%k)*(M.a%k))%k+((M.d%k)*(M.c%k)%k))%k;
        tmp.d = (((M.c%k)*(M.b%k))%k+((M.d%k)*(M.d%k)%k))%k;
        return tmp;
    }
    else
    {
        M=mul(i-1);
        tmp.a = (((A.a%k)*(M.a%k))%k+((A.b%k)*(M.c%k)%k))%k;
        tmp.b = (((A.a%k)*(M.b%k))%k+((A.b%k)*(M.d%k)%k))%k;
        tmp.c = (((A.c%k)*(M.a%k))%k+((A.d%k)*(M.c%k)%k))%k;
        tmp.d = (((A.c%k)*(M.b%k))%k+((A.d%k)*(M.d%k)%k))%k;
        return tmp;
    }
}

int main()
{
    //freopen("10229.INP","r",stdin);
    //freopen("10229.OUT","w",stdout);
    A.a=1;
    A.b=1;
    A.c=1;
    A.d=0;
    while(scanf(" %lld %d ",&n,&m)==2)
    {
        k=1;
        for(int i=0;i<m;i++,k*=2);
        if(n==0)
        {
            printf("%d\n",0%k);
            continue;
        }
        else if(n==1)
        {
            printf("%d\n",1%k);
            continue;
        }
        matrix res=mul(n-1);
        long long ans = res.a%k;
        printf("%lld\n",ans);
    }
    return 0;
}
