//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11347 - Multifactorials
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

int cnt[1005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11347 - Multifactorials.INP","r",stdin);
    freopen("11347 - Multifactorials.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    fr(t,1,tcs)
    {
        rep(i,1001) cnt[i] = 0;
        string s;
        read(s);
        
        ll ans = 1;
        ll n = 0;
        ll k = 0;
        rep(i,sz(s))
            if('0' <= s[i] && s[i] <= '9')
                n = n * 10 + s[i] - '0';
            else k++;
        
        ll m = k;
        if(n % k) m = n%k;
        ll j = 0;
        while(n - j*k >= m)
        {
            ll tmp = n - j*k;
            //DEBUG(n - j*k);
            while(tmp % 2 == 0)
            {
                cnt[2]++;
                tmp /= 2;
            }
            
            //DEBUG(tmp);
            //DEBUG(cnt[2]);
            
            for(int i = 3 ; tmp >= i ; i+=2)
            {
                while(tmp % i == 0)
                {
                    cnt[i]++;
                    tmp /= i;
                }
                //DEBUG(tmp);
                //printf("cnt[%d] = %d\n",i,cnt[i]);
            }
            
            j++;
        }
        
        bool ok = true;
        fr(i,2,1000)
        {
            ans = ans*(cnt[i]+1);
            if(ans > 1000000000000000000LL)
            {
                ok = false;
                break;
            }
        }
        
        printf("Case %d: ",t);
        if(ok) printf("%lld\n",ans);
        else puts("Infinity");
    }
    
    return 0;
}
