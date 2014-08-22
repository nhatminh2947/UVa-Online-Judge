//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10929 - You can say 11
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

char n[1005];

int main()
{
    //freopen("10929.INP","r",stdin);
    //freopen("10929.OUT","w",stdout);
    while(scanf(" %s ",&n))
    {
        if(n[0]=='0' && n[1]=='\0') break;
        int len=strlen(n);
        int s_odd=0,s_even=0;
        for(int i=0;i<len;i++)
        {
            if(i%2==0)
                s_even+=(n[i]-'0');
            else s_odd+=(n[i]-'0');
        }
        int k=abs(s_odd-s_even);
        if(k%11==0) printf("%s is a multiple of 11.\n",n);
        else printf("%s is not a multiple of 11.\n",n);
    }
    return 0;
}
