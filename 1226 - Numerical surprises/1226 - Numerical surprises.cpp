//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1226 - Numerical surprises
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
#include <cctype>
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

int tcs;

class BigNum
{
    public:
        string n;
    public:
        BigNum()
        {
            n = "";
        }
        
        int Mod(int k)
        {
            int sz = n.size();
            int ans = 0;
            for(int i = 0 ; i < sz ; i++)
                ans = (ans*10 + n[i] - '0') % k;
            return ans;
        }
};

int main()
{
    freopen("1226 - Numerical surprises.INP","r",stdin);
    freopen("1226 - Numerical surprises.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int k;
        string s;
        scanf(" %d ",&k);
        BigNum n;
        cin >> n.n;
        
        int ans = n.Mod(k);
        printf("%d\n",ans);
    }
    return 0;
}
