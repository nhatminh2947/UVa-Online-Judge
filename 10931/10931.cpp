//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10931 - Parity
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

int main()
{
    //freopen("10931.INP","r",stdin);
    //freopen("10931.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
        stack<int> s;
        int cnt=0;
        printf("The parity of ");
        while(n)
        {
            s.push(n%2);
            if(n%2==1) cnt++;
            n/=2;
        }
        while(!s.empty())
        {
            printf("%d",s.top());
            s.pop();
        }
        printf(" is %d (mod 2).\n",cnt);
    }
    return 0;
}
