//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 401 - Palindromes
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

string s;
int m[300];

void init()
{
    m['A'] = 'A';
    m['E'] = '3';
    m['H'] = 'H';
    m['I'] = 'I';
    m['J'] = 'L';
    m['L'] = 'J';
    m['M'] = 'M';
    m['O'] = 'O';
    m['A'] = 'A';
    m['S'] = '2';
    m['T'] = 'T';
    m['U'] = 'U';
    m['V'] = 'V';
    m['W'] = 'W';
    m['X'] = 'X';
    m['Y'] = 'Y';
    m['Z'] = '5';
    m['1'] = '1';
    m['2'] = 'S';
    m['3'] = 'E';
    m['5'] = 'Z';
    m['8'] = '8';
}

int main()
{
    freopen("401 - Palindromes.INP","r",stdin);
    freopen("401 - Palindromes.OUT","w",stdout);
    init();
    while(cin >> s)
    {
        cout << s;
        int sz = s.size();
        int l = sz/2;
        int ans = 0;
        
        bool c1 = true;
        bool c2 = true;
        for(int i = 0 ; i <= l && (c1 || c2) ; i++)
        {
            if(s[i] != s[sz-1-i])
                c1 = false;
            if(s[i] != m[s[sz-1-i]])
                c2 = false;
        }
        if(c1)
            ans += 1;
        if(c2)
            ans += 2;
            
        if(ans == 0)
            printf(" -- is not a palindrome.\n");
        else if(ans == 1)
            printf(" -- is a regular palindrome.\n");
        else if(ans == 2)
            printf(" -- is a mirrored string.\n");
        else if(ans == 3)
            printf(" -- is a mirrored palindrome.\n");
        printf("\n");
    }
    
    return 0;
}
