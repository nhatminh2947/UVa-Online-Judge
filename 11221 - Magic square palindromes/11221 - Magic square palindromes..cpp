//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11221 - Magic square palindromes.
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
#define maxN 10000

int a[105][105];

int main()
{
    freopen("11221 - Magic square palindromes..INP","r",stdin);
    freopen("11221 - Magic square palindromes..OUT","w",stdout);

    int tcs;
    scanf("%d",&tcs);
    getchar();
    fr(t,1,tcs)
    {
        printf("Case #%d:\n",t);
        
        string tmp,s;
        getline(cin,tmp);
        rep(i,sz(tmp))
            if('a' <= tmp[i] && tmp[i] <= 'z')
                s += tmp[i];
        
        int k = sqrt(sz(s));
        if(k*k == sz(s))
        {
            for(int i = 0 ; i < k ; i++)
                for(int j = 0 ; j < k ; j++)
                    a[i][j] = s[k*i+j];
            
            int ans = k;
            for(int i = 0 ; i < k && ans; i++)
                for(int j = 0 ; j < k && ans; j++)
                {
                    if(a[i][j] != a[j][i])
                        ans = 0;
                    if(a[i][j] != a[k-j-1][k-i-1])
                        ans = 0;
                }
            if(ans) printf("%d\n",ans);
            else puts("No magic :(");
        }
        else puts("No magic :(");
    }

    return 0;
}