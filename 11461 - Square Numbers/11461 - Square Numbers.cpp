//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11461 - Square Numbers
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

int ans[maxN+5];

void preCal()
{
    fill(ans,ans+maxN+1,false);
    for(int i = 1 ; i <= (int)sqrt(maxN) ; i++)
        ans[i*i] = 1;
    
    for(int i = 1 ; i <= maxN ; i++)
        ans[i] += ans[i-1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11461 - Square Numbers.INP","r",stdin);
    //freopen("11461 - Square Numbers.OUT","w",stdout);
    #endif
    preCal();
    int a,b;
    while(read2(a,b) && a)
    {
        printf("%d\n",ans[b] - ans[a-1]);
    }
    
    return 0;
}
