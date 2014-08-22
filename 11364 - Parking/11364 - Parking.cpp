//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11364 - Parking
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
#define int64 long long
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define read2(x,y) scanf(" %d %d ",&x,&y)
#define read3(x,y,z) scanf(" %d %d %d ",&x,&y,&z)
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
string s;
int a[maxN];

int main()
{
    freopen("11364 - Parking.INP","r",stdin);
    freopen("11364 - Parking.OUT","w",stdout);
    
    int tcs;
    read(tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        read(n);
        int mi = INF;
        int ma = -INF;
        for(int i = 0 ; i < n ; i++)
        {
            int k;
            read(k);
            mi = min(k,mi);
            ma = max(k,ma);
        }
        
        printf("%d\n",2*(ma-mi));
    }
    
    return 0;
}

