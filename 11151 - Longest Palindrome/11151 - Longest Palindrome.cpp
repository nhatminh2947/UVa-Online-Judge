//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11151 - Longest Palindrome
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

int tcs;
int F[1005][1005];

int DP(char s[])
{
    int sz = strlen(s);
    
    for(int i = 0 ; i < sz ; i++)
        for(int j = 0 ; j < sz ; j++)
        {
            if(i == j) F[i][j] = 1;
            else F[i][j] = 0;
        }
    
    int res = 1;
    
    for(int i = sz-1 ; i >= 0 ; i--)
        for(int j = i+1 ; j < sz ; j++)
        {
            if(s[i] == s[j]) F[i][j] = F[i+1][j-1] + 2;
            else F[i][j] = max(F[i+1][j],F[i][j-1]);
            res = max(res,F[i][j]);
        }
    
    return res;
}

int main()
{
    //freopen("11151 - Longest Palindrome.INP","r",stdin);
    //freopen("11151 - Longest Palindrome.OUT","w",stdout);
    scanf("%d",&tcs);
    getchar();
    for(int t = 1 ; t <= tcs ; t++)
    {
        char s[1005];
        gets(s);
        if(strlen(s) == 0)
            printf("0\n");
        else
        {
            int ans = DP(s);
            printf("%d\n",ans);
        }
    }
    return 0;
}
