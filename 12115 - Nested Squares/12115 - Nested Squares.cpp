//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12115 - Nested Squares
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

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
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
#define maxN 100000

char s[50005];
int q, r1, r2, c1, c2;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12115 - Nested Squares.INP","r",stdin);
    freopen("12115 - Nested Squares.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %s %d ",&s,&q);
        
        printf("Square %d:\n",t);
        
        int len = strlen(s);
        
        fr(k,1,q)
        {
            printf("Query %d:\n",k);
            
            scanf(" %d %d %d %d ",&r1,&c1,&r2,&c2);
            
            r1--; c1--;
            r2--; c2--;
            
            fr(i,r1,r2)
            {
                fr(j,c1,c2)
                {
                    int y = i;
                    int x = j;
                    
                    if(y >= len) y = y - 2*(y - len + 1);
                    if(x >= len) x = x - 2*(x - len + 1);
                    
                    printf("%c",s[(y>=x) ? x : y]);
                }
                puts("");
            }
        }
        
        puts("");
    }
    
    return 0;
}

