//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 526 - String Distance and Transform Process
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

char s1[85],s2[85];
int F[85][85];
int cnt;

int DP()
{
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
            else F[i][j] = min(min(F[i-1][j-1],F[i-1][j]),F[i][j-1]) + 1;
        }
    
    return F[sz1][sz2];
}

void trace(int l1,int l2)
{
    if(l1 <= 0 && l2 <= 0)
        return;
    if(s1[l1-1] == s2[l2-1])
        trace(l1-1,l2-1);
    
    else if((l1 - 1 >= 0 && l2 - 1 >= 0) && F[l1][l2] == F[l1-1][l2-1] + 1)
    {
        printf("%d Replace %d,%c\n",++cnt,l1,s2[l2-1]);
        trace(l1-1,l2-1);
    }
    
    else if(l1 - 1 >= 0 && F[l1][l2] == F[l1-1][l2] + 1)
    {
        printf("%d Delete %d\n",++cnt,l1);
        trace(l1-1,l2);
    }
    
    else if(l2 - 1 >= 0 && F[l1][l2] == F[l1][l2-1] + 1)
    {
        printf("%d Insert %d,%c\n",++cnt,l1+1,s2[l2-1]);
        trace(l1,l2-1);
    }
}

int main()
{
    //freopen("526 - String Distance and Transform Process.INP","r",stdin);
    //freopen("526 - String Distance and Transform Process.OUT","w",stdout);
    int tcs = 0;
    while(gets(s1))
    {
        cnt = 0;
        if(tcs++) printf("\n");
        gets(s2);
        int ans = DP();
        printf("%d\n",ans);
        trace(strlen(s1),strlen(s2));
    }
    return 0;
}
