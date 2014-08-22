//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12599 - Black and White
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

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 10000

char s[maxN+5];
int a[5][maxN+5];
int n;

int main()
{
    freopen("12599 - Black and White.INP","r",stdin);
    freopen("12599 - Black and White.OUT","w",stdout);

    int tcs;
    scanf(" %d ",&n);
    rep(i,n)
    {
        scanf(" %s ",&s);
        
        int sz = strlen(s);
        if(s[0] == 'W' || s[sz-1] == 'B')
        {
            puts("IMPOSSIBLE");
            continue;
        }
        
        a[1][0] = a[2][0] = 0;
        int cnt = 0;
        rep(i,sz-1)
        {
            if(s[i] == 'B' && s[i+1] == 'W') cnt++;
            if(i != 0 && s[i] == 'B')
            {
                a[1][0]++;
                a[1][a[1][0]] = i+1;
            }
            else if(s[i] == 'W')
            {
                a[2][0]++;
                a[2][a[2][0]] = i+1;
            }
        }
        if(cnt == 1)
        {
            printf("1\n");
            printf("%d",sz);
            rep(i,sz) printf(" %d",i+1);
            printf("\n");
        }
        else
        {
            printf("2\n");
            
            printf("%d 1",a[2][0]+1);
            fr(i,1,a[2][0]) printf(" %d",a[2][i]);
            printf("\n");
            
            printf("%d",a[1][0]+1);
            fr(i,1,a[1][0]) printf(" %d",a[1][i]);
            printf(" %d\n",sz);
        }
    }

    return 0;
}