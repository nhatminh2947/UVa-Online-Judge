//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11475 - Extend to Palindrome
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

const unsigned long C = 9999991;

unsigned long ha[100005];
unsigned long hb[100005];
unsigned long p[100005];
char s[100005];

int main()
{
    freopen("11475 - Extend to Palindrome.INP","r",stdin);
    freopen("11475 - Extend to Palindrome.OUT","w",stdout);
    while(gets(s))
    {
        int sz = strlen(s);
        ha[0] = s[0];
        p[0] = 1;
        for(int i = 1 ; i < sz ; i++)
        {
            p[i] = p[i-1] * C;
            ha[i] = ha[i-1] + s[i] * p[i];
        }
        
        reverse(s,s+sz);
        hb[0] = s[0];
        for(int i = 1 ; i < sz ; i++)
            hb[i] = hb[i-1] + s[i] * p[i];
        
        int pos = 0;
        for(int i = 0 ; i < sz ; i++)
            if((ha[i] - ha[sz-1])*p[sz-i-1] == (hb[0] - hb[sz-i-1])*p[sz-1])
            {
                pos = i;
                break;
            }
        
        reverse(s,s+sz);
        
        printf("%s",s);
        for(int i = pos-1 ; i >= 0 ; i--)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
