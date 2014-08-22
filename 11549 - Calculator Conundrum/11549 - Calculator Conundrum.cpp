//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11549 - Calculator Conundrum
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
#define maxN 300000

int n,k;

int f(int x)
{
    ll tmp = 1LL*x*x;
    ll m = tmp;
    
    int cnt = 0;
    while(tmp)
    {
        tmp /= 10;
        cnt++;
    }
    
    while(cnt > n)
    {
        m /= 10;
        cnt--;
    }
    
    return (int)m;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11549 - Calculator Conundrum.INP","r",stdin);
    freopen("11549 - Calculator Conundrum.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&k);
        
        int a = k;
        int b = k;
        int ans = a;
        
        do
        {
            a = f(a);
            b = f(f(b));
            ans = max(a,ans);
        }while(a != b);
        
        do
        {
            a = f(a);
            ans = max(a,ans);
        }while(a != b);
        
        printf("%d\n",ans);
    }
    
    return 0;
}


