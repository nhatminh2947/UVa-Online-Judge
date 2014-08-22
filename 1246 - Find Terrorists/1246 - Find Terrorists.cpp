//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1246 - Find Terrorists
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

vector<int> primes;
bool check[1000005];
bool yes[1000005];

void sieve()
{
    primes.clear();
    for(int i = 0 ; i <= 10000 ; i++)
        check[i] = true;
    
    for(long long i = 2 ; i <= 10000 ; i++)
    {
        if(check[i])
        {
            for(long long j = i ; i*j <= 10000 ; j++)
                check[i*j] = false;
            primes.pb(i);
        }
    }
}

void pre_cal()
{
    sieve();
    fill(yes,yes+10001,false);
    int sz = primes.size();
    for(int i = 2 ; i <= 10000 ; i++)
    {
        int n = i;
        int sum = 2;
        for(int j = 0 ; j < sz && primes[j] < n ; j++)
        {
            int k = primes[j];
            int cnt = 0;
            while(k <= n)
            {
                cnt += n/k;
                k *= primes[j];
            }
            
            sum += cnt;
        }
        
        if(check[sum])
            yes[n] = true;
    }
}

int main()
{
    freopen("1246 - Find Terrorists.INP","r",stdin);
    freopen("1246 - Find Terrorists.OUT","w",stdout);
    pre_cal();
    int tcs,L,H;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d %d ",&L,&H);
        bool space = false;
        bool res = false;
        for(int i = L ; i <= H ; i++)
        {
            if(yes[i])
            {
                if(space) printf(" ");
                res = true;
                printf("%d",i);
            }
            if(res) space = true;
        }
        if(!res) printf("-1");
        printf("\n");
    }
    return 0;
}
