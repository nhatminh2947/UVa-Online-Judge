//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 932 - Checking the N-Queens Problem
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

const int err = 40;

int n;
char data[35][35];
bool row[35],col[35],lef[100],rig[100];
int point[35];
int cnt;
bool ans;

void backtrack(int y,int x)
{
    if(cnt == n && !ans)
    {
        ans = true;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                if(point[i] == j)
                    printf("X");
                else printf("0");
            printf("\n");
        }
    }
    
    for(int j = 0 ; j < n ; j++)
    {
        if(!row[y+1] && !col[j] && !rig[err+y+1-j] && !lef[y+1+j])
        {
            row[y+1] = col[j] = rig[err+y+1-j] = lef[y+1+j] = true;
            point[y+1] = j;
            cnt++;
            backtrack(y+1,j);
            cnt--;
            row[y+1] = col[j] = rig[err+y+1-j] = lef[y+1+j] = false;
        }
    }
}

int main()
{
    freopen("932 - Checking the N-Queens Problem.INP","r",stdin);
    freopen("932 - Checking the N-Queens Problem.OUT","w",stdout);
    int tcs = 0;
    while(scanf(" %d ",&n) == 1)
    {
        if(tcs++) printf("\n");
        fill(row,row+n,0);
        fill(col,col+n,0);
        fill(lef,lef+n+n,0);
        fill(rig,rig+err+n,0);
        
        bool YES = true;
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                scanf(" %c ",&data[i][j]);
                if(data[i][j] == 'X')
                {
                    if(row[i] || col[j] || rig[err+i-j] || lef[i+j])
                        YES = false;
                    else row[i] = col[j] = rig[err+i-j] = lef[i+j] = true;
                }
            }
        
        if(YES) printf("YES\n");
        else
        {
            printf("NO\n");
            printf("YES\n");
            fill(row,row+n,0);
            fill(col,col+n,0);
            fill(lef,lef+n+n,0);
            fill(rig,rig+err+n,0);
            cnt = 0;
            ans = false;
            for(int j = 0 ; j < n ; j++)
            {
                row[0] = col[j] = rig[err-j] = lef[j] = true;
                point[0] = j;
                cnt++;
                backtrack(0,j);
                if(ans) break;
                cnt--;
                row[0] = col[j] = rig[err-j] = lef[j] = false;
            }
        }
        
    }
    return 0;
}
