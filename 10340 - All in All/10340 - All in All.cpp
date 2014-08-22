//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10340 - All in All
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

using namespace std;

char s1[1000005],s2[1000005];

int main()
{
    freopen("10340 - All in All.INP","r",stdin);
    freopen("10340 - All in All.OUT","w",stdout);
    while(scanf(" %s %s ",&s1,&s2) == 2)
    {
        int sz1 = strlen(s1);
        int sz2 = strlen(s2);
        
        bool ans = false;
        int k = 0;
        for(int i = 0 ; i < sz2 ; i++)
            if(s2[i] == s1[k])
            {
                k++;
                if(k == sz1)
                    break;
            }
        
        if(k == sz1)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
