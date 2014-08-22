//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11239 - Open Source
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

map<string,int> project;
map<string,string> student;

bool cmp(pair<string,int> u, pair<string,int> v)
{
    if(u.ss == v.ss) return u.ff < v.ff;
    return u.ss > v.ss;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11239 - Open Source.INP","r",stdin);
    freopen("11239 - Open Source.OUT","w",stdout);
    #endif
    string s;
    
    project.clear();
    student.clear();
    while(getline(cin,s) && s != "0")
    {
        string cur = s;
        project[cur] = 0;
        while(getline(cin,s) && s[0] != '1')
        {
            //DEBUG(s);
            if('A' <= s[0] && s[0] <= 'Z')
            {
                cur = s;
                project[cur] = 0;
            }
            else
            {
                if(!student.count(s))
                {
                    project[cur]++;
                    student[s] = cur;
                }
                else if(student[s] != cur)
                {
                    project[student[s]]--;
                    student[s] = "";
                }
            }
            //if(project.count("C")) DEBUG(project["C"]);
        }
        
        if(project.count(""))
            project.erase("");
        map<string,int>::iterator it;
        vector< pair<string,int> > v;
        
        for(it = project.begin() ; it != project.end() ; it++)
            v.pb(mp(it->ff,it->ss));
        
        sort(all(v),cmp);
        
        rep(i,sz(v))
            cout << v[i].ff << " " << v[i].ss << endl;
        
        project.clear();
        student.clear();
        //DEBUG(project.size());
    }
    
    return 0;
}
