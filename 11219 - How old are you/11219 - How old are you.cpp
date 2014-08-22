//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11219 - How old are you?
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



int main()
{
    freopen("11219 - How old are you.INP","r",stdin);
    freopen("11219 - How old are you.OUT","w",stdout);

    int tcs;
    scanf(" %d ",&tcs);
    fr(t,1,tcs)
    {
        printf("Case #%d: ",t);
        int a,b,c,d,m,y;
        scanf("%d/%d/%d",&a,&b,&c);
        scanf("%d/%d/%d",&d,&m,&y);
        
        if(c < y || (c == y && b < m) || (c == y && b == m && a < d))
            printf("Invalid birth date\n");
        else
        {
            int birth = c - y;
            
            if(b < m || (b == m && a < d))
                birth--;
            
            if(birth > 130) printf("Check birth date\n");
            else printf("%d\n",birth);
        }
    }

    return 0;
}