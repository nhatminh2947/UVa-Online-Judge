//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 714 - Copying Books
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

ll n,p;
ll a[505];
bool check[505];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("714 - Copying Books.INP","r",stdin);
    freopen("714 - Copying Books.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    rep(t,tcs)
    {
        read2(n,p);
        
        fr(i,1,n) read(a[i]);
        
        ll lo = 0;
        ll hi = 6000000000LL;
        ll ans = 0;
        while(lo <= hi)
        {
            ll mid = (lo + hi)/2;
            
            ll sum = 0;
            ll cnt = 1;
            bool ok = true;
            
            fr(i,1,n)
            {
                if(a[i] > mid)
                {
                    ok = false;
                    break;
                }
                if(sum + a[i] > mid)
                {
                    //DEBUG(sum);
                    sum = a[i];
                    cnt++;
                }
                else sum += a[i];
            }
            
            if(!ok || sum > mid)
            {
                lo = mid + 1;
                continue;
            }
            
            //printf("mid = %lld cnt = %lld\n",mid,cnt);
            
            if(cnt <= p)
            {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        //cout << ans << endl;
        
        fr(i,1,n) check[i] = false;
        
        ll sum = 0;
        int sl = p-1;
        int k = n;
        dw(i,n,1)
        {
            if(sl == k)
            {
                check[i+1] = true;
                continue;
            }
            if(sum + a[i] > ans)
            {
                sl--;
                check[i+1] = true;
                sum = a[i];
            }
            else sum += a[i];
            k--;
        }
        
        fr(i,1,n)
        {
            if(i != 1) printf(" ");
            if(check[i]) printf("/ ");
            printf("%lld",a[i]);
        }
        printf("\n");
    }
    
    return 0;
}
