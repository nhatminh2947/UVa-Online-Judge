//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10137 - The Trip
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

int n;
double a[1005];

int main()
{
    freopen("10137 - The Trip.INP","r",stdin);
    freopen("10137 - The Trip.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
        //DEBUG(n);
        double av = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf(" %lf ",&a[i]);
            av += a[i];
        }
        av /= n;
        //printf(" %lf\n",av);
        
        double pos = 0, neg = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(a[i] > av)
                pos += (double)(int)((a[i] - av)*100)/100.0;
            else neg += (double)(int)((av - a[i])*100)/100.0;
        }
        //DEBUG(pos);
        //DEBUG(neg);
        printf("$%.2lf\n",max(pos,neg));
    }
    return 0;
}

