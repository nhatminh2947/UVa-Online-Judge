//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number:  102 - Ecological Bin Packing
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
#define INF 2147483648

using namespace std;

int B[5],G[5],C[5];
string str;
int main()
{
    //freopen("102.INP","r",stdin);
    //freopen("102.OUT","w",stdout);
    while(scanf(" %d %d %d %d %d %d %d %d %d ",&B[1],&G[1],&C[1],&B[2],&G[2],&C[2],&B[3],&G[3],&C[3])!=EOF)
    {
        int min=B[2]+B[3]+G[1]+G[2]+C[1]+C[3];
        str="BCG";
        if(min>(B[2]+B[3]+G[1]+G[3]+C[1]+C[2]))
        {
            str="BGC";
            min=B[2]+B[3]+G[1]+G[3]+C[1]+C[2];
        }
        if(min>(B[1]+B[3]+G[1]+G[2]+C[2]+C[3]))
        {
            str="CBG";
            min=B[1]+B[3]+G[1]+G[2]+C[2]+C[3];
        }
        if(min>(B[1]+B[2]+G[1]+G[3]+C[2]+C[3]))
        {
            str="CGB";
            min=B[1]+B[2]+G[1]+G[3]+C[2]+C[3];
        }
        if(min>(B[1]+B[3]+G[2]+G[3]+C[1]+C[2]))
        {
            str="GBC";
            min=B[1]+B[3]+G[2]+G[3]+C[1]+C[2];
        }
        if(min>(B[1]+B[2]+G[2]+G[3]+C[1]+C[3]))
        {
            str="GCB";
            min=B[1]+B[2]+G[2]+G[3]+C[1]+C[3];
        }
        cout<<str;
        printf(" %d\n",min);
    }
    return 0;
}
