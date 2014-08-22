//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10222 - Decode the Mad man
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

int main()
{
    freopen("10222 - Decode the Mad man.INP","r",stdin);
    freopen("10222 - Decode the Mad man.OUT","w",stdout);
    int m[300];
    char s[10000];
    m[' '] = ' ';
    m['='] = '0';
    m['-'] = '9';
    m['0'] = '8';
    m['9'] = '7';
    m['8'] = '6';
    m['7'] = '5';
    m['6'] = '4';
    m['5'] = '3';
    m['4'] = '2';
    m['3'] = '1';
    m['2'] = '`';
    
    m['\\'] = '[';
    m[']'] = 'p';
    m['['] = 'o';
    m['p'] = 'i';
    m['o'] = 'u';
    m['i'] = 'y';
    m['u'] = 't';
    m['y'] = 'r';
    m['t'] = 'e';
    m['r'] = 'w';
    m['e'] = 'q';
    
    m['\''] = 'l';
    m[';'] = 'k';
    m['l'] = 'j';
    m['k'] = 'h';
    m['j'] = 'g';
    m['h'] = 'f';
    m['g'] = 'd';
    m['f'] = 's';
    m['d'] = 'a';
    
    m['/'] = ',';
    m['.'] = 'm';
    m[','] = 'n';
    m['m'] = 'b';
    m['n'] = 'v';
    m['b'] = 'c';
    m['v'] = 'x';
    m['c'] = 'z';
    
    gets(s);
    int sz = strlen(s);
    for(int i = 0 ; i < sz ; i++)
    {
        if('A' <= s[i] && s[i] <= 'Z' && s[i] != ' ')
            s[i] += ('a'-'A');
        printf("%c",m[s[i]]);
    }
    printf("\n");
    return 0;
}

