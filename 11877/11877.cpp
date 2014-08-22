//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11877 - The Coco-Cola Store
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int n;

int main()
{
    //freopen("11877.INP","r",stdin);
    //freopen("11877.OUT","w",stdout);
    while(scanf(" %d ",&n) && n)
    {
        int ans=0;
        int carry;
        int borrow=0;
        while(n>=3 && n/3>=borrow)
        {
            ans+=n/3;
            carry=n%3;
            n=n/3+carry;
            if(n<3) borrow=3-n;
            else borrow=0;
            n+=borrow;
        }
        printf("%d\n",ans);
    }
    return 0;
}
