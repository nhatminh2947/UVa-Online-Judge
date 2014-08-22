//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1241 - Jollybee Tournament
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

bool a[2000];
bool F[5000];
int cnt;

bool solve(int node, int lf, int rg)
{
    if(lf == rg)
        return F[node] = a[lf];
    
    solve(node*2,lf,(lf+rg)/2);
    solve(node*2+1,(lf+rg)/2+1,rg);
    
    if(F[node*2] && F[node*2+1])
        return F[node] = true;
    
    if((F[node*2] && !F[node*2+1]) || (!F[node*2] && F[node*2+1]))
    {
        cnt++;
        return F[node] = true;
    }
    
    return F[node] = false;
}

int main()
{
    freopen("1241 - Jollybee Tournament.INP","r",stdin);
    freopen("1241 - Jollybee Tournament.OUT","w",stdout);
    int tcs,n,m;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        cnt = 0;
        scanf(" %d %d ",&n,&m);
        fill(a,a+(1<<n)+5,true);
        for(int i = 0 ; i < m ; i++)
        {
            int tmp;
            scanf(" %d ",&tmp);
            a[tmp-1] = false;
        }
        solve(1,0,(1<<n)-1);
        printf("%d\n",cnt);
    }
    return 0;
}
