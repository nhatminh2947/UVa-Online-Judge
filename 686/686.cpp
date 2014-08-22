//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 686 - Goldbach's Conjecture (II)
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

bool check[32770];
vector<int> primes;
int n;

void sieve()
{
    for(int i=0;i<32770;i++)
        check[i]=true;
    for(int i=2;i<32770;i++)
        if(check[i])
        {
            primes.push_back(i);
            for(int j=2;j*i<32770;j++)
                check[i*j]=false;
        }
}

int main()
{
    //freopen("686.INP","r",stdin);
    //freopen("686.OUT","w",stdout);
    sieve();
    while(scanf(" %d ",&n) && n)
    {
        int k=n/2;
        int cnt=0;
        for(int i=0;primes[i]<=k;i++)
        {
            int t=n-primes[i];
            if(check[t]) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
