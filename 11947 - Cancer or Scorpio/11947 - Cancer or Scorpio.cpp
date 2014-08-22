//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11947 - Cancer or Scorpio
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

bool checkYear(int y)
{
    if((y%4 == 0 && y%100 != 0) || y%400 == 0) return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11947 - Cancer or Scorpio.INP","r",stdin);
    freopen("11947 - Cancer or Scorpio.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        string s;
        read(s);
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int y = (s[4] - '0')*1000 + (s[5] - '0')*100 + (s[6] - '0')*10 + s[7] - '0';
        int m = (s[0] - '0')*10 + s[1] - '0';
        int d = 40*7 + (s[2] - '0')*10 + s[3] - '0';
        
        while(1)
        {
            if(checkYear(y))
                days[2] = 29;
            else days[2] = 28;
            
            if(d > days[m])
            {
                d -= days[m];
                m++;
                
                if(m > 12)
                {
                    m = 1;
                    y++;
                }
            }
            else break;
        }
        
        printf("%d %02d/%02d/%04d ",t,m,d,y);
        
        if((m == 1 && d >= 21) || (m == 2 && d <= 19)) puts("aquarius");
        else if((m == 2 && d >= 20) || (m == 3 && d <= 20)) puts("pisces");
        else if((m == 3 && d >= 21) || (m == 4 && d <= 20)) puts("aries");
        else if((m == 4 && d >= 21) || (m == 5 && d <= 21)) puts("taurus");
        else if((m == 5 && d >= 22) || (m == 6 && d <= 21)) puts("gemini");
        else if((m == 6 && d >= 22) || (m == 7 && d <= 22)) puts("cancer");
        else if((m == 7 && d >= 23) || (m == 8 && d <= 21)) puts("leo");
        else if((m == 8 && d >= 22) || (m == 9 && d <= 23)) puts("virgo");
        else if((m == 9 && d >= 24) || (m == 10 && d <= 23)) puts("libra");
        else if((m == 10 && d >= 24) || (m == 11 && d <= 22)) puts("scorpio");
        else if((m == 11 && d >= 23) || (m == 12 && d <= 22)) puts("sagittarius");
        else if((m == 12 && d >= 23) || (m == 1 && d <= 20)) puts("capricorn");
    }
    
    return 0;
}
