//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10162 - Last Digit
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = { 0,-1, 1, 0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int ans[105];

void preCal()
{
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 5;
    ans[3] = 2;
    ans[4] = 8;
    ans[5] = 3;
    ans[6] = 9;
    ans[7] = 2;
    ans[8] = 8;
    ans[9] = 7;
    ans[10] = 7;
    ans[11] = 8;
    ans[12] = 4;
    ans[13] = 7;
    ans[14] = 3;
    ans[15] = 8;
    ans[16] = 4;
    ans[17] = 1;
    ans[18] = 5;
    ans[19] = 4;
    ans[20] = 4;
    ans[21] = 5;
    ans[22] = 9;
    ans[23] = 6;
    ans[24] = 2;
    ans[25] = 7;
    ans[26] = 3;
    ans[27] = 6;
    ans[28] = 2;
    ans[29] = 1;
    ans[30] = 1;
    ans[31] = 2;
    ans[32] = 8;
    ans[33] = 1;
    ans[34] = 7;
    ans[35] = 2;
    ans[36] = 8;
    ans[37] = 5;
    ans[38] = 9;
    ans[39] = 8;
    ans[40] = 8;
    ans[41] = 9;
    ans[42] = 3;
    ans[43] = 0;
    ans[44] = 6;
    ans[45] = 1;
    ans[46] = 7;
    ans[47] = 0;
    ans[48] = 6;
    ans[49] = 5;
    ans[50] = 5;
    ans[51] = 6;
    ans[52] = 2;
    ans[53] = 5;
    ans[54] = 1;
    ans[55] = 6;
    ans[56] = 2;
    ans[57] = 9;
    ans[58] = 3;
    ans[59] = 2;
    ans[60] = 2;
    ans[61] = 3;
    ans[62] = 7;
    ans[63] = 4;
    ans[64] = 0;
    ans[65] = 5;
    ans[66] = 1;
    ans[67] = 4;
    ans[68] = 0;
    ans[69] = 9;
    ans[70] = 9;
    ans[71] = 0;
    ans[72] = 6;
    ans[73] = 9;
    ans[74] = 5;
    ans[75] = 0;
    ans[76] = 6;
    ans[77] = 3;
    ans[78] = 7;
    ans[79] = 6;
    ans[80] = 6;
    ans[81] = 7;
    ans[82] = 1;
    ans[83] = 8;
    ans[84] = 4;
    ans[85] = 9;
    ans[86] = 5;
    ans[87] = 8;
    ans[88] = 4;
    ans[89] = 3;
    ans[90] = 3;
    ans[91] = 4;
    ans[92] = 0;
    ans[93] = 3;
    ans[94] = 9;
    ans[95] = 4;
    ans[96] = 0;
    ans[97] = 7;
    ans[98] = 1;
    ans[99] = 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10162 - Last Digit.INP","r",stdin);
    freopen("10162 - Last Digit.OUT","w",stdout);
    #endif
    
    preCal();
    
    string s;
    while(read(s))
    {
        if(s == "0") break;
        int n;
        if(sz(s) > 1)
            n = (s[sz(s)-2]-'0')*10 + s[sz(s) - 1]-'0';
        else n = s[0] - '0';
        
        cout << ans[n] << endl;
    }
    
    return 0;
}


