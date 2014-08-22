//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10921 - Find the Telephone
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int m[250];

void init()
{
    m['A'] = '2';
    m['B'] = '2';
    m['C'] = '2';
    m['D'] = '3';
    m['E'] = '3';
    m['F'] = '3';
    m['G'] = '4';
    m['H'] = '4';
    m['I'] = '4';
    m['J'] = '5';
    m['K'] = '5';
    m['L'] = '5';
    m['M'] = '6';
    m['N'] = '6';
    m['O'] = '6';
    m['P'] = '7';
    m['Q'] = '7';
    m['R'] = '7';
    m['S'] = '7';
    m['T'] = '8';
    m['U'] = '8';
    m['V'] = '8';
    m['W'] = '9';
    m['X'] = '9';
    m['Y'] = '9';
    m['Z'] = '9';
    m['-'] = '-';
    m['0'] = '0';
    m['1'] = '1';
    m['2'] = '2';
    m['3'] = '3';
    m['4'] = '4';
    m['5'] = '5';
    m['6'] = '6';
    m['7'] = '7';
    m['8'] = '8';
    m['9'] = '9';
}

int main()
{
    //freopen("10921 - Find the Telephone.INP","r",stdin);
    //freopen("10921 - Find the Telephone.OUT","w",stdout);
    init();
    char s[100];
    while(gets(s))
    {
        int sz = strlen(s);
        for(int i = 0 ; i < sz ; i++)
            printf("%c",m[s[i]]);
        printf("\n");
    }
    
    return 0;
}

