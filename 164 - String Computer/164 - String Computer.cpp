//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 164 - String Computer
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

char s1[25];
char s2[25];
int F[25][25];

void trace(int sz1,int sz2)
{
    if(sz1 <= 0 && sz2 <= 0)
        return;
    
    if(s1[sz1-1] == s2[sz2-1])
        trace(sz1-1,sz2-1);
    else if((sz1-1 >= 0 && sz2-1 >= 0) && F[sz1][sz2] == F[sz1-1][sz2-1] + 1)
    {
        printf("C%c%.2d",s2[sz2-1],sz1);
        trace(sz1-1,sz2-1);
    }
    else if(sz1-1 >= 0 && F[sz1][sz2] == F[sz1-1][sz2] + 1)
    {
        printf("D%c%.2d",s1[sz1-1],sz1);
        trace(sz1-1,sz2);
    }
    else if(sz2-1 >= 0 && F[sz1][sz2] == F[sz1][sz2-1] + 1)
    {
        printf("I%c%.2d",s2[sz2-1],sz1+1);
        trace(sz1,sz2-1);
    }
}

int main()
{
    //freopen("164 - String Computer.INP","r",stdin);
    //freopen("164 - String Computer.OUT","w",stdout);
    while(scanf(" %s ",&s1))
    {
        if(s1[0] == '#') break;
        scanf(" %s ",&s2);
        
        int sz1 = strlen(s1);
        int sz2 = strlen(s2);
        
        for(int i = 0 ; i <= sz1 ; i++)
            for(int j = 0 ; j <= sz2 ; j++)
                F[i][j] = 0;
        
        for(int i = 0 ; i <= sz1 ; i++)
            F[i][0] = i;
        for(int j = 0 ; j <= sz2 ; j++)
            F[0][j] = j;
        
        for(int i = 1 ; i <= sz1 ; i++)
            for(int j = 1 ; j <= sz2 ; j++)
            {
                if(s1[i-1] == s2[j-1]) F[i][j] = F[i-1][j-1];
                else F[i][j] = min(F[i-1][j],min(F[i-1][j-1],F[i][j-1])) + 1;
            }
        trace(sz1,sz2);
        printf("E\n");
    }
    return 0;
}
