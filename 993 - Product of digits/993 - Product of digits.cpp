//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 993 - Product of digits
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

int p[] = {2,3,5,7};
int cnt[10];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("993 - Product of digits.INP","r",stdin);
    freopen("993 - Product of digits.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        int n;
        read(n);
        if(n == 1 || n == 0)
        {
            printf("%d\n",n);
            continue;
        }
        
        rep(i,10) cnt[i] = 0;
        
        rep(i,4)
        {
            while(n % p[i] == 0)
            {
                n /= p[i];
                cnt[p[i]]++;
            }
        }
        
        if(n != 1) puts("-1");
        else
        {
            vi ans;
            while(cnt[3] > 1)
            {
                cnt[3] -= 2;
                ans.pb(9);
            }
            
            while(cnt[2] > 2)
            {
                cnt[2] -= 3;
                ans.pb(8);
            }
            
            while(cnt[2] > 0 && cnt[3] > 0)
            {
                cnt[2]--;
                cnt[3]--;
                ans.pb(6);
            }
            
            while(cnt[2] > 1)
            {
                cnt[2] -= 2;
                ans.pb(4);
            }
            
            rep(i,4)
                while(cnt[p[i]])
                {
                    ans.pb(p[i]);
                    cnt[p[i]]--;
                }
            
            sort(all(ans));
            rep(i,sz(ans)) printf("%d",ans[i]);
            printf("\n");
        }
    }
    
    return 0;
}
