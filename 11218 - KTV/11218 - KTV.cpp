//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11218 - KTV
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
#define maxN 123456
#define INF 1000111222

using namespace std;

int F[550];
int a[100],b[100],c[100],s[100];
int n;

int solve(int st)
{
    if(st == 511)
        return 0;
    if(F[st] != -1)
        return F[st];
    
    int m = -INF;
    
    for(int i = 0 ; i < n ; i++)
    {
        int x = 1 << a[i];
        int y = 1 << b[i];
        int z = 1 << c[i];
        
        if(!(x & st) && !(y & st) && !(z & st))
            m = max(m,s[i] + solve(st | x | y | z));
    }
    
    return F[st] = m;
}

int main()
{
    //freopen("11218 - KTV.INP","r",stdin);
    //freopen("11218 - KTV.OUT","w",stdout);
    int tcs = 0;
    while(scanf(" %d ",&n) && n)
    {
        for(int i = 0 ; i < 512 ; i++)
            F[i] = -1;
        
        for(int i = 0 ; i < n ; i++)
        {
            scanf(" %d %d %d %d ",&a[i],&b[i],&c[i],&s[i]);
            a[i]--;
            b[i]--;
            c[i]--;
        }
        
        int res = solve(0);
        printf("Case %d: ",++tcs);
        if(res > 0)
            printf("%d\n",res);
        else printf("-1\n");
    }
    return 0;
}
