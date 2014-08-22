#include <stdio.h>
#include <string.h>

char ts[1000];
int h,m,s,sp=0,newsp,now,time=0;
int n;
float km=0;

int main()
{
    //freopen("10281.INP","r",stdin);
    //freopen("10281.OUT","w",stdout);
    while(gets(ts))
    {
        n=sscanf(ts,"%d:%d:%d %d",&h,&m,&s,&newsp);
        now = h * 3600 + m * 60 + s;
		km += (now - time) * sp;
		time = now;

		if (n == 3)
			printf("%02d:%02d:%02d %.2lf km\n", h, m, s, km/3600);
		else if (n == 4)
			sp = newsp;
    }
    return 0;
}
