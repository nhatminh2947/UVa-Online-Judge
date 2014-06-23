//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 146 - ID Codes
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

int n;
string s;
int a[maxN];

int main()
{
    freopen("146 - ID Codes.INP","r",stdin);
    freopen("146 - ID Codes.OUT","w",stdout);
    
    while(cin >> s)
    {
        if(s == "#") break;
        string k = s;
        sort(k.begin(),k.end());
        next_permutation(s.begin(),s.end());
        
        if(s == k)
            puts("No Successor");
        else cout << s << endl;
    }
    
    return 0;
}


