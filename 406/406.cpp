//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 406 - Prime Cuts
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

int n,c;
bool check[1005];
vector<int> primes;

void sieve()
{
    for(int i=0;i<=1000;i++)
        check[i]=true;
    primes.push_back(1);
    for(int i=2;i<=1000;i++)
        if(check[i])
        {
            primes.push_back(i);
            for(int j=2;i*j<=1000;j++)
                check[i*j]=false;
        }
}

int main()
{
    freopen("406.INP","r",stdin);
    freopen("406.OUT","w",stdout);
    sieve();
    while(scanf(" %d %d ",&n,&c)==2)
    {
        printf("%d %d:",n,c);
        
        
        
        int cnt;
        int sz=primes.size();
        for(cnt=0;primes[cnt]<=n && cnt<sz;cnt++);
        
        if(cnt%2==0)
            c*=2;
        else c=c*2-1;
        
        if(c>=cnt)
            for(int i=0;i<cnt;i++)
                printf(" %d",primes[i]);
        else
        {
            int i=(cnt-c)/2;
            for(int k=0;k<c;k++,i++)
                printf(" %d",primes[i]);
        }
        
        printf("\n\n");
    }
    return 0;
}
