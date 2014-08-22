//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 455 - Periodic Strings
// Verdict: Accepted
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

int n;
char s[85];

int main()
{
    //freopen("455.INP","r",stdin);
    //freopen("455.OUT","w",stdout);
    scanf(" %d ",&n);
    for(int i=0;i<n;i++)
    {
        if(i) printf("\n");
        scanf(" %s ",&s);
        int len=strlen(s);
        queue<char> q;
        q.push(s[0]);
        for(int i=0;i<len;i++)
        {
            if(s[i]==q.front())
                q.pop();
            q.push(s[i]);
        }
        int sz=q.size();
        if(len%sz==0)
            printf("%d\n",sz);
        else printf("%d\n",len);
    }
    return 0;
}
