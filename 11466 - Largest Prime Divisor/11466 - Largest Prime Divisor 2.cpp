//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11466 - Largest Prime Divisor
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

ll n;
char s[20];

int main()
{
    freopen("11466 - Largest Prime Divisor.INP","r",stdin);
    freopen("11466 - Largest Prime Divisor.OUT","w",stdout);

    while(scanf("%s",&s))
    {
        int sz = strlen(s);
        n = 0;
        int k = 0;
        if(s[0] == '-')
            k++;
        for(int i = k ; i < sz ; i++)
            n = n*10 + (s[i]-'0');
        
        if(n == 0)
            break;
        int cnt = 0;
        if(n % 2 == 0)
        {
            cnt++;
            while(n%2 == 0)
                n /= 2;
        }
        
        ll ans = 0;
        for(ll i = 3 ; i <= (ll)sqrt(n) ; i+=2)
        {
            if(n % i == 0)
            {
                ans = i;
                cnt++;
                while(n%i == 0)
                    n /= i;
            }
        }
        
        if(cnt >= 1 && n != 1) printf("%lld\n",n);
        else if(cnt >= 2 && n == 1) printf("%lld\n",ans);
        else puts("-1");
    }

    return 0;
}