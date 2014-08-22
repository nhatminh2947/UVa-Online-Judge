//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10539 - Almost Prime Numbers
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
#define maxN 1000000
#define INF 1000111222
#define int64 long long
#define uns64 unsigned long long

using namespace std;

bool check[maxN + 5];
vector<int64> primes;
vector<int64> ans;

const int64 lim = 1000000000000LL;

void sieve()
{
    for(int i = 0 ; i <= maxN ; i++)
        check[i] = true;
    
    for(int64 i = 2 ; i <= maxN ; i++)
    {
        if(check[i])
        {
            for(int64 j = i ; i*j <= maxN ; j++)
                check[i*j] = false;
            primes.pb(i);
        }
    }
}

void pre_cal()
{
    sieve();
    ans.clear();
    int sz = primes.size();
    for(int64 i = 0 ; i < sz ; i++)
        for(int64 j = primes[i]*primes[i] ; j <= lim ; j *= primes[i])
            ans.pb(j);
}

int main()
{
    freopen("10539 - Almost Prime Numbers.INP","r",stdin);
    freopen("10539 - Almost Prime Numbers.OUT","w",stdout);
    pre_cal();
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int64 lo,hi;
        cin >> lo >> hi ;
        
        int sz = ans.size();
        int cnt = 0;
        sort(ans.begin(),ans.end());
        for(int i = 0 ; i < sz ; i++)
            if(lo <= ans[i] && ans[i] <= hi)
                cnt++;
        
        printf("%d\n",cnt);
    }
    return 0;
}
