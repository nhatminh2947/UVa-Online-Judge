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
#define int64 long long
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

int64 convert(string s)
{
    int64 n = 0;
    int sz = s.size();
    for(int i = 0 ; i < sz ; i++)
        n = n*10 + (s[i] - '0');
    return n;
}

int main()
{
    freopen("11371 - Number Theory for Newbies.INP","r",stdin);
    freopen("11371 - Number Theory for Newbies.OUT","w",stdout);
    string s;
    while(cin >> s)
    {
        int64 u,v;
        sort(s.begin(),s.end());
        string k = s;
        
        int i = 0;
        while(s[i] == '0')
            i++;
        swap(k[i],k[0]);
        
        v = convert(k);
        reverse(s.begin(),s.end());
        u = convert(s);
        
        printf("%lld - %lld = %lld = 9 * %lld\n",u,v,u-v,(u-v)/9);
    }
    
    return 0;
}

