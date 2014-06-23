//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 112 - Tree Summing
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
#define maxN 100000

bool YES;
int n;
string tree;

int solve(int i, int sum)
{
    if(tree[i] == ')') return -1;
    int st1,st2;
    
    int num = 0;
    bool neg = false;
    if(tree[i] == '-') neg = true, i++;

    while(tree[i] != '(')
    {
        num = num*10 + (tree[i] - '0');
        i++;
    }
    if(neg) num = -num;
    
    st1 = ++i;
    
    int op = 1;
    int cl = 0;
    
    while(op != cl)
    {
        if(tree[i] == '(') op++;
        else if(tree[i] == ')') cl++;
        i++;
    }
    
    st2 = ++i;
    
    int a = solve(st1,sum+num);
    int b = solve(st2,sum+num);
    
    if(a == -1 && b == -1 && sum + num == n)
        YES = true;
    
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("112 - Tree Summing.INP","r",stdin);
    freopen("112 - Tree Summing.OUT","w",stdout);
    #endif
    
    while(scanf(" %d ",&n) == 1)
    {
        YES = false;
        
        tree.clear();
        int op = 0;
        int cl = 0;
        
        do
        {
            char c;
            scanf(" %c ",&c);
            if(c == '(') op++;
            else if(c == ')') cl++;
            
            tree += c;
            
        } while(op != cl);
        
        if(tree == "()")
        {
            puts("no");
            continue;
        }
        
        solve(1,0);
        
        if(YES) puts("yes");
        else puts("no");
    }

    return 0;
}