//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 443 - Humble Numbers
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

int res[5845];
int n;

void solve()
{
    int cnt=1;
    
    long long x=1,y=1,z=1,t=1;
    for(int i=0;i<=30 && cnt<=5842;i++)
    {
        if(i)
            x*=2;
        y=1;
        for(int j=0;j<=19 && cnt<=5842 && x*y<=2000000000;j++)
        {
            if(j)
                y*=3;
            z=1;
            for(int k=0;k<=13 && cnt<=5842 && x*y*z<=2000000000;k++)
            {
                if(k)
                    z*=5;
                t=1;
                for(int l=0;l<=11 && cnt<=5842 && x*y*z*t<=2000000000;l++)
                {
                    if(l)
                        t*=7;
                    if(x*y*z*t<=2000000000)
                        res[cnt++]=x*y*z*t;
                }
            }
        }
    }
    sort(res+1,res+5843);
}

int main()
{
    //freopen("443.INP","r",stdin);
    //freopen("443.OUT","w",stdout);
    solve();
    while(scanf(" %d ",&n) && n)
    {
        char c[5];
        strcpy(c,"th");
        if(n%10==1 && n%100!=11)
            strcpy(c,"st");
        if(n%10==2 && n%100!=12)
            strcpy(c,"nd");
        if(n%10==3 && n%100!=13)
            strcpy(c,"rd");
        printf("The %d",n);
        printf("%s",c);
        printf(" humble number is %d.\n",res[n]);
    }
    return 0;
}
