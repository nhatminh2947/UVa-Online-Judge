//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 543 - Goldbach's Conjecture
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

int n;
vector<int> primes;
bool check[1000005];

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
    //freopen("543.INP","r",stdin);
    //freopen("543.OUT","w",stdout);
    sieve();
    while(scanf(" %d ",&n) && n)
    {
        bool lock=false;
        for(int i=0;primes[i]<=n/2 && !lock;i++)
        {
            if(check[n-primes[i]] && primes[i]%2==1 && (n-primes[i])%2==1)
            {
                printf("%d = %d + %d\n",n,primes[i],n-primes[i]);
                lock=true;
                break;
            }
        }
        if(!lock) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
