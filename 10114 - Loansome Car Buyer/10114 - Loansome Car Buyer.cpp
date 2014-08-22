//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10114 - Loansome Car Buyer
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

double d[105];
int m,n;
double dp,aol;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10114 - Loansome Car Buyer.INP","r",stdin);
    freopen("10114 - Loansome Car Buyer.OUT","w",stdout);
    #endif
    
    while(scanf(" %d %lf %lf %d ",&m,&dp,&aol,&n) && m > 0)
    {
        rep(i,n)
        {
            int a;
            double b;
            scanf(" %d %lf ",&a,&b);
            for(int i = a ; i <= m ; i++)
                d[i] = b;
        }
        
        double monthpay = aol/m;
        double valCar = dp+aol;
        fr(i,0,maxN)
        {
            valCar *= (1 - d[i]);
            if(aol < valCar)
            {
                printf("%d month",i);
                if(i != 1) printf("s");
                printf("\n");
                break;
            }
            aol -= monthpay;
        }
    }
    
    return 0;
}
