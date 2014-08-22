//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10168 - Summation of Four Primes
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

bool check[10000005];
vector<int> primes;
int n;

void sieve()
{
    for(long long i=0;i<=10000000;i++)
        check[i]=true;
    for(long long i=2;i<=10000000;i++)
    {
        if(check[i])
        {
            primes.push_back(i);
            for(long long j=i;j*i<=10000000;j++)
                check[i*j]=false;
        }
    }
}

int main()
{
    //freopen("10168.INP","r",stdin);
    //freopen("10168.OUT","w",stdout);
    sieve();
    while(scanf(" %d ",&n)==1)
    {
        bool lock=false;
        if(n<8)
        {
            printf("Impossible.\n");
        }
        else
        {
            int sz=primes.size();
            int s=2;
            for(int j=2;j<=3 && !lock;j++)
            {
                for(int k=0;k<70 && !lock;k++)
                {
                    s=2+j+primes[k];
                    if(s<n && check[n-s])
                    {
                        printf("2 %d %d %d\n",j,primes[k],n-s);
                        lock=true;
                    }
                }
                s-=primes[j];
            }
        }
    }
    return 0;
}
