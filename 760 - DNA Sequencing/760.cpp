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

string s;
int SA[maxN+5], tempSA[maxN+5];
int RA[maxN+5], tempRA[maxN+5];
int c[maxN+5];

void countingSort(int k)
{
    int maxi = max(255,sz(s));
    rep(i,maxN) c[i] = 0;
    
    rep(i,sz(s))
        if(i + k < sz(s)) c[RA[i+k]]++;
        else c[0]++;
        
    int sum = 0;
    rep(i,maxi)
    {
        int tmp = c[i];
        c[i] = sum;
        sum += tmp;
    }
    
    rep(i,sz(s))
        if(SA[i] + k < sz(s))
            tempSA[ c[RA[i]+k]++ ] = SA[i];
        else tempSA[ c[0]++ ] = SA[i];
    
    rep(i,sz(s))
        SA[i] = tempSA[i];
}

void constructSA()
{
    rep(i,sz(s)) SA[i] = s[i] - '.';
    rep(i,sz(s)) RA[i] = i;
    
    for(int k = 1 ; k < sz(s) ; k <<= 1)
    {
        countingSort(k);
        countingSort(0);
        
        int r = 0;
        tempRA[SA[0]] = 0;
        for(int i = 1 ; i < sz(s) ; i++)
            if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k])
                tempRA[SA[i]] = r;
            else tempRA[SA[i]] = ++r;
        
        rep(i,sz(s)) RA[i] = tempRA[i];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("760 - DNA Sequencing.INP","r",stdin);
    freopen("760 - DNA Sequencing.OUT","w",stdout);
    #endif
    
    string a,b;
    while(read2(a,b))
    {
        s = a + '.' + b;
        
        constructSA();
    }
    
    return 0;
}
