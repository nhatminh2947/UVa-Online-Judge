//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 571 - Jugs
// Verdict:
//**********************************************
#include <iostream>
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
#define INF 999999999
#define PI 3,1415926535

using namespace std;

int Ca,Cb,n;
int a,b;

int main()
{
    //freopen("571.INP","r",stdin);
    //freopen("571.OUT","w",stdout);
    while(scanf(" %d %d %d ",&Ca,&Cb,&n)==3)
    {
        a=0,b=0;
        while(b!=n)
        {
            if(!a)
            {
                a=Ca;
                printf("fill A\n");
            }
            else
            {
                if(a+b<=Cb)
                {
                    b+=a;
                    a=0;
                    printf("pour A B\n");
                }
                else
                {
                    a-=(Cb-b);
                    printf("pour A B\n");
                    b=0;
                    printf("empty B\n");
                }
            }
        }
        printf("success\n");
    }
    return 0;
}
