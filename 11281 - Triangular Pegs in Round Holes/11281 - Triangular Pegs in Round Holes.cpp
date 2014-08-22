//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11281 - Triangular Pegs in Round Holes
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

int n,m;
double h[105];

bool check(double a, double b, double c)
{
    double A = acos((b*b+c*c-a*a)/(2*b*c));
    double B = acos((a*a+c*c-b*b)/(2*a*c));
    double C = acos((b*b+a*a-c*c)/(2*b*a));
    
    A = A*180/PI;
    B = B*180/PI;
    C = C*180/PI;
    
    if(A <= 90 && B <= 90 && C <= 90)
        return true;
    return false;
}

double radius(double a, double b, double c)
{   
    double p = (a+b+c)/2;
    double S = sqrt(p*(p-a)*(p-b)*(p-c));
    double r = (a*b*c)/(4*S);
    
    return r;
}

int main()
{
    freopen("11281 - Triangular Pegs in Round Holes.INP","r",stdin);
    freopen("11281 - Triangular Pegs in Round Holes.OUT","w",stdout);

    read(m);
    rep(i,m) read(h[i]);
    
    read(n);
    rep(i,n)
    {
        vector<int> ans;
        double a, b, c;
        read3(a,b,c);
        
        if(check(a,b,c))
        {
            double r = radius(a,b,c);
            //DEBUG(r);
            rep(i,m)
                if(2*r <= h[i])
                    ans.pb(i+1);
        }
        else
        {
            double l = max(max(a,b),c);
            rep(i,m)
                if(l <= h[i])
                    ans.pb(i+1);
        }
        
        if(sz(ans))
        {
            printf("Peg %c will fit into hole(s):",i+'A');
            rep(i,sz(ans)) printf(" %d",ans[i]);
            printf("\n");
        }
        else printf("Peg %c will not fit into any holes\n",i+'A');
    }

    return 0;
}