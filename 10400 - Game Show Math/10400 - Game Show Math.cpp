//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10400 - Game Show Math
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

const int r = 32000;

int tcs,n,res;
int data[105];
bool F[105][65000];
int sign[105];
int ch[] = {' ','+','-','*','/'};
bool ans;

void DFS(int p,int val)
{
    if(ans) return;
    if(p == n+1)
    {
        if(val == res)
        {
            printf("%d",data[1]);
            for(int i = 2 ; i <= n ; i++)
                printf("%c%d",ch[sign[i]],data[i]);
            printf("=%d",res-r);
            ans = true;
            return;
        }
        return;
    }
    if(F[p-1][val] && !ans)
    {
        if(ans) return;
        if(0 < val+data[p] && val+data[p] < 64000 && !F[p][val+data[p]])
        {
            sign[p] = 1;
            F[p][val+data[p]] = true;
            DFS(p+1,val+data[p]);
        }
        
        if(ans) return;
        if(0 < val-data[p] && val-data[p] < 64000 && !F[p][val-data[p]])
        {
            sign[p] = 2;
            F[p][val-data[p]] = true;
            DFS(p+1,val-data[p]);
        }
        
        if(ans) return;
        if(0 < ((val-r)*data[p]+r) && ((val-r)*data[p]+r) < 64000 && !F[p][(val-r)*data[p]+r])
        {
            sign[p] = 3;
            F[p][(val-r)*data[p]+r] = true;
            DFS(p+1,(val-r)*data[p]+r);
        }
        
        if(ans) return;
        if((data[p] != 0) && ((val-r)%data[p] == 0) && (0 < ((val-r)/data[p]+r)) && (((val-r)/data[p]+r) < 64000) && !F[p][(val-r)/data[p]+r])
        {
            sign[p] = 4;
            F[p][(val-r)/data[p]+r] = true;
            DFS(p+1,(val-r)/data[p]+r);
        }
    }
    return;
}

int main()
{
    //freopen("10400 - Game Show Math.INP","r",stdin);
    //freopen("10400 - Game Show Math.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        for(int i = 1 ; i <= n ; i++)
            scanf(" %d ",&data[i]);
        scanf(" %d ",&res);
        res += r;
        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j <= 64000 ; j++)
                F[i][j] = false;
        
        F[1][data[1]+r] = true;
        ans = false;
        
        DFS(2,data[1]+r);
        
        if(!ans) printf("NO EXPRESSION");
        printf("\n");
    }
    return 0;
}
