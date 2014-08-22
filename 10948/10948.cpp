//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10948 - The primary problem
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

bool check[1000005];
vector<int> primes;
int n;

void sieve()
{
    for(int i=0;i<=1000000;i++)
        check[i]=true;
    for(long long i=2;i<=1000000;i++)
    {
        if(check[i])
        {
            primes.push_back(i);
            for(long long j=i;j*i<=1000000;j++)
                check[i*j]=false;
        }
    }
}

int main()
{
    //freopen("10948.INP","r",stdin);
    //freopen("10948.OUT","w",stdout);
    sieve();
    while(scanf(" %d ",&n) && n)
    {
        printf("%d:\n",n);
        int sz=primes.size();
        bool lock=true;
        for(int i=0;i<sz;i++)
        {
            if(primes[i]>n/2)
            {
                lock=false;
                break;
            }
            if(check[n-primes[i]])
            {
                printf("%d+%d\n",primes[i],n-primes[i]);
                break;
            }
        }
        if(!lock) printf("NO WAY!\n");
    }
    return 0;
}
