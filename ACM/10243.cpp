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
int n, deg[1222];
bool use[1222], adj[1222][1222], used[1222];
int main()
{   
    freopen("10243.INP","r",stdin);
    freopen("10243.OUT","w",stdout);
    while(scanf("%d",&n)&&n){
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++){
                adj[i][j] = false;
            }
        for(int i = 1 ; i <= n ; i++){
            int k,x;
            scanf("%d",&k);
            deg[i] = k;
            while(k--){
                scanf("%d",&x);
                adj[i][x] = true;
            }
        }
        if ( n == 1 ){
            puts("1");
            continue;
        }
        for(int i = 1 ; i <= n ; i++) used[i] = false;
        while(true){
            bool found = false;
            for(int i = 1 ; i <= n ; i++){
            use[i] = false;
            }
            for(int i = 1 ; i <= n ; i++){
                if ( deg[i] == 1 ){
                    found = true;
                    for(int j = 1 ; j <= n ; j++){
                        if ( adj[i][j] ){
                            if ( deg[j] == 1 ){
                                used[j] = true;
                                adj[i][j] = adj[j][i] = false;
                                deg[i]--,deg[j]--;
                            }else{
                                use[j] = true;
                            }
                            break;
                        }
                    }
                }
            }
            if ( !found ) break;
            for(int i = 1 ; i <= n ; i++){
                if ( use[i] ){
                    used[i] = true;
                    for(int j = 1 ; j <= n ; j++){
                        if ( adj[i][j] ){
                            adj[i][j] = adj[j][i] = false;
                            deg[i]--,deg[j]--;
                        }
                    }
                }
            }
            
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            cnt += used[i];
        }
        printf("%d\n",cnt);
    }
    return 0;
}
