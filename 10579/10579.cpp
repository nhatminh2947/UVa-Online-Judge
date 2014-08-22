//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10579 - Fibonacci Numbers
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

typedef char BigNum[1005];
const int sizeA=1000;
char n[10];

BigNum F[5005];

void plusBN(BigNum a,BigNum b,BigNum c)
{
    char carry='0';
    for(int i=sizeA;i>=0;i--)
    {
        c[i]=a[i]-'0'+b[i]-'0'+carry;
        carry=((c[i]-'0')/10)+'0';
        c[i]-='0';
        c[i]%=10;
        c[i]+='0';
    }
    for(int i=0;i<=sizeA;i++)
    {
        if(c[i]!='0')
        {
            while(i<=sizeA)
            {
                printf("%c",c[i]);
                i++;
            }
        }
    }
    printf("\n");
}

void solve()
{
    for(int i=0;i<=5000;i++)
        fill(F[i],F[i]+sizeA+1,'0');
    F[1][sizeA]='1';
    F[2][sizeA]='2';
    for(int i=3;i<=5000;i++)
        plusBN(F[i-1],F[i-2],F[i]);
}

int main()
{
    freopen("10579.INP","r",stdin);
    freopen("10579.OUT","w",stdout);
    solve();
    while(gets(n))
    {
        if(n-'0'==0)
        {
            printf("0\n");
            continue;
        }
        else
        {
            int k=0;
            int len=strlen(n);
            for(int i=0;i<len;i++)
                k=k*10+(n[i]-'0');
            for(int i=0;i<=sizeA;i++)
            {
                if(F[k][i]!='0')
                {
                    while(i<=sizeA)
                    {
                        printf("%c",F[k][i]);
                        i++;
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
