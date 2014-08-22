//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11790 - Murcia's Skyline
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

int tcs,n;
int data[1000005];
int val[1000005];
int L[1000005];
int path[1000005];

void DP()
{
    data[0] = -INF;
    data[n+1] = INF;
    L[n+1] = 1;
    
    for(int i = n ; i >= 0 ; i--)
    {
        int jmax = n+1;
        for(int j = i+1 ; j <= n+1 ; j++)
            if(data[j] > data[i] && L[jmax] < L[j])
                jmax = j;
        L[i] = L[jmax] + val[i];
        path[i] = jmax;
    }
}

int main()
{
    //freopen("11790 - Murcia's Skyline.INP","r",stdin);
    //freopen("11790 - Murcia's Skyline.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        for(int i = 1 ; i <= n ; i++)
            scanf(" %d ",&data[i]);
        for(int i = 1 ; i <= n ; i++)
            scanf(" %d ",&val[i]);
        
        DP();
        int sum_inc = 0;
        int pos = path[0];
        while(pos != n+1)
        {
            sum_inc += val[pos];
            pos = path[pos];
        }
        
        reverse(data+1,data+n+1);
        reverse(val+1,val+n+1);
        
        DP();
        int sum_dec = 0;
        pos = path[0];
        while(pos != n+1)
        {
            sum_dec += val[pos];
            pos = path[pos];
        }
        
        printf("Case %d. ",t);
        if(sum_inc >= sum_dec)
            printf("Increasing (%d). Decreasing (%d).\n",sum_inc,sum_dec);
        else printf("Decreasing (%d). Increasing (%d).\n",sum_dec,sum_inc);
    }
    return 0;
}
