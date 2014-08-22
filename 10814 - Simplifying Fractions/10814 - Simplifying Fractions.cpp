//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10814 - Simplifying Fractions
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

string dv(string n)
{
    int m = 0;
    int a[35];
    int j = 0;
    rep(i,sz(n))
    {
        m = m*10 + n[i] - '0';
        
        a[j++] = m/2;
        m = m%2;
    }
    
    string ans = "";
    rep(i,j)
    {
        string tmp = "";
        DEBUG(a[i]);
        
        if(a[i] == 0)
        {
            if(!ans.empty())
                ans += '0';
            continue;
        }
        while(a[i])
        {
            tmp = char(a[i]%10 + '0') + tmp;
            a[i] /= 10;
        }
        
        ans += tmp;
    }
    
    return ans;
}

    

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10814 - Simplifying Fractions.INP","r",stdin);
    freopen("10814 - Simplifying Fractions.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        string k = dv("1000");
        DEBUG(k);
    }
    
    return 0;
}
