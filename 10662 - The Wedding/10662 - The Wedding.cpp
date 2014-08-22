//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10662 - The Wedding
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
#define maxN 100000

int T,R,H;
int a[25][25],b[25][25],c[25][25];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10662 - The Wedding.INP","r",stdin);
    freopen("10662 - The Wedding.OUT","w",stdout);
    #endif
    
    while(read3(T,R,H))
    {
        fr(i,1,T)
        {
            scanf("%d",&a[i][0]);
            fr(j,1,R) scanf("%d",&a[i][j]);
        }
        
        fr(i,1,R)
        {
            scanf("%d",&b[i][0]);
            fr(j,1,H) scanf("%d",&b[i][j]);
        }
        
        fr(i,1,H)
        {
            scanf("%d",&c[i][0]);
            fr(j,1,T) scanf("%d",&c[i][j]);
        }
        
        int m = INF;
        int I,J,K;
        I = J = K = INF;
        fr(i,1,R)
            fr(j,1,H)
                fr(k,1,T)
                {
                    if(!a[k][i] && !b[i][j] && !c[j][k])
                    {
                        if(m > a[k][0] + b[i][0] + c[j][0])
                        {
                            I = k;
                            J = i;
                            K = j;
                            m = a[k][0] + b[i][0] + c[j][0];
                        }
                    }
                }
        
        if(I == INF) puts("Don't get married!");
        else
        {
            printf("%d %d %d:%d\n",I-1,J-1,K-1,m);
        }
    }
    
    return 0;
}
