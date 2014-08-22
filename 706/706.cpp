#include "cstdio"
#include "string.h"

char out[50][150];
int s;
char n[20];

int draw()
{
    int x=0;
    for(int i=0;i<strlen(n);i++)
    {
        if(n[i]=='0')
        {
            for(int j=1;j<=(2*s+3);j++)
                for(int k=1;k<=(s+2);k++)
                {
                    if((j==1 && (2<=k && k<=s+1)) || (j==(2*s+3) && (2<=k && k<=s+1)))
                        out[j][k+x]='-';
                    else if(j!=((2*s+3)/2+1) && j!=1 && j!=(2*s+3) && (k==1 || k==s+2))
                        out[j][k+x]='|';
                    else 
                        out[j][k+x]=' ';
                }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='1')
        {
            for(int j=1;j<=(2*s+3);j++)
                 for(int k=1;k<=(s+2);k++)
                 {
                     if(j!=((2*s+3)/2+1) && j!=1 && j!=(2*s+3) && k==s+2)
                         out[j][k+x]='|';
                     else 
                         out[j][k+x]=' ';
                 }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='2')
        {
            for(int j=1;j<=(2*s+3);j++)
                for(int k=1;k<=(s+2);k++)
                {
                    if((j==1 && (2<=k && k<=s+1)) || (j==((2*s+3)/2+1)&& (2<=k && k<=s+1)) ||(j==(2*s+3) && (2<=k && k<=s+1)))
                        out[j][k+x]='-';
                    else if((k==s+2 && 1<j && j<(2*s+3)/2+1) || (k==1 && ((2*s+3)/2+1)<j && j<(2*s+3)))
                        out[j][k+x]='|';
                    else 
                        out[j][k+x]=' ';
                }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='3')
        {
            for(int j=1;j<=(2*s+3);j++)
                 for(int k=1;k<=(s+2);k++)
                 {
                     if((j==1 && (2<=k && k<=s+1)) || (j==((2*s+3)/2+1)&& (2<=k && k<=s+1)) ||(j==(2*s+3) && (2<=k && k<=s+1)))
                            out[j][k+x]='-';
                     else if(j!=((2*s+3)/2+1) && j!=1 && j!=(2*s+3) && k==s+2)
                         out[j][k+x]='|';
                     else 
                         out[j][k+x]=' ';
                 }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='4')
        {
            for(int j=1;j<=(2*s+3);j++)
                 for(int k=1;k<=(s+2);k++)
                 {
                     if(j==((2*s+3)/2+1)&& (2<=k && k<=s+1))
                            out[j][k+x]='-';
                     else if((k==1 && 1<j && j<(2*s+3)/2+1) || j!=((2*s+3)/2+1) && j!=1 && j!=(2*s+3) && k==s+2)
                         out[j][k+x]='|';
                     else 
                         out[j][k+x]=' ';
                 }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='5')
        {
            for(int j=1;j<=(2*s+3);j++)
                for(int k=1;k<=(s+2);k++)
                {
                    if((j==1 && (2<=k && k<=s+1)) || (j==((2*s+3)/2+1)&& (2<=k && k<=s+1)) ||(j==(2*s+3) && (2<=k && k<=s+1)))
                        out[j][k+x]='-';
                    else if((k==1 && 1<j && j<(2*s+3)/2+1) || (k==s+2 && ((2*s+3)/2+1)<j && j<(2*s+3)))
                        out[j][k+x]='|';
                    else 
                        out[j][k+x]=' ';
                }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='6')
        {
            for(int j=1;j<=(2*s+3);j++)
                for(int k=1;k<=(s+2);k++)
                {
                    if((j==1 && (2<=k && k<=s+1)) || (j==((2*s+3)/2+1)&& (2<=k && k<=s+1)) ||(j==(2*s+3) && (2<=k && k<=s+1)))
                        out[j][k+x]='-';
                    else if(j!=((2*s+3)/2+1) && (k==1 && 1<j && j<2*s+3) || (k==s+2 && ((2*s+3)/2+1)<j && j<(2*s+3)))
                        out[j][k+x]='|';
                    else 
                        out[j][k+x]=' ';
                }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='7')
        {
            for(int j=1;j<=(2*s+3);j++)
                 for(int k=1;k<=(s+2);k++)
                 {
                     if(j==1 && (2<=k && k<=s+1))
                            out[j][k+x]='-';
                     else if(j!=((2*s+3)/2+1) && j!=1 && j!=(2*s+3) && k==s+2)
                         out[j][k+x]='|';
                     else 
                         out[j][k+x]=' ';
                 }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='8')
        {
            for(int j=1;j<=(2*s+3);j++)
                for(int k=1;k<=(s+2);k++)
                {
                    if((j==1 || j==(2*s+3) || j==(2*s+3)/2+1) && (2<=k && k<=s+1))
                        out[j][k+x]='-';
                    else if(j!=((2*s+3)/2+1) && j!=1 && j!=(2*s+3) && (k==1 || k==s+2))
                        out[j][k+x]='|';
                    else 
                        out[j][k+x]=' ';
                }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
        else if(n[i]=='9')
        {
            for(int j=1;j<=(2*s+3);j++)
                for(int k=1;k<=(s+2);k++)
                {
                    if((j==1 || j==(2*s+3)/2+1 || j==(2*s+3)) && (2<=k && k<=s+1))
                        out[j][k+x]='-';
                    else if((k==1 && (1<j && j<(2*s+3)/2+1)) || (k==s+2 && j!=(2*s+3)/2+1 && j!=1 && j!=(2*s+3)))
                        out[j][k+x]='|';
                    else 
                        out[j][k+x]=' ';
                }
            if(i!=strlen(n)-1)
                for(int j=1;j<=(2*s+3);j++)
                    out[j][x+s+3]=' ';
            x+=s+3;
        }
    }
    for(int j=1;j<=(2*s+3);j++)
        {
            for(int k=1;k<=((s+3)*strlen(n)-1);k++)
                 printf("%c",out[j][k]);
            printf("\n");
        }
}

int main()
{
    //freopen("706.INP","r",stdin);
    //freopen("706.OUT","w",stdout);
    while(scanf("%d",&s))
    {
        getchar();
        gets(n);
        if(s==0 && n[0]=='0') break;
        int k=strlen(n);
        for(int i=0;i<k;i++)
        {
            if(n[0]=='0' && n[1]=='\0') break;
            else if(n[0]=='0')
            {
                for(int j=0;j<k;j++)
                    n[j]=n[j+1];
                i--;
                k--;
            }
        }
        draw();
        printf("\n");
    }
    return 0;
}
