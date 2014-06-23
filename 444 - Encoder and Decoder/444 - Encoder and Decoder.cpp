//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 444 - Encoder and Decoder
// Verdict: Accpeted
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
#define int64 long long
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define read2(x,y) scanf(" %d %d ",&x,&y)
#define read3(x,y,z) scanf(" %d %d %d ",&x,&y,&z)
#define out(x) printf("%d",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

string inp,ans;

int main()
{
    freopen("444 - Encoder and Decoder.INP","r",stdin);
    freopen("444 - Encoder and Decoder.OUT","w",stdout);

    while(getline(cin,inp))
    {
        ans.clear();
        int sz = inp.size();
        bool en = true;
        for(int i = 0 ; i < sz && en; i++)
            if('0' <= inp[i] && inp[i] <= '9')
                en = false;
                        
        if(en)
        {
            for(int i = 0 ; i < sz ; i++)
            {
                string tmp;
                int k = inp[i];
                //DEBUG(k);
                while(k)
                {
                    tmp = (char)(k%10 + '0') + tmp;
                    k /= 10;
                    //DEBUG(ans);
                }
                ans += tmp;
                //DEBUG(ans);
            }
            
            reverse(ans.begin(),ans.end());
        }
        else
        {
            int k = 0;
            for(int i = sz-1 ; i >= 0 ; i--)
            {
                k = k*10 + (inp[i] - '0');
                if(k > 12)
                {
                    //DEBUG(k);
                    ans += (char)k;
                    k = 0;
                    //DEBUG(ans);
                }
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}