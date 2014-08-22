//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 524 - Prime Ring Problem
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
#define maxN 123456
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

using namespace std;

bool check[55];
bool num[20];
int n;

void sieve()
{
    for(int i = 0; i <= 50; i++)
        check[i] = true;
    for(int i = 2; i <= 50; i++)
    {
        if(check[i])
        {
            for(int j = i; i*j <= 50; j++)
                check[i*j] = false;
        }
    }
}

void backtrack(int k, vector<int> res)
{
    if(k==0 && check[res[0] + res[n-1]])
    {
        printf("%d",res[0]);
        for(int i = 1; i < res.size(); i++)
            printf(" %d",res[i]);
        printf("\n");
        return;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(check[res.back() + i] && !num[i])
        {
            num[i] = true;
            res.pb(i);
            backtrack(k-1,res);
            res.pop_back();
            num[i] = false;
        }
    }
}

int main()
{
    //freopen("524.INP","r",stdin);
    //freopen("524.OUT","w",stdout);
    sieve();
    int tcs = 0;
    while(scanf(" %d ",&n)==1)
    {
        if(tcs) printf("\n");
        printf("Case %d:\n",++tcs);
        for(int i = 1 ; i <= n ; i++)
            num[i] = false;
        num[1] = true;
        vector<int> a;
        a.pb(1);
        backtrack(n-1,a);
    }
    return 0;
}
