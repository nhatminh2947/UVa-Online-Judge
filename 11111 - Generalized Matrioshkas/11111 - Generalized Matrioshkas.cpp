//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 11111 - Generalized Matrioshkas
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
#define int64 long long
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define read2(x,y) scanf(" %d %d ",&x,&y)
#define read3(x,y,z) scanf(" %d %d %d ",&x,&y,&z)
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

int n;
char s[1000000];
int a[maxN];

int main()
{
    freopen("11111 - Generalized Matrioshkas.INP","r",stdin);
    freopen("11111 - Generalized Matrioshkas.OUT","w",stdout);
    
    while(gets(s))
    {
        stack<int> stk;
        int sz = strlen(s);
        s[sz] = ' ';
        s[sz+1] = '\0';
        sz = strlen(s);
        int neg = 1;
        n = 0;
        bool ans = true;
        for(int i = 0 ; i < sz ; i++)
        {
            if(s[i] == ' ')
            {
                n *= neg;
                
                if(n > 0)
                {
                    int sum = 0;
                    while(stk.size() && stk.top() > 0)
                    {
                        sum += stk.top();
                        stk.pop();
                    }
                    
                    if(stk.empty() || stk.top() != -n)
                    {
                        ans = false;
                        break;
                    }
                    
                    if(sum < n)
                    {
                        stk.pop();
                        stk.push(n);
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }
                else if(n < 0)
                    stk.push(n);
                neg = 1;
                n = 0;
            }
            else if(s[i] == '-') neg = -1;
            else n = n*10 + (s[i] - '0');
        }
        
        while(!stk.empty())
        {
            if(stk.top() < 0)
            {
                ans = false;
                break;
            }
            stk.pop();
        }
        
        if(ans)
            puts(":-) Matrioshka!");
        else
            puts(":-( Try again.");
    }
    
    return 0;
}

