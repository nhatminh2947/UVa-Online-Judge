//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 492 - Pig-Latin
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

bool check[300];

void preCal()
{
    fill(check,check+280,false);
    
    check['a'] = check['A'] = true;
    check['e'] = check['E'] = true;
    check['i'] = check['I'] = true;
    check['o'] = check['O'] = true;
    check['u'] = check['U'] = true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("492 - Pig-Latin.INP","r",stdin);
    freopen("492 - Pig-Latin.OUT","w",stdout);
    #endif
    preCal();
    string s;
    while(getline(cin,s))
    {
        string tmp;
        for(int i = 0 ; i < sz(s) ; i++)
        {
            tmp = "";
            while(i < sz(s) && (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')))
            {
                tmp += s[i];
                i++;
            }
            
            if(!check[tmp[0]])
            {
                string k = tmp + tmp[0];
                
                for(int i = 1 ; i < sz(k) ; i++)
                    tmp[i-1] = k[i];
            }
            if(tmp.empty())
            {
                if(i < sz(s)) cout << s[i];
                continue;
            }
            tmp += "ay";
            cout << tmp;
            if(i < sz(s)) cout << s[i];
        }
        puts("");
    }
    
    return 0;
}
