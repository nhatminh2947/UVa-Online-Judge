//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1266 - Magic Square
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



int main()
{
    freopen("1266 - Magic Square.INP","r",stdin);
    freopen("1266 - Magic Square.OUT","w",stdout);
    int n;
    int tcs = 0;
    while(scanf(" %d ",&n) == 1)
    {
        if(tcs++)
            printf("\n");
        int a[20][20];
        for(int i = 0 ; i <= 15 ; i++)
            for(int j = 0 ; j <= 15 ; j++)
                a[i][j] = 0;
        int sum = 0;
        for(int i = 1 ; i <= n*n ; i++)
            sum += i;
        sum /= n;
        int mid = n/2;
        
        a[0][mid] = 1;
        int num = 2;
        
        int x = mid;
        int y = 0;
        for(int i = 2 ; i <= n*n ; i++)
        {
            int u = y - 1;
            int v = x + 1;
            
            if(u < 0)
                u = n-1;
            if(v >= n)
                v = 0;
            
            if(a[u][v])
            {
                u = y + 1;
                v = x;
            }
            a[u][v] = num++;
            x = v;
            y = u;
        }
        printf("n=%d, sum=%d\n",n,sum);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                printf(" %2d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
