//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10100 - Longest Match
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

map<string,int> enc;
char s1[25000];
char s2[25000];
int a[1005],b[1005];
int F[1005][1005];

int DP(int l1,int l2)
{
    for(int i = 0 ; i <= l1 ; i++)
        F[i][0] = 0;
    for(int j = 0 ; j <= l2 ; j++)
        F[0][j] = 0;
    
    for(int i = 1 ; i <= l1 ; i++)
        for(int j = 1 ; j <= l2 ; j++)
        {
            if(a[i] == b[j])
                F[i][j] = F[i-1][j-1] + 1;
            else F[i][j] = max(F[i-1][j],F[i][j-1]);
        }
    
    return F[l1][l2];
}

int main()
{
    freopen("10100 - Longest Match.INP","r",stdin);
    freopen("10100 - Longest Match.OUT","w",stdout);
    int tcs = 1;
    while(gets(s1))
    {
        enc.clear();
        printf("%2d. ",tcs++);
        gets(s2);
        int sz1 = strlen(s1);
        int sz2 = strlen(s2);
        if(sz1 == 0 || sz2 == 0)
        {
            printf("Blank!\n");
            continue;
        }
        int cnt = 1;
        int l1 = 0;
        int l2 = 0;
        for(int i = 0 ; i < sz1 ; i++)
        {
            string tmp = "";
            while(isalnum(s1[i]))
            {
                tmp += s1[i];
                i++;
            }
            if(tmp.size() != 0)
            {
                l1++;
                if(!enc[tmp]) enc[tmp] = cnt++;
                a[l1] = enc[tmp];
                i--;
            }
        }
        
        for(int i = 0 ; i < sz2 ; i++)
        {
            string tmp = "";
            while(isalnum(s2[i]))
            {
                tmp += s2[i];
                i++;
            }
            if(tmp.size() != 0)
            {
                l2++;
                if(!enc[tmp]) enc[tmp] = cnt++;
                b[l2] = enc[tmp];
                i--;
            }
        }
        
        int ans = DP(l1,l2);
        printf("Length of longest match: %d\n",ans);
    }
    return 0;
}
