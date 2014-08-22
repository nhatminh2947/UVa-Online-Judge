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

ll num[15];
ll c[300];
string res[500];
string m[500];
ll n,k;

void init()
{
    num['0'] = 4;
    num['1'] = 3;
    num['2'] = 3;
    num['3'] = 5;
    num['4'] = 4;
    num['5'] = 4;
    num['6'] = 3;
    num['7'] = 5;
    num['8'] = 5;
    num['9'] = 4;
    
    c['A'] = c['B'] = c['C'] = '2';
    c['D'] = c['E'] = c['F'] = '3';
    c['G'] = c['H'] = c['I'] = '4';
    c['J'] = c['K'] = c['L'] = '5';
    c['M'] = c['N'] = c['O'] = '6';
    c['P'] = c['Q'] = c['R'] = c['S'] = '7';
    c['T'] = c['U'] = c['V'] = '8';
    c['W'] = c['X'] = c['Y'] = c['Z'] = '9';
    
    m['0'] = "9376";
    m['1'] = "663";
    m['2'] = "896";
    m['3'] = "84733";
    m['4'] = "3687";
    m['5'] = "3483";
    m['6'] = "749";
    m['7'] = "73836";
    m['8'] = "34448";
    m['9'] = "6463";
    
    res['0'] = "ZERO";
    res['1'] = "ONE";
    res['2'] = "TWO";
    res['3'] = "THREE";
    res['4'] = "FOUR";
    res['5'] = "FIVE";
    res['6'] = "SIX";
    res['7'] = "SEVEN";
    res['8'] = "EIGHT";
    res['9'] = "NINE";
}

int main()
{
    freopen("E.INP","r",stdin);
    freopen("E.OUT","w",stdout);

    int tcs;
    init();
    scanf(" %d ",&tcs);
    fr(t,1,tcs)
    {
        printf("Case %d: ",t);
        string s;
        cin >> s >> n >> k;
        
        string a;
        ll cnt = 0;
        string ans = "";
        rep(i,sz(s))
        {
            a += c[s[i]];
            cnt += num[a[i]];
            if(cnt >= k)
            {
                ans = res[a[i]];
                break;
            }
        }
        
        
        int p;
        for(int i = 1 ; i < n ; i++)
        {
            string b = "";
            cnt = 0;
            for(int j = 0 ; j < sz(a) ; j++)
            {
                b += m[a[j]];
                for(int u = 0 ; u < sz(m[a[j]]) ; u++)
                {
                    cnt += num[m[a[j]][u]];
                    if(cnt >= k)
                    {
                        ans = res[m[a[j]][u]];
                        break;
                    }
                }
                if(cnt >= k)
                    break;
            }
            if(cnt >= k)
                break;
            DEBUG(cnt);
            a = b;
        }
        
        p = sz(ans) - (cnt - k);
        cout << ans[p-1] << endl;
    }

    return 0;
}