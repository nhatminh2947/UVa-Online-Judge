//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11362 - Phone List
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
#define maxN 123456
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs,n;
string data[10005];

int main()
{
    //freopen("11362.INP","r",stdin);
    //freopen("11362.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        for(int i=0;i<n;i++)
            cin>>data[i];
            
        sort(data,data+n);
        
        bool ans=true;
        for(int i=0;i<n-1 && ans;i++)
        {
            if(data[i+1].compare(0,data[i].size(),data[i])==0)
                ans=false;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
