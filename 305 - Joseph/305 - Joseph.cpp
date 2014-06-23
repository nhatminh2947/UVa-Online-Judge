//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 305 - Joseph
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

int n;
//int ans[15];
int ans[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

void pre_cal()
{
    printf("int ans[] = {0");
    fr(k,1,13)
    {
        int m = k;
        while(m)
        {
            int p = 2*k;
            int kill = (m-1)%p;
            
            while(kill >= k && p >= k)
            {
                kill = (kill - 1 + m)%(--p);
            }
            
            if(p == k)
            {
                ans[k] = m;
                printf(",%d",m);
                //DEBUG(ans[k]);
                break;
            }
            m++;
        }
    }
    printf("};\n");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("305 - Joseph.INP","r",stdin);
    freopen("305 - Joseph.OUT","w",stdout);
    #endif
    //pre_cal();
    while(scanf("%d",&n) && n)
    {
        printf("%d\n",ans[n]);
    }

    return 0;
}