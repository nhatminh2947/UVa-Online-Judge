//**********************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 10700 - Camel trading
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

char f[300];
int tcs;
stack<double> cal;
bool oper;

int main()
{
    freopen("10700.INP","r",stdin);
    freopen("10700.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=0;i<tcs;i++)
    {
        scanf(" %s ",&f);
        int len=strlen(f);
        
        oper=false;
        for(int i=0;i<len;i++)
        {
            if(f[i]!='+' && f[i]!='*')
            {
                int tmp=0;
                int k=i;
                while(f[k]!='+' && f[k]!='*' && f[k]!='\0')
                {
                    tmp=tmp*10+(f[k]-'0');
                    k++;
                }
                cal.push(tmp);
                if(oper)
                {
                    double a=cal.top();
                    cal.pop();
                    double b=cal.top();
                    cal.pop();
                    cal.push(a*b);
                    oper=false;
                }
                if(f[k]=='*') oper=true;
                i=k;
            }
        }
        double min=0;
        while(!cal.empty())
        {
            min+=cal.top();
            cal.pop();
        }
        
        oper=false;
        for(int i=0;i<len;i++)
        {
            if(f[i]!='+' && f[i]!='*')
            {
                int tmp=0;
                int k=i;
                while(f[k]!='+' && f[k]!='*' && f[k]!='\0')
                {
                    tmp=tmp*10+(f[k]-'0');
                    k++;
                }
                cal.push(tmp);
                if(oper)
                {
                    double a=cal.top();
                    cal.pop();
                    double b=cal.top();
                    cal.pop();
                    cal.push(a+b);
                    oper=false;
                }
                if(f[k]=='+') oper=true;
                i=k;
            }
        }
        double max=1;
        while(!cal.empty())
        {
            max*=cal.top();
            cal.pop();
        }
        
        printf("The maximum and minimum are %.lf and %.lf.\n",max,min);
    }
    return 0;
}
