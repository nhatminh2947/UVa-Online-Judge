//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11413 - Fill the Containers
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
#define E 2,71828183
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int n,m;
int A[1005];

bool check(int sum)
{
    int cnt=0;
    int i=0;
    while(cnt!=m && i!=n)
    {
        if(A[i]>sum)
            return false;
        int s=0;
        while(i!=n)
        {
            s+=A[i];
            if(s>sum)
                break;
            i++;
        }
        cnt++;
    }
    if(cnt<=m && i==n) return true;
    return false;
}

int BS(int sum)
{
    int left=0,right=sum;
    int mid;
    int res=sum;
    
    while(left<=right)
    {
        mid=(left+right)/2;
        
        if(check(mid))
        {
            right=mid-1;
            res=mid;
        }
        else left=mid+1;
    }
    
    return res;    
}

int main()
{
    //freopen("11413.INP","r",stdin);
    //freopen("11413.OUT","w",stdout);
    while(scanf(" %d %d ",&n,&m)==2)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf(" %d ",&A[i]);
            sum+=A[i];
        }
        cout<<BS(sum)<<endl;
    }
    return 0;
}
