//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10042 - Smith Numbers
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
#define maxN 10000
#define INF 1000111222
#define int64 long long

using namespace std;

bool check[maxN+5];
vector<int> primes;

void sieve()
{
    for(int i = 0 ; i <= maxN ; i++)
        check[i] = true;
    
    for(int64 i = 2 ; i <= maxN ; i++)
        if(check[i])
        {
            for(int64 j = i ; i*j <= maxN ; j++)
                check[i*j] = false;
            primes.pb(i);
        }
}

int sumDigits(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n%10;
        n/=10;
    }
    
    return sum;
}

int sumFractors(int n)
{
    int sz = primes.size();
    int sum = 0;
    int tmp = n;
    for(int i = 0 ; i < sz && primes[i] < n && n != 1; i++)
    {
        int cnt = 0;
        while(n % primes[i] == 0 && n != 1)
        {
            n /= primes[i];
            cnt++;
        }
        sum += sumDigits(primes[i])*cnt;
    }
    
    if(tmp == n)
        return -INF;
    
    if(n != 1)
        sum += sumDigits(n);
    
    return sum;
}

int main()
{
    freopen("10042 - Smith Numbers.INP","r",stdin);
    freopen("10042 - Smith Numbers.OUT","w",stdout);
    sieve();
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int n;
        scanf(" %d ",&n);
        
        while(++n)
        {
            if(sumDigits(n) == sumFractors(n))
            {
                printf("%d\n",n);
                break;
            }
        }
    }
    return 0;
}
