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

typedef pair<double,double> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

double xA, yA, xB, yB, xC, yC, xF, yF, xE, yE, xD, yD ;

struct Tdt{
    double a, b, c;
};

Tdt Extract( double xA, double yA, double xB, double yB )
{
    double a = -(yA - yB);
    double b = ( xA -xB);
    double c = - ( xA*a + yA*b);
    Tdt kq;
    kq.a = a;
    kq.b = b;
    kq.c = c;
    return kq;
}

ii giao( Tdt mot, Tdt hai )
{
    ii kq;
    kq.ff = ( (hai.b*mot.c)/mot.b - hai.c ) / ( hai.a - (hai.b*mot.a)/mot.b);
    kq.ss = ( - mot.a*kq.ff - mot.c ) / mot.b;
    return kq;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11437.INP","r",stdin);
    freopen("11437.OUT","w",stdout);
    #endif
    
    int tcs; scanf("%d",&tcs);
    rep(t,tcs)
    {
        scanf(" %lf %lf %lf %lf %lf %lf ",&xA,&yA,&xB,&yB,&xC,&yC);
        //DEBUG(xB);
        double delX = xA - xB ;
        double delY = yA - yB ;
        //DEBUG(delX);
        xF = xB + delX*2/3;
        yF = yB + delY*2/3;
        //DEBUG(xF);DEBUG(yF);
        delX = xC - xB;
        delY = yC - yB;
        xD = xB + delX/3;
        yD = yB + delY/3;
        delX = xA - xC;
        delY = yA - yC;
        xE = xC + delX/3;
        yE = yC + delY/3;
        ii r, p, q;
        r = giao( Extract(xF,yF,xC,yC), Extract(xA,yA,xD,yD));
        p = giao( Extract(xB,yB,xE,yE), Extract(xA,yA,xD,yD));
        q = giao( Extract(xF,yF,xC,yC), Extract(xB,yB,xE,yE));
        double A = sqrt( (r.ff - p.ff)*(r.ff - p.ff) + (r.ss - p.ss)*(r.ss- p.ss) );
        double B = sqrt( (r.ff - q.ff)*(r.ff - q.ff) + (r.ss - q.ss)*(r.ss- q.ss) );
        double C = sqrt( (q.ff - p.ff)*(q.ff - p.ff) + (q.ss - p.ss)*(q.ss- p.ss) );
        //DEBUG(A);
        //DEBUG(B);
        //DEBUG(C);
        double P = ( A + B + C ) /2;
        //DEBUG(P);
        double S = sqrt ( P*(P-A)*(P-B)*(P-C));
        printf("%.0lf\n",S);
    }
    
    return 0;
}
