//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11070 - The Good Old Times
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
#define eps 1e-11
#define maxN 100000

struct Symbol
{
    int type;
    double val;
    string s;
    Symbol(){}
    
    Symbol(int t, double v, string str)
    {
        type = t;
        val = v;
        s = str;
    }
};

class Func
{
    public:
        vector<Symbol> inFix;
        vector<Symbol> postFix;
        
        Func() 
        {
            inFix.clear();
            postFix.clear();
        }
        
        double number(string s)
        {
            bool chia = false;
            double d = 1;
            int mi = 0;
            double n;
            rep(i,sz(s))
            {
                if(s[i] == '-') mi++;
                else if(s[i] == '+') continue;
                else if(s[i] == '.') chia = true;
                else
                {
                    if(chia) d *= 10;
                    n = n*10 + s[i] - '0';
                }
            }
            
            if(mi % 2) n *= -1.0;
            return n / d;
        }
        
        void analyze(string s)
        {
            string tmp = "";
            for(int i = 0 ; i < sz(s) ; i++)
            {
                if('0' <= s[i] && s[i] <= '9' || s[i] == '.')
                {
                    tmp += s[i];
                }
                else if(s[i] == '+' || s[i] == '-')
                {
                    if(sz(tmp) == 0)
                        tmp += s[i];
                    else if(sz(tmp) && (tmp[sz(tmp)-1] == '+' || tmp[sz(tmp)-1] == '-'))
                    {
                        tmp += s[i];
                    }
                    else
                    {
                        string k = "";
                        k += s[i];
                        inFix.pb(Symbol(1,number(tmp),tmp));
                        inFix.pb(Symbol(2,1,k));
                        tmp = "";
                    }
                }
                else if(s[i] == '*' || s[i] == '/')
                {
                    string k = "";
                    k += s[i];
                    inFix.pb(Symbol(1,number(tmp),tmp));
                    inFix.pb(Symbol(2,2,k));
                    tmp = "";
                }
            }
            
            if(sz(tmp))
                inFix.pb(Symbol(1,number(tmp),tmp));
        }
        
        void inFixtoPostFix()
        {
            stack<Symbol> s;
            
            rep(i,sz(inFix))
            {
                if(inFix[i].type == 1) postFix.pb(inFix[i]);
                else
                {
                    while(!s.empty() && (s.top().val >= inFix[i].val))
                    {
                        postFix.pb(s.top());
                        s.pop();
                    }
                    
                    s.push(inFix[i]);
                }
            }
            
            while(!s.empty())
            {
                postFix.pb(s.top());
                s.pop();
            }
        }
        
        double Cal()
        {
            stack<double> s;
            
            rep(i,sz(postFix))
            {
                if(postFix[i].type == 1) s.push(postFix[i].val);
                else
                {
                    string k = postFix[i].s;
                    double b = s.top();
                    s.pop();
                    double a = s.top();
                    s.pop();
                    
                    if(k == "+")
                        s.push(a+b);
                    else if(k == "-")
                        s.push(a-b);
                    else if(k == "*")
                        s.push(a*b);
                    else if(k == "/")
                        s.push(a/b);
                }
            }
            
            return s.top();
        }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11070 - The Good Old Times.INP","r",stdin);
    freopen("11070 - The Good Old Times.OUT","w",stdout);
    #endif
    
    string s;
    while(read(s))
    {
        Func F;
        
        F.analyze(s);
        F.inFixtoPostFix();
        /*
        cout << "INFIX  ";
        rep(i,sz(F.inFix))
        {
            if(F.inFix[i].type == 1) cout << F.inFix[i].val;
            else cout << F.inFix[i].s;
            cout << " ";
        }
        printf("\n");
        
        cout << "POSTFIX ";
        rep(i,sz(F.postFix))
        {
            if(F.postFix[i].type == 1) cout << F.postFix[i].val;
            else cout << F.postFix[i].s;
            cout << " ";
        }
        printf("\n");
        */
        double ans = F.Cal();
        if(ans > -eps && ans < eps) ans = ans*(-1.0);
        printf("%.3lf\n",ans+1e-7);
    }
    
    return 0;
}
