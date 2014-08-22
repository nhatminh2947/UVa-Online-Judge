//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11858 - Frosh Week
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
#define read(x) scanf("%d",&x)
#define read2(x,y) scanf(" %d %d ",&x,&y)
#define read3(x,y,z) scanf(" %d %d %d ",&x,&y,&z)
#define out(x) printf("%d",x)
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
#define maxN 1000000

int n;
int a[maxN+5];
int b[maxN+5];
ll ans;

void merge(int lf, int mid, int rg)
{
    int k = rg - lf + 1;
    int m = mid + 1;
    int l = lf;
    int i = 0;
    while(l <= mid && m <= rg)
    {
        if(a[l] <= a[m]) b[i++] = a[l++];
        else
        {
            ans += (ll)(mid + 1 - l);
            b[i++] = a[m++];
        }
    }
    
    while(l <= mid) b[i++] = a[l++];
    while(m <= rg) b[i++] = a[m++];
    
    for(i = 0 ; i < k ; i++)
        a[lf++] = b[i];
}

void merge_sort(int l, int r)
{
    if(l >= r) return;
    
    int m = (l+r)/2;
    merge_sort(l,m);
    merge_sort(m+1,r);
    merge(l,m,r);
}

int main()
{
    freopen("11858 - Frosh Week.INP","r",stdin);
    freopen("11858 - Frosh Week.OUT","w",stdout);

    while(read(n) == 1)
    {
        ans = 0;
        rep(i,n) read(a[i]);
        
        merge_sort(0,n-1);
        //cout << "AAAA" << endl << endl;
        //rep(i,n) out(a[i]), cout << " ";
        printf("%lld\n",ans);
    }

    return 0;
}