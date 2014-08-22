//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 944 - Happy Numbers
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
#define maxN 99999

int step[maxN+5];

int f(int x)
{
    int sum = 0;
    
    while(x)
    {
        sum += (x%10)*(x%10);
        x /= 10;
    }
    
    return sum;
}

int strToInt(string s)
{
    int x = 0;
    rep(i,sz(s))
        x = x*10 + (s[i] - '0');
    
    return x;
}

string intToStr(int x)
{
    string s = "";
    while(x)
    {
        if(x%10 != 0) s = s + char(x%10 + '0');
        x /= 10;
    }
    
    sort(all(s));
    return s;
}

int checkHappy(int x)
{
    if(x == 1) return 2;
    int a = x;
    int b = x;
    int cnt = 0;
    
    do
    {
        a = f(a);
        b = f(f(b));
        cnt++;
        if(a == 1) return cnt+1;
    }while(a != b);
    
    do
    {
        a = f(a);
        cnt++;
        if(a == 1) return cnt+1;
    }while(a != b);
    
    return -1;
}

void preCal()
{
    step[1] = 1;
    
    fr(i,2,99999)
    {   
        int k = strToInt(intToStr(i));
        step[i] = checkHappy(k);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("944 - Happy Numbers.INP","r",stdin);
    freopen("944 - Happy Numbers.OUT","w",stdout);
    #endif
    
    preCal();
    
    bool blank = false;
    int a,b;
    while(read2(a,b))
    {
        if(blank) puts("");
        blank = true;
        
        fr(i,a,b)
        {
            if(step[i] != -1) printf("%d %d\n",i,step[i]);
        }
    }
    
    return 0;
}


