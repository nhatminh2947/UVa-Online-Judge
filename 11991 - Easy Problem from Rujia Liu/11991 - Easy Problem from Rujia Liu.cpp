//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11991 - Easy Problem from Rujia Liu
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
#define read1(x) scanf("%d",&x)
#define read2(x,y) scanf(" %d ",&x,&y)
#define read3(x,y,z) scanf(" %d %d %d ",&x,&y,&z)
#define int64 long long
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define out(x) printf("%d",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

int n,m;
vector<int> v[1000005];

int main()
{
    freopen("11991 - Easy Problem from Rujia Liu.INP","r",stdin);
    freopen("11991 - Easy Problem from Rujia Liu.OUT","w",stdout);
    
    while(scanf(" %d %d ",&n,&m) == 2)
    {
        for(int i = 0 ; i <= 1000000 ; i++)
            v[i].clear();
        
        for(int i = 0 ; i < n ; i++)
        {
            int t;
            scanf(" %d ",&t);
            v[t].pb(i+1);
        }
        
        for(int i = 0 ; i < m ; i++)
        {
            int p,q;
            scanf(" %d %d ",&p,&q);
            
            if(p-1 < v[q].size())
                printf("%d\n",v[q][p-1]);
            else puts("0");
        }
    }
    
    return 0;
}


