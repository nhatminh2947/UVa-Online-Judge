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

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

char str[1000005];
int n,a,b;
long long res[1000005];

int main()
{
    freopen("10324.INP","r",stdin);
    freopen("10324.OUT","w",stdout);
    int tcs=0;
    while(gets(str))
    {
        printf("Case %d:\n",++tcs);
        int len = strlen(str);
        res[0] = str[0] - '0';
        for(int i = 1 ; i < len ; i++)
            res[i] = res[i-1] + str[i] - '0';
        
        scanf(" %d ",&n);
        for(int i=0;i<n;i++)
        {
            scanf(" %d %d ",&a,&b);
            if(a > b) a ^= b ^= a ^= b;
            if(str[a] == str[b] && 
               ((res[b] - res[a] == b - a) 
               || (res[b] == res[a]))) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
