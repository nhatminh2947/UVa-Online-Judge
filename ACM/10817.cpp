//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number:
// Verdict:
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
#define PI 3,1415926535

using namespace std;

struct tc
{
    int cost;
    int list[9];
    bool operator < (const tc &other) const
    {
        return cost < other.cost;
    }
};
int n,su,m,ans;
tc data[100];
bool used[111];
bool checkall(const int arr[])
{
    for (int i = 1; i <= su ; i++)
        if (arr[i]) return 0;
    return 1;
}

void cpy(int arr[],const int brr[])
{
    for (int i = 1 ; i <= su; i++)
        arr[i] = brr[i];
}
/*
int choose(int n,const int arr[],int sum)
{
    if (checkall(arr)) return sum;
    int marr[10];
    cpy(marr,arr);
    for (int i = 0 ; i < data[n].n ; i++){
        if (marr[data[n].list[i]]) marr[data[n].list[i]]--;
    }
    
    if (n == 0)
        if (checkall(marr)) return sum + data[n].cost;
            else return INF;
    int s1 = choose(n - 1,marr, sum + data[n].cost);
    int s2 = choose(n - 1,arr, sum);
    //printf("%d %d\n",s1,s2);
    return min(s1,s2);
}*/
int full[10];
void mytry(int p,int ss){
    if ( full[p] <= 0 ){
        if ( p == n ){
            ans = min(ans,ss);
        }else{
            mytry(p+1,ss);
        }
    }else{
        for(int i = 1 ; i <= n ;i++){
            if ( !used[i] && data[i].list[p] && ss + data[i].cost < ans ){
                used[i] = true;
                for(int j = 1 ; j <= su ; j++){
                    if ( data[i].list[j] ){
                        full[j]--;
                    }
                }
                mytry(p,ss+data[i].cost);
                used[i] = false;
                for(int j = 1 ; j <= su ; j++){
                    if ( data[i].list[j] ){
                        full[j]++;
                    }
                }
            }
        }
    }
}



int main()
{
    freopen("10817.INP","r",stdin);
    freopen("10817.OUT","w",stdout);
    char s[1000];
    
    
    while (scanf("%d %d %d ",&su,&m,&n) && (n + su + m))
    {
        int total2 = 0;
        for (int i = 1 ; i <= su ; i++)
            full[i] = 2;
        for (int i = 0 ; i < m ; i++)
        {
            gets(s);
            int cost;
            sscanf(s,"%d",&cost);
            total2 += cost;
            int p = 0;
            int len = strlen(s);
            while (p < len && s[p] != 32) p++;
            
            while (p < len)
            {
                int sub;
                sscanf(s + p,"%d",&sub);
                if (full[sub] > 0)
                    full[sub]--;
                while (p < len && s[p] == 32) p++;
                while (p < len && s[p] != 32) p++;
            }
        }
       // for(int i = 1 ; i <= su ; i++){
//            printf("%d ",full[i]);
//        }
//        puts("");
        for (int i = 1 ; i <= n ; i++)
        {
            memset(data[i].list, false, sizeof(data[i].list));
            gets(s);
            int cost;
            sscanf(s,"%d",&cost);
            data[i].cost=cost;
            int p = 0;
            int len = strlen(s);
            while (p < len && s[p] != 32) p++;
            
            while (p < len)
            {
                int sub;
                sscanf(s + p,"%d",&sub);
                data[i].list[sub] = true;
                while (p < len && s[p] == 32) p++;
                while (p < len && s[p] != 32) p++;
            }
            used[i] = false;
        }
        sort(data+1,data+1+n);
        ans = INF;
        mytry(1,total2);
        printf("%d\n",ans);
    }
    return 0;
}
