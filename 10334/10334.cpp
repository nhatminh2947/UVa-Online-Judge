//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10334 - Ray Through Glasses
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

const int maxN=220;

typedef int BigNum[250];
BigNum F[1005];
int n;

void plusBN(BigNum a, BigNum b, BigNum c)
{
    int carry = 0;
    fill(c,c+maxN,0);
    for(int i = maxN-1; i >= 0; i--)
    {
        c[i] = a[i] + b[i] + carry;
        carry = c[i] / 10;
        c[i] %= 10;
    }
}

void fibo()
{
    fill(F[0],F[0]+maxN,0);
    fill(F[1],F[1]+maxN,0);
    fill(F[2],F[2]+maxN,0);
    F[0][maxN-1]=1;
    F[1][maxN-1]=2;
    for(int i=2;i<=1000;i++)
        plusBN(F[i-1],F[i-2],F[i]);
}

int main()
{
    //freopen("10334.INP","r",stdin);
    //freopen("10334.OUT","w",stdout);
    fibo();
    while(scanf(" %d ",&n)==1)
    {
        int i;
        for(i=0;i<maxN;i++)
            if(F[n][i]!=0) break;
        for(i;i<maxN;i++)
            printf("%d",F[n][i]);
        printf("\n");
    }
    return 0;
}
