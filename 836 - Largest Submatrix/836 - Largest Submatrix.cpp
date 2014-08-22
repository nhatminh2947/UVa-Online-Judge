//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 836 - Largest Submatrix
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("836 - Largest Submatrix.INP","r",stdin);
    freopen("836 - Largest Submatrix.OUT","w",stdout);
    #endif
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        if(t != 1) puts("");
        char a[30][30];
        int sum[30][30];
        
        int n = 0;
        while(1)
        {
            gets(a[n]);
            if(a[n][0] == '\0') break;
            n++;
        }
        
        rep(i,n)
        {
            rep(j,n)
            {
                sum[i][j] = (a[i][j]-'0');
                
                if(i != 0) sum[i][j] += (sum[i-1][j]);
                if(j != 0) sum[i][j] += (sum[i][j-1]);
                if(i != 0 && j != 0) sum[i][j] -= sum[i-1][j-1];
            }
        }
        
        int ans = 0;
        rep(i,n) rep(j,n)
            for(int y = i ; y < n ; y++) for(int x = j ; x < n ; x++)
            {
                int s = sum[y][x];
                if(i != 0) s -= sum[i-1][x];
                if(j != 0) s -= sum[y][j-1];
                if(i != 0 && j != 0) s += sum[i-1][j-1];
                
                if(s == (y-i+1)*(x-j+1))
                    ans = max(ans,(y-i+1)*(x-j+1));
            }
        
        printf("%d\n",ans);
    }
    
    return 0;
}

