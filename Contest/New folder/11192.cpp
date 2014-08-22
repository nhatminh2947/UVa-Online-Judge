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

char s[255];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11192.INP","r",stdin);
    freopen("11192.OUT","w",stdout);
    #endif
    
    while ( gets(s) && s[0]!='0'){
            int k;
            //puts(s);
          //char *p = strchr(s,' ');
    //cout << p << endl;
            int len = strlen(s);
            for (int i=0; i<len; i++) if ( s[i]==' ')
            {
                s[i]='\0';
                k = atoi(s);
                strcpy(s,s+i+1);
                break;
            }
          //strcpy(p,'\0')
          //puts(s);
          //cout << s << endl;
          //int k = atoi(s);
//        strcpy(s,p+1);
        //cout << k << " " << s << endl;
        //puts(s);
        int v = 0;
        len = strlen(s);
        //cout << " len = " << len << endl;
        int m = len/k-1;
        //cout << " m = " << m  << endl;
        while ( v < len ){
            for (int i=0; i<=m/2; i++){
                char tmp = s[v+i];
                s[v+i] = s[v+m-i];
                s[v+m-i]= tmp;
            }
            v+=(m+1);
        }
        puts(s);
        //gets(s);
    }
    
    return 0;
}
