//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1207 - AGTC
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

int n,m;
char s1[10005];
char s2[10005];
int F[10005][10005];

int main()
{
    //freopen("1207 - AGTC.INP","r",stdin);
    //freopen("1207 - AGTC.OUT","w",stdout);
    while(scanf(" %d ",&n) == 1)
    {
        scanf(" %s ",&s1);
        scanf(" %d ",&m);
        scanf(" %s ",&s2);
        
        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j <= m ; j++)
                F[i][j] = 0;
        for(int i = 0 ; i <= n ; i++)
            F[i][0] = i;
        for(int j = 0 ; j <= m ; j++)
            F[0][j] = j;
        
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
            {
                if(s1[i-1] == s2[j-1])
                    F[i][j] = F[i-1][j-1];
                else F[i][j] = min(F[i-1][j],min(F[i-1][j-1],F[i][j-1])) + 1;
            }
        
        printf("%d\n",F[n][m]);
    }
    return 0;
}
