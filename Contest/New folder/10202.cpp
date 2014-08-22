//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
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
#define maxN 100000

ll a[maxN+5];
ll b[maxN+5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10202.INP","r",stdin);
    freopen("10202.OUT","w",stdout);
    #endif
    int n;
    bool stop = false;
    while(scanf(" %d ",&n) == 1)
    {
        stop = false;
        int k = n*(n-1)/2;
        ll m = 0;
        fr(i,1,k)
        {
            read(a[i]);
            m += a[i];
        }
        DEBUG(m);
        sort(a+1,a+k+1);
        
        fr(i,1,k) printf("%d ",a[i]);
        printf("\n");
        
        ll sum = 0;
        
        sum = a[k-2] + a[k-1] - a[k];
        if ( sum%2 ) puts("Impossible");        
        else
        {
            b[n-2] = sum/2;
            b[n-1] = a[k-2] - b[n-2];
            b[n] = a[k-1] - b[n-2];
            int g = 3;
            int v = k - 3;
            int v2 = n;
            while ( g<=n )
            {
                int tong = 0;
                for (int i=1; i<=g; i++) tong+= a[v--];
                for (int i=1; i<=g; i++) tong-= b[v2--];
                cout << " tong = " << tong << endl;
                if ( tong%g ) {
                        puts("Impossible");
                        stop = true;
                        break;
                }
                else {
                        b[n-g] = tong/g;
                    g++;
                }
            }
        }
        if ( stop ) continue;
//        if(sum % 2) puts("Impossible");
//        else
//        {
//            sum /= 2;
//            
//            b[n-2] = a[k-1] - sum;
//            b[1] = a[n-1] - b[n-2];
//            
//            DEBUG(b[n-2]);
//            DEBUG(b[1]);
//            fr(i,2,n-1) b[i] = a[i-1] - b[1];
//            
//            printf("%d",b[1]);
//            fr(i,2,n) printf(" %d",b[i]);
//            printf("\n");
//        }
    }
    
    return 0;
}
