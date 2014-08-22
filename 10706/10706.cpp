//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10706 - Number Sequence
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
#define INF 1000000000
#define E 2,71828183
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs,n;
vector<int> seq;

void sequence()
{
    for(int i=1;i<=2147483647;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int k=j;
            while(k)
            {
                if(k<10)
                {
                    seq.push_back(k);
                    break;
                }
                seq.push_back(k/10);
                k%=10;
            }
        }
        
        if(seq.size()>=100000000)
        {
            cout<<i<<endl;
            break;
        }
    }
}

int main()
{
    freopen("10706.INP","r",stdin);
    freopen("10706.OUT","w",stdout);
    sequence();
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        
    }
    return 0;
}
