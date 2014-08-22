//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10171 - Meeting Prof. Miguel
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

int Y[300][300];
int M[300][300];
int n;

void FloydWarshall()
{
    fr(k,'A','Z')
        fr(i,'A','Z')
            fr(j,'A','Z')
            {
                Y[i][j] = min(Y[i][j],Y[i][k]+Y[k][j]);
                M[i][j] = min(M[i][j],M[i][k]+M[k][j]);
            }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10171 - Meeting Prof. Miguel.INP","r",stdin);
    freopen("10171 - Meeting Prof. Miguel.OUT","w",stdout);
    #endif
    
    while(scanf(" %d ",&n) && n)
    {
        fr(i,'A','Z') fr(j,'A','Z')
        {
            if(i == j) Y[i][j] = 0;
            else Y[i][j] = M[i][j] = INF;
        }
        
        char u,v;
        rep(i,n)
        {
            char age,ways;
            int w;
            scanf(" %c %c %c %c %d ",&age,&ways,&u,&v,&w);
            
            if(age == 'Y')
            {
                if(ways == 'U') Y[u][v] = min(Y[u][v],w);
                else if(ways == 'B') Y[u][v] = Y[v][u] = min(Y[u][v],w);
            }
            else if(age == 'M')
            {
                if(ways == 'U') M[u][v] = min(M[u][v],w);
                else if(ways == 'B') M[u][v] = M[v][u] = min(M[u][v],w);
            }
        }
        
        scanf(" %c %c ",&u,&v);
        
        FloydWarshall();
        
        int m = INF;
        fr(j,'A','Z') m = min(m,Y[u][j] + M[v][j]);
        
        if(m < INF)
        {
            printf("%d",m);
            fr(j,'A','Z') if(Y[u][j] + M[v][j] == m) printf(" %c",j);
        
            printf("\n");
        }
        else puts("You will never meet.");
    }
    
    return 0;
}
