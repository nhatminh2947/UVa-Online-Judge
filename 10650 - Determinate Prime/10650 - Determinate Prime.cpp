//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10650 - Determinate Prime
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
#define maxN 32000
#define INF 1000111222

using namespace std;

bool check[maxN+5];
vector<int> primes;
vector<int> ans[maxN+5];

void sieve()
{
    for(int i = 0 ; i <= maxN ; i++)
        check[i] = true;
    
    for(int i = 2 ; i <= maxN ; i++)
        if(check[i])
        {
            for(int j = i ; j*i <= maxN ; j++)
                check[i*j] = false;
            primes.pb(i);
        }
}

int pre_cal()
{
    int sz = primes.size();
    int k = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        int cnt = 0;
        vector<int> tmp;
        tmp.pb(primes[i]);
        tmp.pb(primes[i+1]);
        int j = i+2;
        while(primes[j] - tmp.back() == (tmp[1] - tmp[0]))
        {
            tmp.pb(primes[j]);
            j++;
        }
        if(tmp.size() >= 3)
        {
            ans[k++] = tmp;
            i = j-2;
        }
    }
    return k;
}

int main()
{
    freopen("10650 - Determinate Prime.INP","r",stdin);
    freopen("10650 - Determinate Prime.OUT","w",stdout);
    sieve();
    int lim = pre_cal();
    int x,y;
    while(scanf(" %d %d ",&x,&y))
    {
        if(!x && !y)
            break;
        if(x > y)
            swap(x,y);
        for(int i = 0 ; i < lim ; i++)
        {
            int sz = ans[i].size();
            if(x <= ans[i].front() && ans[i].back() <= y)
            {
                printf("%d",ans[i][0]);
                for(int j = 1 ; j < sz ; j++)
                    printf(" %d",ans[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
