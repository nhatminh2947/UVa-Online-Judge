//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1195 - Calling Extraterrestrial Intelligence Again
// Verdict:
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
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int m,a,b;
bool check[8005];
vector<int> primes;

void sieve()
{
    for(int i=0;i<=8000;i++)
        check[i]=true;
    
    for(int i=2;i<=8000;i++)
    {
        if(check[i])
        {
            primes.push_back(i);
            for(long long j=i;j*i<=8000;j++)
                check[i*j]=false;
        }
    }
}

int main()
{
    //freopen("1195.INP","r",stdin);
    //freopen("1195.OUT","w",stdout);
    sieve();
    while(scanf(" %d %d %d ",&m,&a,&b) && m)
    {
        int sz=primes.size();
        int area=-INF;
        int p,q;
        for(int i=0;i<sz && primes[i]<=m;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(primes[i]>primes[j]) continue;
                int k=primes[i]*primes[j];
                if(k>m || a*primes[j]>b*primes[i]) break;
                if(k>area)
                {
                    area=k;
                    p=primes[i];
                    q=primes[j];
                }
            }
        }
        printf("%d %d\n",p,q);
    }
    return 0;
}
