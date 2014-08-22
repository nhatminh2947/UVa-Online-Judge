//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10945 - Mother bear
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

string s;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10945 - Mother bear.INP","r",stdin);
    freopen("10945 - Mother bear.OUT","w",stdout);
    #endif
    
    while(getline(cin,s) && s != "DONE")
    {
        for(int i = 0 ; i < sz(s) ; i++)
        {
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] += abs('a' - 'A');
            else if(!('a' <= s[i] && s[i] <= 'z'))
            {
                s.erase(s.begin() + i);
                i--;
            }
        }
        
        string ans = "You won't be eaten!";
        for(int i = 0 ; i < sz(s) ; i++)
            if(s[i] != s[sz(s)-i-1])
            {
                ans = "Uh oh..";
                break;
            }
        
        cout << ans << endl;
    }
    
    return 0;
}
