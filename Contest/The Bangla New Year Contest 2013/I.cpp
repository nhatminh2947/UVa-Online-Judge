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

map<string,int> m;

void BFS()
{
    string s = " WWWWWWWWWRRRBBBOOOGGGRRRBBBOOOGGGRRRBBBOOOGGGYYYYYYYYY";
    m[s] = 1;
    queue< pair<string,int> > q;
    q.push(mp(s,1));
    while(!q.empty())
    {
        s = q.front().ff;
        int d = q.front().ss;
        printf("d = %d\n",d);
        if(d == 7) return;
        q.pop();
        int i = 0;
        //for(int i = 0 ; i < 3 ; i++)
        {
            char tmp = s[7-3*i];
            string k = s;
            k[7-3*i] = k[8-3*i], k[8-3*i] = k[9-3*i], k[9-3*i] = k[16-i], k[16-i] = k[28-i], k[28-i] = k[40-i], 
                k[40-i] = k[48-3*i],k[48-3*i] = k[47-3*i],k[47-3*i] = k[46-3*i],k[46-3*i] = k[36-i],k[36-i] = k[24-i],
                    k[24-i] = k[12-i], k[12-i] = tmp;
            
            if(!m[k])
            {
                m[k] = d+1;
                q.push(mp(k,d+1));
            }
            
            tmp = s[7-3*i];
            k = s;
            k[7-3*i] = k[12-i], k[12-i] = k[24-i], k[24-i] = k[36-i], k[36-i] = k[46-3*i], k[46-3*i] = k[47-3*i], 
                k[47-3*i] = k[48-3*i],k[48-3*i] = k[40-i],k[40-i] = k[28-i],k[28-i] = k[16-i],k[16-i] = k[9-3*i],
                    k[9-3*i] = k[8-3*i], k[8-3*i] = tmp;
            
            if(!m[k])
            {
                m[k] = d+1;
                q.push(mp(k,d+1));
            }
        }
        
        //for(int i = 0 ; i < 3 ; i++)
        {
            char tmp = s[10+12*i];
            string k = s;
            k[10+12*i] = k[11+12*i], k[11+12*i] = k[12+12*i], k[12+12*i] = k[13+12*i], k[13+12*i] = k[14+12*i],
                k[14+12*i] = k[15+12*i], k[15+12*i] = k[16+12*i],k[16+12*i] = k[17+12*i],k[17+12*i] = k[18+12*i],
                    k[18+12*i] = k[19+12*i],k[19+12*i] = k[20+12*i],k[20+12*i] = k[21+12*i], k[21+12*i] = tmp;
            
            if(!m[k])
            {
                m[k] = d+1;
                q.push(mp(k,d+1));
            }
            
            tmp = s[10+12*i];
            k = s;
            k[10+12*i] = k[21+12*i], k[21+12*i] = k[20+12*i], k[20+12*i] = k[19+12*i], k[19+12*i] = k[18+12*i],
                k[18+12*i] = k[17+12*i], k[17+12*i] = k[16+12*i],k[16+12*i] = k[15+12*i],k[15+12*i] = k[14+12*i],
                    k[14+12*i] = k[13+12*i],k[13+12*i] = k[12+12*i],k[12+12*i] = k[11+12*i], k[11+12*i] = tmp;
            
            if(!m[k])
            {
                m[k] = d+1;
                q.push(mp(k,d+1));
            }
        }
        
        //for(int i = 0 ; i < 3 ; i++)
        {
            char tmp = s[1+i];
            string k = s;
            k[1+i] = k[4+i], k[4+i] = k[7+i], k[7+i] = k[13+i], k[13+i] = k[25+i],
                k[25+i] = k[37+i], k[37+i] = k[46+i],k[46+i] = k[49+i],k[49+i] = k[52+i],
                    k[52+i] = k[45+i],k[45+i] = k[33+i],k[33+i] = k[21+i], k[21+i] = tmp;
            
            if(!m[k])
            {
                m[k] = d+1;
                q.push(mp(k,d+1));
            }
            
            tmp = s[1+i];
            k = s;
            k[1+i] = k[21+i], k[21+i] = k[33+i], k[33+i] = k[45+i], k[45+i] = k[52+i],
                k[52+i] = k[49+i], k[49+i] = k[46+i],k[46+i] = k[37+i],k[37+i] = k[25+i],
                    k[25+i] = k[13+i],k[13+i] = k[7+i],k[7+i] = k[4+i], k[4+i] = tmp;
            
            if(!m[k])
            {
                m[k] = d+1;
                q.push(mp(k,d+1));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("I.INP","r",stdin);
    freopen("I.OUT","w",stdout);
    #endif
    
    BFS();

    return 0;
}