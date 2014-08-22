//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 10562 - Undraw the Trees
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

char T[205][205];
int n;

void DFS(int y, int x)
{
    if(y+1 > n || T[y+1][x] != '|') return;
    
    int lf = x;
    int rg = x;
    
    while(lf-1 >= 0 && T[y+2][lf-1] == '-') lf--;
    while(rg < strlen(T[y+2]) && T[y+2][rg+1] == '-') rg++;
    for(int i = lf ; i <= rg && i < strlen(T[y+3]) ; i++)
    {
        if(y+3 <= n && T[y+3][i] != ' ' && T[y+3][i] != '#' && T[y+3][i] != '-' && T[y+3][i] != '|')
        {
            cout << T[y+3][i] << '(' ;
            DFS(y+3,i);
            cout << ')';
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10562 - Undraw the Trees.INP","r",stdin);
    freopen("10562 - Undraw the Trees.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    getchar();
    fr(t,1,tcs)
    {
        n = 1;
        while(gets(T[n]) && T[n][0] != '#')
        {
            //puts(T[n]);
            n++;
        }
        n--;
        
        int len = strlen(T[1]);
        cout << '(';
        rep(i,len) 
            if(T[1][i] != ' ' && T[1][i] != '#' && T[1][i] != '-' && T[1][i] != '|')
            {
                cout << T[1][i] << '(';
                DFS(1,i);
                cout << ')';
                break;
            }
        cout << ')' << endl;
    }
    
    return 0;
}
