//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10055 - Hashmat the Brave Warrior
// Time limit: 3s
//==============================================================

#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    //freopen("10055.INP","r",stdin);
    //freopen("10055.OUT","w",stdout);
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
        printf("%lld\n",abs(b-a));
    return 0;
}
