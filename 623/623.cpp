//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 623 - 500!
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

const int maxN=2600;

typedef int BigNum[maxN+5];

int n;
BigNum F[1005];

void solve()
{
    F[0][maxN]=1;
    F[0][maxN-1]=-1;
    F[1][maxN]=1;
    F[1][maxN-1]=-1;
    for(int i=2;i<=1000;i++)
    {
        F[i][maxN]=0;
        int j;
        int carry=0;
        for(j=maxN;j>=0 && F[i-1][j]!=-1;j--)
        {
            F[i][j]=F[i-1][j]*i+carry;
            carry=F[i][j]/10;
            F[i][j]%=10;
        }
        while(carry)
        {
            F[i][j]=carry%10;
            carry/=10;
            j--;
        }
        F[i][j]=-1;
    }
}

int main()
{
    //freopen("623.INP","r",stdin);
    //freopen("623.OUT","w",stdout);
    solve();
    while(scanf(" %d ",&n)!=EOF)
    {
        printf("%d!\n",n);
        for(int i=maxN;i>=0;i--)
        {
            if(F[n][i]==-1)
            {
                for(int j=i+1;j<=maxN;j++)
                    printf("%d",F[n][j]);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
