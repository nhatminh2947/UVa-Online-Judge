//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 495 - Fibonacci Freeze
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
#define INF 999999999
#define PI 3,1415926535

#define sizeA 1500

using namespace std;

typedef char BigNum[2000];

int n;
BigNum F[5005];

void plusBN(BigNum a,BigNum b,BigNum c)
{
    char carry='0';
    for(int i=sizeA;i>=0;i--)
    {
        c[i]=(a[i]-'0'+b[i]-'0'+carry-'0')+'0';
        carry=((c[i]-'0')/10)+'0';
        c[i]-='0';
        c[i]%=10;
        c[i]+='0';
    }
}

void solve()
{
    for(int i=0;i<=5000;i++)
        fill(F[i],F[i]+sizeA+1,'0');
    F[1][sizeA]='1';
    for(int i=2;i<=5000;i++)
        plusBN(F[i-1],F[i-2],F[i]);
}

int main()
{
    //freopen("495.INP","r",stdin);
    //freopen("495.OUT","w",stdout);
    solve();
    while(scanf(" %d ",&n)==1)
    {
        printf("The Fibonacci number for %d is ",n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        for(int i=0;i<=sizeA;i++)
        {
            if(F[n][i]!='0')
            {
                while(i<=sizeA)
                {
                    printf("%c",F[n][i]);
                    i++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
