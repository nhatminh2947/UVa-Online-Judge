//==============================================================
// Name: Huynh Nhat Minh
// Problem Number: 450-Litle Black Book
//==============================================================

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

using namespace std;

typedef struct
{
    string tt;
    string fn;
    string ln;
    string st;
    string dpm;
    string hp;
    string wp;
    string cb;
} blackbook;

blackbook faculty[30000];

bool cmp(blackbook a,blackbook b)
{
    return a.ln<b.ln;
}

int main()
{
    freopen("450.INP","r",stdin);
    freopen("450.OUT","w",stdout);
    string tempdpm,tempin;
    int num=0,n,found;
    scanf("%d ",&n);
    for(int i=0;i<n;i++)
    {
        getline(cin,tempdpm);
        while(getline(cin,tempin))
        {    
            if(tempin=="") break;
            faculty[num].dpm.append(tempdpm);
            found=tempin.find(",");
            faculty[num].tt.append(tempin,0,(int)found);  
            tempin.erase(0,(int)found+1);
            found=tempin.find(",");
            faculty[num].fn.append(tempin,0,(int)found);  
            tempin.erase(0,(int)found+1);
            found=tempin.find(",");
            faculty[num].ln.append(tempin,0,(int)found);  
            tempin.erase(0,(int)found+1);
            found=tempin.find(",");
            faculty[num].st.append(tempin,0,(int)found);  
            tempin.erase(0,(int)found+1);
            found=tempin.find(",");
            faculty[num].hp.append(tempin,0,(int)found);  
            tempin.erase(0,(int)found+1);
            found=tempin.find(",");
            faculty[num].wp.append(tempin,0,(int)found);  
            tempin.erase(0,(int)found+1);
            found=tempin.find(",");
            faculty[num].cb.append(tempin,0,(int)found);  
            tempin.erase(0,(int)found+1);
            num++;
        }
    }
    sort(faculty,faculty+num,cmp);
    for (int i = 0; i < num; i++) 
    {
        cout << "----------------------------------------" << endl;
        cout << faculty[i].tt << " " << faculty[i].fn << " " << faculty[i].ln << endl;
        cout << faculty[i].st << endl;
        cout << "Department: " << faculty[i].dpm << endl;
        cout << "Home Phone: " << faculty[i].hp << endl;
        cout << "Work Phone: " << faculty[i].wp << endl;
        cout << "Campus Box: " << faculty[i].cb << endl;
    }
    return 0;
}
