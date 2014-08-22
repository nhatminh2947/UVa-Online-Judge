//==============================================================
// Name: Huynh Nhat Minh
// Problem Number: 11034 - Ferry Loading IV
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

using namespace std;

int c,l,m;

int main()
{
    freopen("11034.INP","r",stdin);
    freopen("11034.OUT","w",stdout);
    string bank;
    int length;
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        queue<int> left,right;
        scanf("%d%d",&l,&m);
        l*=100;
        scanf(" ");
        for(int j=0;j<m;j++)
        {
            cin>>length;
            cin>>bank;
            if(bank=="left") left.push(length);
            if(bank=="right") right.push(length);
        }
        int sum,count=0,countl=0,countr=0;
        string check="left";
        while(!left.empty() || !right.empty())
        {
            if(check=="left")
            {
                sum=0;
                while (!left.empty() && sum + left.front()<=l)
                {
                    sum+=left.front();
                    left.pop();
                }
                count++;
                check="right";
            }
            else if(check=="right")
            {
                sum=0;
                while (!right.empty() && sum+right.front()<=l)
                {
                    sum+=right.front();
                    right.pop();
                }
                count++;
                check="left";
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
