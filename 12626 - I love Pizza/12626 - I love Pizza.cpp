//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12626 - I love Pizza
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



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12626 - I love Pizza.INP","r",stdin);
    freopen("12626 - I love Pizza.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    rep(t,tcs)
    {
        char s[605];
        int cnt[300];
        fr(i,'A','Z') cnt[i] = 0;
        scanf(" %s ",&s);
        
        int len = strlen(s);
        
        rep(i,len) cnt[s[i]]++;
        
        int A = cnt['A'] / 3;
        int R = cnt['R'] / 2;
        int M = cnt['M'];
        int G = cnt['G'];
        int I = cnt['I'];
        int T = cnt['T'];
        
        int ans = min(min(min(min(min(I,T),G),R),A),M);
        
        printf("%d\n",ans);
    }

    return 0;
}