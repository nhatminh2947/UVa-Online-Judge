//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 10298 - Power Strings
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
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
#define maxN 123456
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

string s;

int main()
{
    //freopen("10298.INP","r",stdin);
    //freopen("10298.OUT","w",stdout);
    while(cin>>s && s!=".")
    {
        int sz=s.size();
        string tmp="";
        int cnt=1;
        int lm=sz/2;
        for(int i=0;i<lm;i++)
        {
            tmp+=s[i];
            if(sz%(i+1)==0 && s[i+1]==tmp[0])
            {
                int j;
                string k="";
                bool lock=false;
                for(j=i+1;j<sz;j++)
                {
                    k+=s[j];
                    if(k.size()==tmp.size())
                    {
                        if(k==tmp)
                        {
                            cnt++;
                            k.clear();
                        }
                        else
                        {
                            cnt=1;
                            lock=true;
                            break;
                        }
                    }
                }
                if(!lock && j==sz) break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
