//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10260 - Soundex
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

int m[300];

void init()
{
    m['B'] = m['F'] = m['P'] = m['V'] = 1;
    m['C'] = m['G'] = m['J'] = m['K'] = m['Q'] = m['S'] = m['X'] = m['Z'] = 2;
    m['D'] = m['T'] = 3;
    m['L'] = 4;
    m['M'] = m['N'] = 5;
    m['R'] = 6;
    m['A'] = m['E'] = m['I'] = m['O'] = m['U'] = m['H'] = m['W'] = m['Y'] = -1;
}

int main()
{
    freopen("10260 - Soundex.INP","r",stdin);
    freopen("10260 - Soundex.OUT","w",stdout);
    char s[100];
    init();
    while(gets(s))
    {
        bool n[10];
        for(int i = 1 ; i <= 6 ; i++)
            n[i] = false;
        int sz = strlen(s);
        for(int i = 0 ; i < sz ; i++)
        {
            if(m[s[i]] != -1)
            {
                if(!n[m[s[i]]])
                {
                    printf("%d",m[s[i]]);
                    for(int i = 1 ; i <= 6 ; i++)
                        n[i] = false;
                    n[m[s[i]]] = true;
                }
                continue;
            }
            for(int i = 1 ; i <= 6 ; i++)
                n[i] = false;
        }
        printf("\n");
    }
    return 0;
}

