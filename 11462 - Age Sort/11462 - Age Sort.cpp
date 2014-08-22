//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11462 - Age Sort
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
#define maxN 2000000

int n;
int a[maxN+5];

void quicksort(int l, int r)
{
    if(l >= r) return;
    int i = l;
    int j = r;
    int x = a[(l+r)/2];
    while(i <= j)
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        
        if(i <= j)
        {
            swap(a[i],a[j]);
            i++,j--;
        }
    }
    quicksort(l,j);
    quicksort(i,r);
}

int main()
{
    freopen("11462 - Age Sort.INP","r",stdin);
    freopen("11462 - Age Sort.OUT","w",stdout);
    
    while(scanf(" %d ",&n) && n)
    {
        //DEBUG(n);
        for(int i = 0 ; i < n ; i++)
            scanf(" %d ",&a[i]);
        
        quicksort(0,n-1);
        
        printf("%d",a[0]);
        for(int i = 1 ; i < n ; i++)
            printf(" %d",a[i]);
        printf("\n");
    }

    return 0;
}
