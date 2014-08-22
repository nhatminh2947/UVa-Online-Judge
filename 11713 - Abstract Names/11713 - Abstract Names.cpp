//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11713 - Abstract Names
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    freopen("11713 - Abstract Names.INP","r",stdin);
    freopen("11713 - Abstract Names.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        char s1[50],s2[50];
        gets(s1);
        gets(s2);
        
        int sz1 = strlen(s1);
        int sz2 = strlen(s2);
        bool check = true;
        if(sz1 != sz2)
            check = false;
        else
        {
            for(int i = 0 ; i < sz1 && check ; i++)
            {
                if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
                {
                    if(s2[i] != 'a' && s2[i] != 'e' && s2[i] != 'i' && s2[i] != 'o' && s2[i] != 'u')
                    {
                        //cout << i << endl;
                        check = false;
                    }
                }
                else if(s1[i] != s2[i])
                    check = false;
            }
        }
        
        if(check)
            puts("Yes");
        else puts("No");
    }
    
    return 0;
}
