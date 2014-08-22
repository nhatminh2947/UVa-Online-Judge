//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10954 - Add All
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
#define int64 long long

using namespace std;

int main()
{
    freopen("10954 - Add All.INP","r",stdin);
    freopen("10954 - Add All.OUT","w",stdout);
    int n;
    while(scanf(" %d ",&n) && n)
    {
        priority_queue<int64, vector<int64>, greater<int> > q;
        
        for(int i = 0 ; i < n ; i++)
        {
            int tmp;
            scanf(" %d ",&tmp);
            q.push(tmp);
        }
        
        int64 ans = 0;
        
        while(q.size() != 1)
        {
            int64 a = q.top(); q.pop();
            int64 b = q.top(); q.pop();
            
            ans += (a + b);
            
            q.push(a+b);
        }
        
        cout << ans << endl;
    }
    return 0;
}
