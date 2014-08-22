//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10469 - To Carry or not to Carry
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

int main()
{
    freopen("10469 - To Carry or not to Carry.INP","r",stdin);
    freopen("10469 - To Carry or not to Carry.OUT","w",stdout);
    long long a,b;
    while(scanf(" %lld %lld ",&a,&b) == 2)
    {
        printf("%lld\n",a^b);
    }
    return 0;
}
