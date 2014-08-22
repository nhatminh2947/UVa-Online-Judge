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
#define maxN 20000000
#define INF 1000111222
#define int64 long long

using namespace std;

vector<int> primes;
bool check[maxN+5];
pair<int,int> ans[100005];

void sieve()
{
    for(int i = 0 ; i <= maxN ; i++)
        check[i] = true;
    
    for(int64 i = 2 ; i <= maxN ; i++)
        if(check[i])
        {
            primes.pb(i);
            for(int64 j = i ; i*j <= maxN ; j++)
                check[i*j] = false;
        }
}

void pre_cal()
{
    sieve();
    int sz = primes.size();
    int cnt = 1;
    for(int i = 1 ; i < primes.size() && cnt < 100001 ; i++)
        if(primes[i] - primes[i-1] == 2)
        {
            ans[cnt].ff = primes[i-1];
            ans[cnt].ss = primes[i];
            cnt++;
        }
}

int main()
{
    freopen("10394 - Twin Primes.INP","r",stdin);
    freopen("10394 - Twin Primes.OUT","w",stdout);
    pre_cal();
    int n;
    while(scanf(" %d ",&n) == 1)
    {
        printf("(%d, %d)\n",ans[n].ff,ans[n].ss);
    }
    return 0;
}
