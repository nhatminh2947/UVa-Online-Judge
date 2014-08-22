//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11786 - Global Raining at Bididibus
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

char inp[10005];
int tcs;

int main()
{
    //freopen("11786 - Global Raining at Bididibus.INP","r",stdin);
    //freopen("11786 - Global Raining at Bididibus.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int ans = 0;
        gets(inp);
        int sz = strlen(inp);
        stack<int> s;
        for(int i = 0 ; i < sz ; i++)
        {
            if(inp[i] == '\\')
                s.push(i);
            else if(inp[i] == '/' && s.size() != 0)
            {
                ans += (i - s.top());
                s.pop();
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
