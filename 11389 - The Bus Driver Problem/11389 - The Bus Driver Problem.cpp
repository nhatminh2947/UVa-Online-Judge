//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11389 - The Bus Driver Problem
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
#include <list
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
#define read(x) scanf("%d",&x)
#define read2(x,y) scanf(" %d %d ",&x,&y)
#define read3(x,y,z) scanf(" %d %d %d ",&x,&y,&z)
#define out(x) printf("%d",x)
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

int n,d,r;
int a[maxN+5];
int b[maxN+5];

int main()
{
    freopen("11389 - The Bus Driver Problem.INP","r",stdin);
    freopen("11389 - The Bus Driver Problem.OUT","w",stdout);

    while(read3(n,d,r) && (n || d || r))
    {
        rep(i,n) read(a[i]);
        rep(i,n) read(b[i]);
        
        sort(a,a+n);
        sort(b,b+n)
        reverse(b,b+n);
        
        int ans = 0;
        rep(i,n)
        {
            int k = a[i] + b[i] - d;
            ans += max(0,k) * r;
        }
        
        out(ans);
        puts("");
    }

    return 0;
}
