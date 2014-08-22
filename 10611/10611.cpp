//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10611 - The Playboy Chimp
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

int n,q;
int A[50005];

void BS(int target)
{
    int low=0,high=n-1;
    int mid;
    if(n==1 && A[0]==target)
    {
        printf("X X\n");
        return;
    }
    if(A[high]<=target)
    {
        while(target==A[high])
            high--;
        printf("%d X\n",A[high]);
        return;
    }
    if(target<=A[low])
    {
        while(target==A[low])
            low++;
        printf("X %d\n",A[low]);
        return;
    }
    for(int i=0;i<18;i++)
    {
        mid=(low+high)/2;
        
        if(A[mid]>target)
            high=mid;
        else if(A[mid]==target)
            high=mid+1;
        else low=mid;
    }
    while(A[high]==target) high++;
    while(A[low]==target) low--;
    printf("%d %d\n",A[low],A[high]);
}

int main()
{
    freopen("10611.INP","r",stdin);
    freopen("10611.OUT","w",stdout);
    scanf(" %d ",&n);
    for(int i=0;i<n;i++)
        scanf(" %d ",&A[i]);
    scanf(" %d ",&q);
    for(int i=0;i<q;i++)
    {
        int tmp;
        scanf(" %d ",&tmp);
        BS(tmp);
    }
    return 0;
}
