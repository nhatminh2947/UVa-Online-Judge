#include "cstdio"
#include "string.h"

char s[20],snum3[5],sym1,sym2;
int num1,num2;

int main()
{
    freopen("11878.INP","r",stdin);
    freopen("11878.OUT","w",stdout);
    int count=0;
    while(scanf("%s",&s)!=EOF)
    {
        int num3=0;
        sscanf(s,"%d%c%d%c%s",&num1,&sym1,&num2,&sym2,&snum3);
        if(snum3[0]!='?')
        {
            for(int i=0;i<strlen(snum3);i++)
                num3=num3*10+(snum3[i]-48);
            if((sym1=='+' && num1+num2==num3) || (sym1=='-' && num1-num2==num3))
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
