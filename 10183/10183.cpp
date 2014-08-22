//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10183 - How many Fibs?
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

const int maxN=200;
typedef struct
{
    int n[205];
    int l;
}BigNum;

BigNum F[505];
char a[105],b[105];

void plusBN(BigNum a, BigNum b, int c)
{
    int carry=0;
    int len=max(a.l, b.l)+1;
    F[c].l=len;
    int lim=maxN-len+1;
    fill(F[c].n+maxN-len, F[c].n+maxN+1, 0);
    for(int i=maxN; i>=lim; i--)
    {
        F[c].n[i] = a.n[i] + b.n[i] + carry;
        carry = F[c].n[i] / 10;
        F[c].n[i] %= 10;
    }
    if(F[c].n[lim]==0) F[c].l=len-1;
}

void solve()
{
    F[1].l=1;
    F[2].l=1;
    F[1].n[maxN]=1;
    F[2].n[maxN]=2;
    for(int i=3;i<=500;i++)
        plusBN(F[i-1],F[i-2],i);
}

int cmp(BigNum a,BigNum b)
{
    if(a.l>b.l) return 1;
    if(a.l<b.l) return -1;
    if(a.l==b.l)
    {
        int len=maxN-a.l+1;
        for(int i=len;i<=maxN;i++)
        {
            if(a.n[i]>b.n[i]) return 1;
            if(a.n[i]<b.n[i]) return -1;
        }
    }
    return 0;
}

int main()
{
    //freopen("10183.INP","r",stdin);
    //freopen("10183.OUT","w",stdout);
    solve();
    while(scanf(" %s %s ",&a,&b) && (a[0]!='0' || b[0]!='0'))
    {
        int la=strlen(a)-1;
        int lb=strlen(b)-1;
        int l=maxN;
        BigNum A,B;
        for(int i=la;i>=0;i--)
            A.n[l--]=a[i]-'0';
        l=maxN-l;
        A.l=l;
        l=maxN;
        for(int i=lb;i>=0;i--)
            B.n[l--]=b[i]-'0';
        l=maxN-l;
        B.l=l;
        int cnt=0;
        for(int i=1;i<480;i++)
        {
            if(F[i].l>B.l) break;\
            if(F[i].l>=A.l && cmp(A,F[i])<=0 && cmp(F[i],B)<=0)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
