//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1210 - 
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

bool check[10005];
int primes[1230];
int n;

void sieve()
{
    //1229
    for(int i=2;i<=10000;i++)
        check[i]=true;
    int k=0;
    for(int i=2;i<=10000;i++)
    {
        if(check[i])
        {
            primes[k++]=i;
            for(int j=i;j*i<=10000;j++)
                check[i*j]=false;
        }
    }
}

int main()
{
    freopen("1210.INP","r",stdin);
    freopen("1210.OUT","w",stdout);
    sieve();
    while(scanf(" %d ",&n) && n)
    {
        
    }
    return 0;
}
