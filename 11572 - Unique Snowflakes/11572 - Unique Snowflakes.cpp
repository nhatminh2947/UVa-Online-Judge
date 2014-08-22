//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11572 - Unique Snowflakes
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
map<int,bool> m;
deque<int> dq;

int main()
{
    freopen("11572 - Unique Snowflakes.INP","r",stdin);
    freopen("11572 - Unique Snowflakes.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        m.clear();
        dq.clear();
        int ans = -INF;
        for(int i = 0 ; i < n ; i++)
        {
            int k;
            scanf(" %d ",&k);
            if(m[k] == false)
            {
                m[k] = true;
                dq.pb(k);
            }
            else
            {
                //DEBUG(cnt);
                ans = max(ans,(int)dq.size());
                while(dq.front() != k)
                {
                    m[dq.front()] = false;
                    dq.pop_front();
                }
                dq.pop_front();
                dq.pb(k);
                m[k] = true;
            }
        }
        //DEBUG(cnt);
        ans = max((int)dq.size(),ans);
        printf("%d\n",ans);
    }
    
    return 0;
}

