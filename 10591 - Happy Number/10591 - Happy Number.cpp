//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10591 - Happy Number
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
#define maxN 300000

int n;

int f(int k)
{
    int sum = 0;
    while(k)
    {
        sum += (k%10)*(k%10);
        k /= 10;
    }
    
    return sum;
}

bool checkNum(int k)
{
    if(k == 1) return true;
    
    int a = f(k);
    int b = f(f(k));
    while(a != b)
    {
        a = f(a);
        b = f(f(b));
    }
    
    b = k;
    while(a != b)
    {
        b = f(b);
        if(b == 1) return true;
    }
    
    b = f(b);
    if(b == 1) return true;
    while(a != b)
    {
        b = f(b);
        if(b == 1) return true;
    }
    
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10591 - Happy Number.INP","r",stdin);
    freopen("10591 - Happy Number.OUT","w",stdout);
    #endif

    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        read(n);
        
        printf("Case #%d: %d is a",t,n);
        if(checkNum(n) == false) printf("n Unh");
        else printf(" H");
        printf("appy number.\n");
    }

    return 0;
}


