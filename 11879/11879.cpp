//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11879 - Multiple of 17
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

long long mod(string x)
{
    long long n=0;
    int sz=x.size();
    for(int i=0;i<sz;i++)
        n=(n*10 + x[i]-'0')%17;
    return n;
}

int main()
{
    //freopen("11879.INP","r",stdin);
    //freopen("11879.OUT","w",stdout);
    string num;
    while(cin>>num)
    {
        if(num=="0") break;
        int n=mod(num);
        if(n==0) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
