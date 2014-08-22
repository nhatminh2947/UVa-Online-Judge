//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 760 - DNA Sequencing
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

string s,a,b;
int n;
int RA[maxN+5], tempRA[maxN+5];
int SA[maxN+5], tempSA[maxN+5];
int c[maxN+5];
int Phi[maxN+5];
int PLCP[maxN+5];
int LCP[maxN+5];
int Owner[maxN+5];

void countingSort(int k)
{
    int sum;
    int maxi = max(300,n);
    memset(c,0,sizeof(c));
    
    for(int i = 0 ; i < n ; i++)
    {
        if(i + k < n) c[RA[i+k]]++;
        else c[0]++;
    }
    
    for(int i = sum = 0 ; i < maxi ; i++)
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(SA[i] + k < n)
            tempSA[ c[RA[SA[i] + k]]++]  = SA[i];
        else tempSA[c[0]++] = SA[i];
    }
    for(int i = 0 ; i < n ; i++)
        SA[i] = tempSA[i];
}

void constructSA()
{
    for(int i = 0 ; i < n ; i++) RA[i] = s[i] - '.';
    for(int i = 0 ; i < n ; i++) SA[i] = i;
    
    for(int k = 1 ; k < n ; k <<= 1)
    {
        countingSort(k);
        countingSort(0);
        
        int r;
        tempRA[SA[0]] = r = 0;
        for(int i = 1 ; i < n ; i++)
            if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k])
                tempRA[SA[i]] = r;
            else tempRA[SA[i]] = ++r;
        for(int i = 0 ; i < n ; i++)
            RA[i] = tempRA[i];
    }
}

void computeLCP()
{
    int L;
    Phi[SA[0]] = -1;
    for(int i = 1 ; i < n ; i++)
        Phi[SA[i]] = SA[i-1];
    
    for(int i = L = 0 ; i < n ; i++)
    {
        if(Phi[i] == -1)
        {
            PLCP[i] = 0;
            continue;
        }
        
        while(s[i+L] == s[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1,0);
    }
    
    for(int i = 1 ; i < n ; i++)
        LCP[i] = PLCP[SA[i]];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("760 - DNA Sequencing.INP","r",stdin);
    freopen("760 - DNA Sequencing.OUT","w",stdout);
    #endif
    
    int tcs = 0;
    while(getline(cin,a) && getline(cin,b))
    {
        getchar();
        
        s = a + '.' + b;
        
        n = sz(s);
        constructSA();
        computeLCP();
        
        int L = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(SA[i] < sz(a)) Owner[i] = 1;
            else Owner[i] = 2;
        }
        
        for(int i = 1 ; i < n ; i++)
        {
            if(Owner[i] != Owner[i-1])
                L = max(L,LCP[i]);
        }
        
        if(tcs++) printf("\n");
        if(L == 0)
        {
            puts("No common sequence.");
            continue;
        }
        
        set<string> st;
        for(int i = 1 ; i < n ; i++)
        {
            if(Owner[i] != Owner[i-1])
                if(LCP[i] == L)
                    st.insert(s.substr(SA[i],L));
        }
        
        for(set<string>::iterator it = st.begin() ; it != st.end() ; it++)
            cout << *it << endl;
    }
    
    return 0;
}
