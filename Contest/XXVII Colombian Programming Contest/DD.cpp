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
#define maxN 100000



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D.INP","r",stdin);
    //freopen("D.OUT","w",stdout);
    #endif
    string s;
    while (getline(cin,s)) {
        int tmp = 0;
        vector <int> data;
        bool nega = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') {
                nega= true;
                continue;
            }
            if (s[i] == ' ') {
                if (nega)
                    tmp *= -1;
                if (data.size() > 0)
                    tmp += data[data.size() - 1];
                data.push_back(tmp);
                tmp = 0;
                nega = false;
                continue;
            }
            tmp = tmp * 10 + s[i] - 48;
        }
        if (nega)
            tmp *= -1;
        if (data.size() > 0)
            tmp += data[data.size() - 1];
        data.push_back(tmp);
        int ans = 0, mn = 0;
        for (int i = 0; i < data.size(); i++) {
            mn = min(mn, data[i]);
            int tmpsub = max(data[i], data[i] - mn);
            ans = max(ans, tmpsub);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
