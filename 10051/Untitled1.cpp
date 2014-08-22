//Code:
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <sstream>
#define memset(arr,value) memset(arr,value,sizeof(arr))
#define INF 2000000000
#define MAX 100000;
const double pi = acos(-1.0);
using namespace std;
int n,k,m,Case,Max,Min,x,Sum,M=0,len;
string str,st,s;
int Cubes[1000][1000];
int F[1000][1000],isHave[1000][1000],Pos[1000][1000];
string face[]={"","front","back","left","right","top","bottom"};

int main(){
    freopen("10051.INP","r",stdin);
    freopen("10051.OUT","w",stdout);
    Case=1;
    while (cin>>n){
          if (n==0) break;
          if (Case>1)
             cout<<endl;  
          cout<<"Case #"<<Case++<<endl;
          
          for (int i=1;i<=n;i++)
              for (int j=1;j<=6;j++)
                  cin>>Cubes[i][j];
          //Init       
          for (int i=0;i<=n+1;i++)
              for (int j=0;j<=100;j++){
                  F[i][j]=0;
                  isHave[i][j]=0;
                  Pos[i][j]=0;
              }
          //DP             
          for (int i=n;i>=1;i--)
              for (int j=1;j<=100;j++){
                  F[i][j]=F[i+1][j];
                  for (int k=1;k<=6;k++)
                      if (Cubes[i][k]==j && F[i+1][Cubes[i][k%2?k+1:k-1]]+1>F[i][j]){
                         F[i][j]=F[i+1][Cubes[i][k%2?k+1:k-1]]+1;
                         isHave[i][j]=1;
                         Pos[i][j]=k;
                      }
              }
          int ans = 0, c, f;
          for (int i = 1; i <= 100; i++)
            if (F[1][i] > ans)
                ans = F[1][i], c = i;
          cout<<ans<<endl;
          //Trace
         for (int i=1;i<=n;i++){
             if (isHave[i][c]){
                cout<<i<<" "<<face[Pos[i][c]]<<endl;
                c=Cubes[i][Pos[i][c]%2?Pos[i][c]+1:Pos[i][c]-1];
             }
         }

    }
return 0;
}
