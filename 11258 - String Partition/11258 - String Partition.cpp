//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
// Verdict:
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

const unsigned long long lim = 2147483647;

int tcs;
char s[205];
unsigned long long F[205];

int main()
{
    freopen("11258 - String Partition.INP","r",stdin);
    freopen("11258 - String Partition.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 0 ; t < tcs ; t++)
    {
        scanf(" %s ",&s);
        fill(F,F+203,0);
        int sz = strlen(s);
        
        for(int i = 0 ; i < sz ; i++)
        {
            unsigned long long val = 0;
            unsigned long long p = 1;
            for(int k = i ; k >= 0 ; k--)
            {
                val = (s[k] - '0')*p + val;
                p *= 10;
                if(val > lim) break;
                F[i+1] = max(F[i+1],F[k]+val);
            }
        }
        cout << F[sz] << endl;
    }
    return 0;
}
