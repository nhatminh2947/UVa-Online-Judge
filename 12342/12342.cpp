//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 12342
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

int tcs;
double k;

int main()
{
    //freopen("12342.INP","r",stdin);
    //freopen("12342.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %lf ",&k);
        double sum = 0;
        
        if(k <= 180000)
        {
            printf("Case %d: 0\n",t);
            continue;
        }
        
        k -= 180000;
        
        if(k > 0)
        {
            double tmp = k*10/100;
            if(k > 300000)
                sum += 30000;
            else sum += tmp;
            
            k -= 300000;
        }
        
        if(k > 0)
        {
            double tmp = k*15/100;
            if(k > 400000)
                sum += 60000;
            else sum += tmp;
            
            k -= 400000;
        }
        
        if(k > 0)
        {
            double tmp = k*20/100;
            if(k > 300000)
                sum += 60000;
            else sum += tmp;
            
            k -= 300000;
        }
        
        if(k > 0)
        {
            double tmp = k*25/100;
            sum += tmp;
        }
        
        sum = max(2000.0,sum);
        
        printf("Case %d: %.lf\n",t,ceil(sum));
    }
    return 0;
}
