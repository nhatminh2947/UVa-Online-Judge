//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10013 - Super long sums
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

const int maxN=1000000;

typedef vector<int> BigNum;

int len,tcs;

void plusBN(BigNum a,BigNum b,BigNum c)
{
    int carry=0;
    int k=maxN-len;
    for(int i=maxN;i>=k;i--)
    {
        c[i]=a[i]+b[i]+carry;
        carry=c[i]/10;
        c[i]%=10;
    }
    for(int i=k;i<=maxN;i++)
    {
        if(c[i]!=0)
            while(i<=maxN)
            {
                printf("%d",c[i]);
                i++;
            }
    }
}

int main()
{
    //freopen("10013.INP","r",stdin);
    //freopen("10013.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=0;t<tcs;t++)
    {
        if(t) printf("\n");
        BigNum a(maxN+1,0),b(a),c(a);
        scanf(" %d ",&len);
        int k=maxN-len+1;
        bool check=false;
        for(int i=0;i<len;i++)
        {
            scanf(" %d %d ",&a[k],&b[k]);
            if(b[k]!=0 || a[k]!=0) check=true;
            k++;
        }
        if(!check)
        {
            printf("0\n");
            continue;
        }
        plusBN(a,b,c);
        printf("\n");
    }
    return 0;
}
