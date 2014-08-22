//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 120 - Stacks of Flapjacks
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
#define i64 long long
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

int main()
{
    freopen("120 - Stacks of Flapjacks.INP","r",stdin);
    freopen("120 - Stacks of Flapjacks.OUT","w",stdout);
    
    char s[3005];
    while(gets(s))
    {
        int sz = strlen(s);
        int a[135];
        int n = 0, cnt = 0;
        int b[135];
        for(int i = 0 ; i < sz ; i++)
        {
            if(s[i] != ' ')
                n = n*10 + (s[i] - '0');
            else if(s[i] == ' ')
            {
                cnt++;
                a[cnt] = b[cnt] = n;
                printf("%d ",n);
                n = 0;
            }
        }
        cnt++;
        a[cnt] = b[cnt] = n;
        printf("%d\n",n);
        sort(b+1,b+cnt+1);
        int c[135];
        for(int i = 1 ; i <= cnt ; i++)
            c[b[i]] = i;
        for(int i = 1 ; i <= cnt ; i++)
            a[i] = c[a[i]];
        for(int i = cnt ; i >= 1 ; i--)
        {
            for(int j = 1 ; j <= cnt ; j++)
            {
                if(a[j] == i)
                {
                    if(j == i)
                        continue;
                    if(j != 1)
                    {
                        int pos = cnt - j + 1;
                        for(int k = 1 ; k <= (j+1)/2 ; k++)
                            swap(a[k],a[j - k + 1]);
                        printf("%d ",pos);
                    }
                    printf("%d ",cnt - i + 1);
                    for(int k = 1 ; k <= (i+1)/2 ; k++)
                        swap(a[k],a[i-k+1]);
                }
            }
        }
        printf("0\n");
    }
    return 0;
}

