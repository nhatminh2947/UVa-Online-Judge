//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10405 - Longest Common Subsequence
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

char s1[1005],s2[1005];
int F[1005][1005];

int main()
{
    //freopen("10405 - Longest Common Subsequence.INP","r",stdin);
    //freopen("10405 - Longest Common Subsequence.OUT","w",stdout);
    while(gets(s1))
    {
        gets(s2);
        int sz1 = strlen(s1);
        int sz2 = strlen(s2);
        for(int i = 0 ; i <= sz1 ; i++)
            F[i][0] = 0;
        for(int j = 0 ; j <= sz2 ; j++)
            F[0][j] = 0;
        
        for(int i = 1 ; i <= sz1 ; i++)
        {
            for(int j = 1 ; j <= sz2 ; j++)
            {
                if(s1[i-1] == s2[j-1])
                    F[i][j] = F[i-1][j-1] + 1;
                else F[i][j] = max(F[i-1][j],F[i][j-1]);
            }
        }
        
        printf("%d\n",F[sz1][sz2]);
    }
    return 0;
}
