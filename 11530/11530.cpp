//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11530 - SMS Typing
// Verdict:
//******************************************************************
#include <iostream>
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
#define INF 999999999
#define PI 3.1415926535
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

int tcs;
char s[105];
map<char,int> m;

void init()
{
    m[' ']=1;
    m['a']=m['d']=m['g']=m['j']=m['m']=m['p']=m['t']=m['w']=1;
    m['b']=m['e']=m['h']=m['k']=m['n']=m['q']=m['u']=m['x']=2;
    m['c']=m['f']=m['i']=m['l']=m['o']=m['r']=m['v']=m['y']=3;
                                       m['s']=       m['z']=4;
}

int main()
{
    //freopen("11530.INP","r",stdin);
    //freopen("11530.OUT","w",stdout);
    init();
    scanf("%d",&tcs);
    getchar();
    for(int t=1;t<=tcs;t++)
    {
        int cnt=0;
        gets(s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
            cnt+=m[s[i]];
        printf("Case #%d: %d\n",t,cnt);
    }
    return 0;
}
