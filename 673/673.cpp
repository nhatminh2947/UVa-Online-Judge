#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

int main()
{
    //freopen("673.INP","r",stdin);
    //freopen("673.OUT","w",stdout);
    stack<char> stk;
    int n;
    string s;
    scanf("%d ",&n);
    for(int i=1;i<=n;i++)
    {
        while(!stk.empty()) stk.pop();
        getline(cin,s);
        for(int j=0;j<s.size();j++)
        {
            if (s[j]=='(' || s[j]=='[') stk.push(s[j]);
            else if ((s[j]==']' || s[j]==')') && stk.size()==0) 
            {
                stk.push(s[j]);
                break;
            }
            else if (s[j]==']' && stk.top()=='[' ) stk.pop();
            else if (s[j]==')' && stk.top()=='(' ) stk.pop();
        }
        if(stk.size()==0) printf("Yes\n");
        else printf("No\n");
    }
}
