//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11062 - Andy's Second Dictionary
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
#define sz(s) s.size()
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

map<string,bool> m;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11062 - Andy's Second Dictionary.INP","r",stdin);
    freopen("11062 - Andy's Second Dictionary.OUT","w",stdout);
    #endif
    m.clear();
    string tmp,s;
    while(getline(cin,tmp))
    {
        //DEBUG(tmp);
        if(tmp == "")
        {
            s += " ";
            continue;
        }
        s += tmp;
        
        if(s[sz(s)-1] == '-')
            s.erase(s.begin()+sz(s)-1);
        else s += " ";
    }
    //DEBUG(s);
    tmp = "";
    rep(i,sz(s))
    {
        if('A' <= s[i] && s[i] <= 'Z')
            tmp += char(s[i] + 'a' - 'A');
        else if('a' <= s[i] && s[i] <= 'z' || s[i] == '-')
            tmp += char(s[i]);
        else if(sz(tmp))
        {
            m[tmp] = true;
            tmp = "";
            continue;
        }
    }
    
    map<string,bool>::iterator it;
    
    for(it = m.begin() ; it != m.end() ; it++)
        cout << (*it).ff << endl;
    //DEBUG(int('a'));
    
    return 0;
}
