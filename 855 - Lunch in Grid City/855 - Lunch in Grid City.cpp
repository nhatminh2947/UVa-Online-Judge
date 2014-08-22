//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 855 - Lunch in Grid City
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
#define maxN 50000

int tcs,f,n,m;
int s[maxN+5],a[maxN+5];

int main()
{
    freopen("855 - Lunch in Grid City.INP","r",stdin);
    freopen("855 - Lunch in Grid City.OUT","w",stdout);

    scanf(" %d ",&tcs);
    rep(t,tcs)
    {
        scanf(" %d %d %d ",&n,&m,&f);
        rep(i,f) scanf(" %d %d ",&s[i],&a[i]);
        
        sort(a,a+f);
        sort(s,s+f);
        
        if(f%2) printf("(Street: %d, Avenue: %d)\n",s[f/2],a[f/2]);
        else printf("(Street: %d, Avenue: %d)\n",s[(f-1)/2],a[(f-1)/2]);
    }

    return 0;
}