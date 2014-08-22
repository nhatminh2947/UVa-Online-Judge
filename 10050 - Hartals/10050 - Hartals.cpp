//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10050 - Hartals
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

#define INF 1000111222
#define pb push_back
#define mp make_pair
#define maxN 123456

using namespace std;

int n,p;
bool check[4000];

int main()
{
    freopen("10050 - Hartals.INP","r",stdin);
    freopen("10050 - Hartals.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        scanf(" %d ",&p);
        for(int i = 0 ; i <= n ; i++)
            check[i] = false;
        for(int i = 0 ; i < p ; i++)
        {
            int k;
            scanf(" %d ",&k);
            
            if(k <= n && !check[k])
            {
                for(int j = k ; j <= n ; j+= k)
                    check[j] = true;
            }
        }
        
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++)
            if(check[i] && (i % 7) != 6 && (i % 7) != 0)
                cnt++;
        printf("%d\n",cnt);
    }
    
    return 0;
}

