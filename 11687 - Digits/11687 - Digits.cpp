//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11687 - Digits
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

char s[10000000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11687 - Digits.INP","r",stdin);
    freopen("11687 - Digits.OUT","w",stdout);
    #endif
    
    while(gets(s) && s[0] != 'E')
    {
        int n = strlen(s);
        if(n == 1 && s[0] == '1')
        {
            puts("1");
            continue;
        }
        for(int i = 1 ; ; i++)
        {
            int k = n;
            int cnt = 0;
            while(k)
            {
                k /= 10;
                cnt++;
            }
            
            if(n == cnt)
            {
                printf("%d\n",i+1);
                break;
            }
            
            n = cnt;
        }
    }
    
    return 0;
}