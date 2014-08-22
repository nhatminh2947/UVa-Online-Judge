#include "cstdio"
#include "string.h"

char in[55];
char out[110][55];

int draw(char in[])
{
    bool lock=true;
    int x=2;
    int y=55;
    int save;
    for(int i=0;i<strlen(in);i++)
    {
        if(in[i]=='R')
        {
            if(in[i-1]=='F')
                 y--;
            out[y][x]='/';
            y--;
            x++;
        }
        else if(in[i]=='F')
        {
            if(in[i-1]=='R')
                y++;
            else if(in[i-1]=='C')
                y++;
            out[y][x]='\\';
            y++;
            x++;
        }
        else if(in[i]=='C')
        {
            if(in[i-1]=='F')
                y--;
            out[y][x]='_';
            x++;
        }
    }
    for(int i=0;i<110;i++)
    {
        for(int k=54;k>=0;k--)
        {
            if(out[i][k]!='\0')
            {
                lock=false;
                save=k;
                break;
            }
        }
        if(lock==false)
            for(int j=0;j<=save;j++)
            {
                out[i][0]='|';
                if(out[i][j]=='\0') 
                    printf(" ");
                else
                    printf("%c",out[i][j]);
                out[i][j]='\0';
                out[i][0]='\0';
            }
        if(lock==false)printf("\n");
        lock=true;
    }
    printf("+");
    for(int i=0;i<=strlen(in)+1;i++)
        printf("-");
    printf("\n");
}

int main()
{
    freopen("10800.INP","r",stdin);
    freopen("10800.OUT","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&in);
        printf("Case #%d:\n",i);
        draw(in);
        printf("\n");
    }
    return 0;
}
