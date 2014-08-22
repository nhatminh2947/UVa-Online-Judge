//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 11223 - O: dah dah dah!
// Verdict: Accepted
//******************************************************************
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
#define PI 3.1415926535
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;

int tcs;
char s[2005];
map<string,char> m;

void init()
{
    m[".-"]='A';
    m["-..."]='B';
    m["-.-."]='C';
    m["-.."]='D';
    m["."]='E';
    m["..-."]='F';
    m["--."]='G';
    m["...."]='H';
    m[".."]='I';
    m[".---"]='J';
    m["-.-"]='K';
    m[".-.."]='L';
    m["--"]='M';
    m["-."]='N';
    m["---"]='O';
    m[".--."]='P';
    m["--.-"]='Q';
    m[".-."]='R';
    m["..."]='S';
    m["-"]='T';
    m["..-"]='U';
    m["...-"]='V';
    m[".--"]='W';
    m["-..-"]='X';
    m["-.--"]='Y';
    m["--.."]='Z';
    m["-----"]='0';
    m[".----"]='1';
    m["..---"]='2';
    m["...--"]='3';
    m["....-"]='4';
    m["....."]='5';
    m["-...."]='6';
    m["--..."]='7';
    m["---.."]='8';
    m["----."]='9';
    m[".-.-.-"]='.';
    m["--..--"]=',';
    m["..--.."]='?';
    m[".----."]='\'';
    m["-.-.--"]='!';
    m["-..-."]='/';
    m["-.--."]='(';
    m["-.--.-"]=')';
    m[".-..."]='&';
    m["---..."]=':';
    m["-.-.-."]=';';
    m["-...-"]='=';
    m[".-.-."]='+';
    m["-....-"]='-';
    m["..--.-"]='_';
    m[".-..-."]='"';
    m[".--.-."]='@';
}

int main()
{
    //freopen("11223.INP","r",stdin);
    //freopen("11223.OUT","w",stdout);
    init();
    scanf(" %d ",&tcs);
    for(int t=0;t<tcs;t++)
    {
        if(t) printf("\n");
        printf("Message #%d\n",t+1);
        gets(s);
        int len=strlen(s);
        int n=0;
        string str;
        str.clear();
        for(int i=0;i<len;i++)
        {
            if(s[i]!=' ')
                str+=s[i];
            else
            {
                if(str.size()!=0)
                {
                    printf("%c",m[str]);
                    str.clear();
                }
                if(s[i+1]==' ')
                {
                    printf(" ");
                    i++;
                }
            }
        }
        if(str.size()!=0)
            printf("%c",m[str]);
        printf("\n");
    }
    return 0;
}
