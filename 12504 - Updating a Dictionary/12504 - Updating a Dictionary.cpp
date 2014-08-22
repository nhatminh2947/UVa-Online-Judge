//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 12504 - Updating a Dictionary
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

map<string,string> m,check;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("12504 - Updating a Dictionary.INP","r",stdin);
    freopen("12504 - Updating a Dictionary.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    getchar();
    fr(t,1,tcs)
    {
        m.clear();
        check.clear();
        vector<string> change,nw,rm;
        string a,b;
        getline(cin,a);
        getline(cin,b);
        //DEBUG(a);
        //DEBUG(b);
        
        string k = "";
        string val = "";
        for(int i = 1 ; i < sz(a) ; i++)
        {
            if(a[i] == ',' || a[i] == '}')
            {
                if(k == "" || val == "") continue;
                //DEBUG(k);
                //DEBUG(val);
                m[k] = val;
                check[k] = val;
                k = "";
                val = "";
            }
            else if(a[i] == ':')
            {
                continue;
            }
            else if('a' <= a[i] && a[i] <= 'z')
                k += a[i];
            else if('0' <= a[i] && a[i] <= '9')
                val += a[i];
        }
        
        k = "";
        val = "";
        for(int i = 1 ; i < sz(b) ; i++)
        {
            if(b[i] == ',' || b[i] == '}')
            {
                if(k == "" || val == "") continue;
                if(m.count(k))
                {
                    if(m[k] != val)
                        change.pb(k);
                    check[k] = "AAA";
                }
                else 
                {
                    m[k] = val;
                    nw.pb(k);
                }
                k = "";
                val = "";
            }
            else if(b[i] == ':')
            {
                continue;
            }
            else if('a' <= b[i] && b[i] <= 'z')
                k += b[i];
            else if('0' <= b[i] && b[i] <= '9')
                val += b[i];
        }
        
        map<string,string>::iterator it;
        for(it = check.begin() ; it != check.end() ; it++)
            if(it->ss != "AAA")
                rm.pb(it->ff);
        
        if(sz(nw) + sz(change) + sz(rm) == 0) puts("No changes");
        else
        {
            if(sz(nw))
            {
                sort(all(nw));
                printf("+");
                bool cm = false;
                rep(i,sz(nw))
                {
                    if(i) printf(",");
                    cout << nw[i];
                }
                printf("\n");
            }
            
            if(sz(rm))
            {
                sort(all(rm));
                printf("-");
                rep(i,sz(rm))
                {
                    if(i) printf(",");
                    cout << rm[i];
                }
                printf("\n");
            }
            
            if(sz(change))
            {
                sort(all(change));
                printf("*");
                bool cm = false;
                rep(i,sz(change))
                {
                    if(i) printf(",");
                    cout << change[i];
                }
                printf("\n");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
