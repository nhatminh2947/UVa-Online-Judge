//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 628 - Passwords
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

int n;
string rule;
string word[105];

void gen(int p, int w, string ans)
{
    if(p >= sz(rule))
    {
        cout << ans << endl;
        return;
    }
    string tmp = ans;
    if(rule[p] == '#')
    {
        gen(p+1,w,ans + word[w]);
    }
    else
    {
        fr(i,0,9)
        {
            gen(p+1,w,ans + char(i+'0'));
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("628 - Passwords.INP","r",stdin);
    freopen("628 - Passwords.OUT","w",stdout);
    #endif
    
    while(read(n))
    {
        printf("--\n");
        rep(i,n) read(word[i]);
        int q;
        read(q);
        
        rep(i,q)
        {
            read(rule);
            rep(j,n)
                gen(0,j,"");
        }
    }
    
    return 0;
}
