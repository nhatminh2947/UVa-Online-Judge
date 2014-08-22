//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 531 - Compromise
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

string str[105];
map<string,int> enc;
int a[105],b[105];
int F[105][105];

void DP(int l1,int l2)
{
    for(int i = 0 ; i <= l1 ; i++)
        F[i][0] = 0;
    for(int j = 0 ; j <= l2 ; j++)
        F[0][j] = 0;
    
    for(int i = 1 ; i <= l1 ; i++)
        for(int j = 1 ; j <= l2 ; j++)
            if(a[i] == b[j])
                F[i][j] = F[i-1][j-1] + 1;
            else F[i][j] = max(F[i-1][j],F[i][j-1]);
}

void trace(int i, int j,int k)
{
    if(i <= 0 || j <= 0)
        return;
    
    if((F[i][j] == F[i-1][j-1] + 1) && a[i] == b[j])
    {
        trace(i-1,j-1,k+1);
        cout << str[a[i]];
        if(k) printf(" ");
    }
    else if(F[i-1][j] > F[i][j-1])
        trace(i-1,j,k);
    else trace(i,j-1,k);
}

int main()
{
    //freopen("531 - Compromise.INP","r",stdin);
    //freopen("531 - Compromise.OUT","w",stdout);
    char tmp[35];
    while(scanf(" %s ",&tmp) == 1)
    {
        enc.clear();
        int cnt = 1;
        int l1 = 0,l2 = 0;
        if(tmp[0] != '#')
        {
            l1 = 1;
            str[cnt] = tmp;
            enc[tmp] = cnt++;
            a[l1] = enc[tmp];
            while(scanf(" %s ",&tmp) && tmp[0] != '#')
            {
                if(!enc[tmp])
                {
                    str[cnt] = tmp;
                    enc[tmp] = cnt++;
                }
                a[++l1] = enc[tmp];
            }
        }
        
        while(scanf(" %s ",&tmp) && tmp[0] != '#')
        {
            if(!enc[tmp])
            {
                str[cnt] = tmp;
                enc[tmp] = cnt++;
            }
            b[++l2] = enc[tmp];
        }
        DP(l1,l2);
        trace(l1,l2,0);
        printf("\n");
    }
    return 0;
}
