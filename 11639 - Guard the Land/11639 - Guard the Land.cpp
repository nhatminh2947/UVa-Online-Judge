//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11639 - Guard the Land
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

int cnt[105][105];
int u1,u2,v1,v2;
int tcs;

int main()
{
    //freopen("11639 - Guard the Land.INP","r",stdin);
    //freopen("11639 - Guard the Land.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        for(int i = 0 ; i <= 100 ; i++)
            for(int j = 0 ; j <= 100 ; j++)
                cnt[i][j] = 0;
        
        scanf(" %d %d %d %d ",&u1,&v1,&u2,&v2);
        for(int i = v1 ; i < v2 ; i++)
            for(int j = u1 ; j < u2 ; j++)
                cnt[i][j]++;
        
        scanf(" %d %d %d %d ",&u1,&v1,&u2,&v2);
        
        for(int i = v1 ; i < v2 ; i++)
            for(int j = u1 ; j < u2 ; j++)
                cnt[i][j]++;
        
        int uns = 0;
        int weak = 0;
        int strong = 0;
        for(int i = 0 ; i < 100 ; i++)
            for(int j = 0 ; j < 100 ; j++)
            {
                if(cnt[i][j] == 0)
                    uns++;
                else if(cnt[i][j] == 1)
                    weak++;
                else if(cnt[i][j] == 2)
                    strong++;
            }
        printf("Night %d: %d %d %d\n",t,strong,weak,uns);
    }
    return 0;
}
