//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 10038 - Jolly Jumpers
// Time limit: 
//==============================================================

#include <cstdio>
#include <cmath>
#include <cstdlib>

int n;
int num[3005];
bool check[3005];

int main()
{
    //freopen("10038.INP","r",stdin);
    //freopen("10038.OUT","w",stdout);
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0 ; i < n ; i++)
            scanf("%d",&num[i]);
        for(int i = 1 ; i <= n-1 ; i++)
            check[i] = false;
        
        for(int i = 1 ; i < n ; i++)    
        {
            int k = abs(num[i] - num[i-1]);
            check[k] = true;
        }
        
        bool Jolly = true;
        for(int i = 1 ; i <= n-1 ; i++)
            if(check[i] == false)
            {
                Jolly = false;
                break;
            }
        
        if(Jolly) puts("Jolly");
        else puts("Not Jolly");
    }
    return 0;
}
