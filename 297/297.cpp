//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 297 - Quadtrees
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
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs;
string s1,s2;
bool i1[35][35],i2[35][35];

int solve()
{
    
}

int main()
{
    freopen("297.INP","r",stdin);
    freopen("297.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %s %s ",&s1,&s2);
        int sz1=s1.size();
        int sz2=s2.size();
        //string s="";
        int i=0,j=0;
        while(i!=sz1)
        {
            if(s1[i]=='f')
            {
                
            }
            
            i++;
            j++;
        }
    }
    return 0;
}
