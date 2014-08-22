//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11689 - Soda Surpler
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs;
int e,f,c;

int main()
{
    //freopen("11689.INP","r",stdin);
    //freopen("11689.OUT","w",stdout);
    scanf(" %d ", &tcs);
    for(int t=0; t<tcs; t++)
    {
        scanf(" %d %d %d ", &e, &f, &c);
        int k=e+f;
        int carry=0;
        int ans=0;
        while(k>=c)
        {
            ans+=k/c;
            carry=k%c;
            k=k/c+carry;
        }
        printf("%d\n",ans);
    }
    return 0;
}
