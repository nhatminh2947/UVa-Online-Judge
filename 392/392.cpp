//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 392 - Polynomial Showdown
//==============================================================

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
#define INF 99999999

using namespace std;

int num[10];

int main()
{
    //freopen("392.INP","r",stdin);
    //freopen("392.OUT","w",stdout);
    while(scanf(" %d %d %d %d %d %d %d %d %d ",&num[8],&num[7],&num[6],&num[5],&num[4],&num[3],&num[2],&num[1],&num[0])!=EOF)
    {
        bool lock=true;
        if(num[8]==0 && num[7]==0 && num[6]==0 && num[5]==0 && num[4]==0 && num[3]==0 && num[2]==0 && num[1]==0 && num[0]==0) printf("0\n");
        else
        {
            for(int i=8;i>=0;i--)
                if(num[i]!=0)
                {
                    if(lock==false && num[i]<0) printf(" - ");
                    else if(lock==false && num[i]>0) printf(" + ");
                    else if(lock==true && num[i]<0) printf("-");
                    lock=false;
                    if(abs(num[i])!=1 && i!=0) printf("%d",abs(num[i]));
                    else if(i==0) printf("%d",abs(num[i]));
                    if(i!=0) printf("x");
                    if(i!=1 && i!=0) printf("^%d",i);
                }
            printf("\n");
        }
    }
    return 0;
}
