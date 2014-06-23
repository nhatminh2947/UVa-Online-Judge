//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 462 - Bridge Hand Evaluator
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

vector<char> v[10];
int m[300];
bool stop[10];

void init()
{
    m['S'] = 1;
    m['H'] = 2;
    m['D'] = 3;
    m['C'] = 4;
    
    m[1] = 'S';
    m[2] = 'H';
    m[3] = 'D';
    m[4] = 'C';
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("462 - Bridge Hand Evaluator.INP","r",stdin);
    freopen("462 - Bridge Hand Evaluator.OUT","w",stdout);
    #endif
    init();
    string s;
    while(getline(cin,s))
    {
        rep(i,5) stop[i] = false;
        fr(i,1,4) v[i].clear();
        int sum = 0;
        for(int i = 0 ; i < sz(s) ; i+=3)
        {
            //DEBUG(s[i]);
            if(s[i+1] == 'S')
                v[1].pb(s[i]);
            else if(s[i+1] == 'H')
                v[2].pb(s[i]);
            else if(s[i+1] == 'D')
                v[3].pb(s[i]);
            else if(s[i+1] == 'C')
                v[4].pb(s[i]);
            if(s[i] == 'A') sum += 4;
            else if(s[i] == 'K') sum += 3;
            else if(s[i] == 'Q') sum += 2;
            else if(s[i] == 'J') sum += 1;
        }
        
        int sub = 0;
        int add = 0;
        int C;
        int ma = -INF;
        for(int i = 1 ; i <= 4 ; i++)
        {
            int K,Q,J,A,O;
            K = Q = J = A = 0;
            O = sz(v[i]);
            rep(j,sz(v[i]))
            {
                if(v[i][j] == 'K') K++;
                else if(v[i][j] == 'Q') Q++;
                else if(v[i][j] == 'J') J++;
                else if(v[i][j] == 'A') A++;
            }
            
            if(O - K == 0) sub += K;
            if(O - Q <= 1) sub += Q;
            if(O - J <= 2) sub += J;
            
            if(O == 2) add++;
            if(O == 1) add += 2;
            if(O == 0) add += 2;
            
            if(A || (K && (O - K >= 1)) || (Q && (O - Q >= 2)))
                stop[i] = true;
            
            if(O > ma)
            {
                ma = O;
                C = m[i];
            }
            //printf("\n");
        }
        //DEBUG(sum);
        //DEBUG(sub);
        //DEBUG(add);
        if(sum - sub >= 16 && stop[1] && stop[2] && stop[3] && stop[4]) printf("BID NO-TRUMP\n");
        else if(sum - sub + add >= 14) printf("BID %c\n",C);
        else printf("PASS\n");
        
        //printf("---------------------------------\n");
    }

    return 0;
}