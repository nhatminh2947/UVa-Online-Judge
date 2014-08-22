//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 541 - Error Correction
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
#define int64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

int a[105][105];
int row[105],col[105];

int main()
{
	freopen("541 - Error Correction.INP","r",stdin);
	freopen("541 - Error Correction.OUT","w",stdout);
	
	int n;
	while(scanf(" %d ",&n) && n)
	{
	    int tmp;
	    for(int i = 1 ; i <= n ; i++)
            row[i] = col[i] = 0;
	    
	    for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
            {
                scanf(" %d ",&tmp);
                row[i] += tmp;
                col[j] += tmp;
            }
        
        int x,y;
        int r = 0,c = 0;
        for(int i = 1 ; i <= n && (r < 2 && c < 2); i++)
        {
            if(row[i] % 2)
            {
                r++;
                y = i;
            }
            if(col[i] % 2)
            {
                c++;
                x = i;
            }
        }
        
        if(!r && !c)
            printf("OK\n");
        else if(r == 1 && c == 1)
            printf("Change bit (%d,%d)\n",y,x);
        else printf("Corrupt\n");
	}
	

	return 0;
}

