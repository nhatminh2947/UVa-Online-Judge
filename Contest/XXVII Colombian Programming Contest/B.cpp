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
#define maxN 10004

string s;
int data[maxN];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    #endif
    while(cin>>s)
    {
        
        int ans = 0;
        for (int i = 0; i < maxN; i++)
            data[i] = 0;
        bool fail = false;
        for (int i = 0, sz = s.size(); i < sz; i++)
            if (s[i] == '?' || s[i] == '0') {
                bool check = false;
                for (int j = i - 1; j >= 0; j--)
                    if (data[j] > 0) {
                        data[j]--;
                        if (data[j] > 0) {
                            check = true;
                            break;
                        }
                    }
                if (!check)
                    ans++;
            } else
                data[i] = 2;
        for (int i = 0; i < s.size(); i++)
            if (data[i] > 0) {
                fail = true;
                break;
            }
        if (fail) {
            puts("0");
        } else printf("%d\n", ans);
            
    }
    return 0;
}
