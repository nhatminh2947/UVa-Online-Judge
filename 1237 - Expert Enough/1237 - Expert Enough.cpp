//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1237 - Expert Enough?
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

typedef struct car
{
    string name;
    int L,H;
};


int main()
{
    freopen("1237 - Expert Enough.INP","r",stdin);
    freopen("1237 - Expert Enough.OUT","w",stdout);
    int tcs,n;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        if(t != 1)
            printf("\n");
        car A[10005];
        scanf(" %d ",&n);
        for(int i = 0 ; i < n ; i++)
        {
            cin >> A[i].name;
            scanf(" %d %d ",&A[i].L,&A[i].H);
        }
        int q,pri;
        scanf(" %d ",&q);
        for(int i = 0 ; i < q ; i++)
        {
            scanf("%d",&pri);
            
            string ans = "UNDETERMINED";
            for(int i = 0 ; i < n ; i++)
            {
                if(A[i].L <= pri && pri <= A[i].H)
                {
                    if(ans == "UNDETERMINED")
                        ans = A[i].name;
                    else if(ans != "UNDETERMINED")
                    {
                        ans = "UNDETERMINED";
                        break;
                    }
                }
            }
            
            cout << ans << endl;
        }
    }
    return 0;
}
