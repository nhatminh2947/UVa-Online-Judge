//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 725 - Division
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



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("725 - Division.INP","r",stdin);
    freopen("725 - Division.OUT","w",stdout);
    #endif
    
    int n;
    bool blank = false;
    while(read(n) && n)
    {
        if(blank) printf("\n");
        blank = true;
        bool ans = false;
        for(int i = 0  ; i <= 99999 ; i++)
        {
            int m = i;
            if(m % n == 0)
            {
                int k = m/n;
                int a = 0;
                int cnt[15];
                vi v1,v2;
                for(int j = 0 ; j <= 9 ; j++)
                    cnt[j] = 0;
                
                for(int j = 0 ; j < 5 ; j++)
                {
                    if(cnt[m%10] == 0) a++;
                    cnt[m%10]++;
                    v1.pb(m%10);
                    m/=10;
                }
                
                for(int j = 0 ; j < 5 ; j++)
                {
                    if(cnt[k%10] == 0) a++;
                    cnt[k%10]++;
                    v2.pb(k%10);
                    k/=10;
                }
                
                if(a == 10)
                {
                    reverse(all(v1));
                    reverse(all(v2));
                    ans = true;
                    
                    for(int j = 0 ; j < 5 ; j++)
                        printf("%d",v1[j]);
                    printf(" / ");
                    for(int j = 0 ; j < 5 ; j++)
                        printf("%d",v2[j]);
                    printf(" = %d\n",n);
                }
            }
        }
        
        if(ans == false) printf("There are no solutions for %d.\n",n);
    }
    
    return 0;
}
