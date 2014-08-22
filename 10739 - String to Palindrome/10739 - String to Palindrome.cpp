//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10739 - String to Palindrome
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

int tcs;
char s[1005];
int F[1005][1005];

int main()
{
    //freopen("10739 - String to Palindrome.INP","r",stdin);
    //freopen("10739 - String to Palindrome.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("Case %d: ",t);
        scanf(" %s ",&s);
        
        int sz = strlen(s);
        for(int i = 0 ; i <= sz ; i++)
            for(int j = 0 ; j <= sz ; j++)
                F[i][j] = 0;
        
        for(int i = sz-1 ; i >= 0 ; i--)
            for(int j = i+1 ; j < sz ; j++)
            {
                if(s[i] == s[j])
                    F[i][j] = F[i+1][j-1];
                else F[i][j] = min(F[i+1][j],min(F[i+1][j-1],F[i][j-1])) + 1;
            }
        
        printf("%d\n",F[0][sz-1]);
    }
    return 0;
}
