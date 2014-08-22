//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1225 - Digit Counting
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

int F[10005][20];

void pre_cal()
{
    for(int i = 0 ; i <= 10000 ; i++)
        for(int j = 0 ; j <= 10 ; j++)
            F[i][j] = 0;
    
    for(int i = 1 ; i <= 10000 ; i++)
    {
        int k = i;
        for(int j = 0 ; j <= 9 ; j++)
            F[i][j] = F[i-1][j];
        
        while(k)
        {
            F[i][k%10]++;
            k/=10;
        }
    }
}

int main()
{
    freopen("1225 - Digit Counting.INP","r",stdin);
    freopen("1225 - Digit Counting.OUT","w",stdout);
    int tcs,n;
    scanf(" %d ",&tcs);
    pre_cal();
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        printf("%d",F[n][0]);
        for(int j = 1 ; j <= 9 ; j++)
            printf(" %d",F[n][j]);
        printf("\n");
    }
    return 0;
}
