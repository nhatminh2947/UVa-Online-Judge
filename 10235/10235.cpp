//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10235 - Simply Emirp
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

bool check[1000005];
char n[10];
char res[][15]={"is not prime.","is prime.","is emirp."};

void sieve()
{
    for(int i=2;i<=1000000;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(int i=2;i<=1000000;i++)
        if(check[i])
            for(int j=2;j*i<=1000000;j++)
                check[i*j]=false;
}

int convert(char n[])
{
    int k=0;
    int len=strlen(n);
    for(int i=0;i<len;i++)
        k=k*10+(n[i]-'0');
    return k;
}

int rev(char n[])
{
    int len=strlen(n);
    reverse(n,n+len);
    return convert(n);
}

int main()
{
    freopen("10235.INP","r",stdin);
    freopen("10235.OUT","w",stdout);
    sieve();
    while(scanf(" %s ",&n)==1)
    {
        char tmp[10];
        strcpy(tmp,n);
        int k=convert(tmp);
        int ans=0;
        if(check[k])
        {
            ans=1;
            int m=rev(tmp);
            if(check[m] && m!=k)
                ans=2;
        }
        printf("%s %s\n",n,res[ans]);
    }
    return 0;
}
