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

int n;
ll a[40];
int fone[40];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E.INP","r",stdin);
    freopen("E.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        read(n);
        ll m = -(INF*100LL);
        rep(i,n)
        {
            read(a[i]);
            ll k = a[i];
            m = max(m,k);
            int cnt = 0;
            while(k)
            {
                if(k%2) fone[i] = cnt;
                cnt++;
                k /= 2;
            }
        }
        
        int cnt = 0;
        ll tmp = m;
        int zero = 0;
        while(tmp)
        {
            if(tmp%2 == 0) zero = cnt;
            cnt++;
            tmp /= 2;
        }
        
        while(1)
        {
            bool check = false;
            rep(i,n) 
            {
                if(fone[i] == zero)
                {
                    check = true;
                    ll k = m;
                    k = k & a[i];
                    
                    m = max(m,k);
                }
            }
            
            if(!check) break;
            cnt = 0;
            tmp = m;
            zero = 0;
            while(tmp)
            {
                if(tmp%2 == 0) zero = cnt;
                cnt++;
                tmp /= 2;
            }
        }
        
        cout << m << endl;
    }

    return 0;
}