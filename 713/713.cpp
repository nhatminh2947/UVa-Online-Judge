//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 713 - Adding Reversed Numbers
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

typedef char BigNum[205];

int tcs;
BigNum a,b,res;

void plusBN(BigNum a,BigNum b)
{
    fill(res,res+201,'0');
    char carry='0';
    for(int i=200;i>=0;i--)
    {
        res[i]=a[i]-'0'+b[i]-'0'+carry;
        carry=(res[i]-'0')/10+'0';
        res[i]-='0';
        res[i]%=10;
        res[i]+='0';
    }
}

int main()
{
    //freopen("713.INP","r",stdin);
    //freopen("713.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=0;t<tcs;t++)
    {
        int len,k;
        BigNum t1,t2;
        scanf(" %s %s ",&t1,&t2);
        
        if(t1[0]=='0' && t2[0]=='0')
        {
            printf("0\n");
            continue;
        }
        
        fill(a,a+205,'0');
        fill(b,b+205,'0');
        
        len=strlen(t1);
        k=200;
        for(int i=0;i<len;i++)
            a[k--]=t1[i];
            
        len=strlen(t2);
        k=200;
        for(int i=0;i<len;i++)
            b[k--]=t2[i];
        
        plusBN(a,b);
        
        len=strlen(res)-1;
        
        for(int j=0;j<=len;j++)
            if(res[j]!='0')
            {
                for(int i=len;i>=0;i--)
                    if(res[i]!='0')
                    {
                        while(i>=j)
                        {
                            printf("%c",res[i]);
                            i--;
                        }
                        break;
                    }
                break;
            }
        printf("\n");
    }
    return 0;
}
