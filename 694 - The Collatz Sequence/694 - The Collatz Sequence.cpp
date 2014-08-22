//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 694 - The Collatz Sequence
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

#define int64 long long

using namespace std;

int64 a,l;

int main()
{
    freopen("694 - The Collatz Sequence.INP","r",stdin);
    freopen("694 - The Collatz Sequence.OUT","w",stdout);
    int tcs = 1;
    while(scanf(" %lld %lld ",&a,&l))
    {
        if(a < 0 && l < 0)
            break;
        
        int cnt = 1;
        int64 tmp = a;
        while(tmp != 1)
        {
            if(tmp%2 == 0)
                tmp /= 2;
            else
                tmp = tmp*3 + 1;
            if(tmp > l)
                break;
            cnt++;
        }
        
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",tcs++,a,l,cnt);
    }
    
    return 0;
}
