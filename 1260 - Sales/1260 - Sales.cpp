//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1260 - Sales
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
#include <cctype>
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

int main()
{
    freopen("1260 - Sales.INP","r",stdin);
    freopen("1260 - Sales.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int sz;
        int a[1005];
        scanf(" %d ",&sz);
        for(int i = 0 ; i < sz ; i++)
            scanf(" %d ",&a[i]);
        
        int ans = 0;
        for(int i = 1 ; i < sz ; i++)
        {
            int cnt = 0;
            for(int j = 0 ; j < i ; j++)
                if(a[j] <= a[i])
                    cnt++;
            ans += cnt;
        }
        
        cout << ans << endl;
    }
    return 0;
}
