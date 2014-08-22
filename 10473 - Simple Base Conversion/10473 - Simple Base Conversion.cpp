//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10473 - Simple Base Conversion
// Verdict: Accepte
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



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10473 - Simple Base Conversion.INP","r",stdin);
    freopen("10473 - Simple Base Conversion.OUT","w",stdout);
    #endif
    string s;
    while(read(s) && s[0] != '-')
    {
        if(s[0] == '0' && s[1] == 'x')
        {
            ll n = 0;
            
            for(int i = 2 ; i < sz(s) ; i++)
            {
                ll m;
                if('A' <= s[i] && s[i] <= 'F')
                    m = s[i] - 'A' + 10;
                else m = s[i] - '0';
                
                n = n*16 + m;
            }
            
            cout << n << endl;
        }
        else
        {
            stack<ll> stk;
            ll n = 0;
            for(int i = 0 ; i < sz(s) ; i++)
                n = n * 10 + s[i] - '0';
            
            cout << "0x";
            if(n == 0) cout << "0";
            while(n)
            {
                stk.push(n%16);
                n /= 16;
            }
            
            while(!stk.empty())
            {
                if(stk.top() >= 10) cout << char('A' + stk.top() - 10);
                else cout << stk.top();
                stk.pop();
            }
            cout << endl;
        }
    }
    
    return 0;
}
