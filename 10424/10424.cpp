//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10424 - Love Calculator
// Verdict: Accepted
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

char n1[30],n2[30];

int cal(char s[])
{
    int len=strlen(s);
    int S=0;
    for(int i=0;i<len;i++)
    {
        if('a'<=s[i] && s[i]<='z')
            S+=(s[i]-'a'+1);
        else if('A'<=s[i] && s[i]<='Z')
            S+=(s[i]-'A'+1);
    }
    while(S>9)
    {
        int tmp=S;
        int t=0;
        while(tmp)
        {
            t+=tmp%10;
            tmp/=10;
        }
        S=t;
    }
    return S;
}

int main()
{
    //freopen("10424.INP","r",stdin);
    //freopen("10424.OUT","w",stdout);
    while(gets(n1) && gets(n2))
    {
        int S1=cal(n1);
        int S2=cal(n2);
        if(S1>S2)
            swap(S1,S2);
        double res=(float)S1/(float)S2;
        printf("%.2lf %%\n",res*100);
    }
    return 0;
}
