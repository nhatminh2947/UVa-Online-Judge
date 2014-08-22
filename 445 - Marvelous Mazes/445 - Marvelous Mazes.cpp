//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:  445 - Marvelous Mazes
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

char s[150];

int main()
{
	freopen("445 - Marvelous Mazes.INP","r",stdin);
	freopen("445 - Marvelous Mazes.OUT","w",stdout);
	
	while(gets(s))
	{
	    if(s[0] == '\0')
	    {
            printf("\n");
            continue;
	    }
        
        int sz = strlen(s);
        int n = 0;
        for(int i = 0 ; i < sz ; i++)
        {
            if('0' <= s[i] && s[i] <= '9')
                n += (s[i] - '0');
            else if(s[i] == 'b')
            {
                for(int i = 0 ; i < n ; i++)
                    printf(" ");
                n = 0;
            }
            else if(s[i] == '!')
            {
                printf("\n");
                n = 0;
            }
            else
            {
                for(int j = 0 ; j < n ; j++)
                    printf("%c",s[i]);
                n = 0;
            }
        }
        
        if(s[sz-1] != '!')
            printf("\n");
	}

	return 0;
}

