#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

typedef struct
{
    string A[10];
} thongtin;

bool CMP(thongtin a,thongtin b)
{
    return a.A[3]<b.A[3];
}


int main()
{
    freopen("450.INP","r",stdin);
    freopen("450.OUT","w",stdout);
    
    int n;
    thongtin Ob[10000];
    int per=0;
    scanf("%d%*c",&n);
    
    string depart="";
    while(n--)
    {
        getline(cin,depart);
        string temp="";
        while(getline(cin,temp) && temp.size()>0)
        {
            Ob[per].A[0]=depart;
            
            int i=0;
            int count=1;
            Ob[per].A[1]="";
            while (i<temp.size())
            {
                if (temp[i]==',') 
                {
                    count++;
                    Ob[per].A[count]="";
                    i++;
                    continue;
                }
                Ob[per].A[count]+=temp[i];
                i++;
            }
            per++;
            temp="";
        }
        
    
    }
    sort(Ob,Ob+per,CMP);
    for (int i=0;i<per;i++) 
    {
        cout<<"----------------------------------------"<<endl;
        cout<<Ob[i].A[1]<<" "<<Ob[i].A[2]<<" "<<Ob[i].A[3]<<endl;
        cout<<Ob[i].A[4]<<endl;
        cout<<"Department: "<<Ob[i].A[0]<<endl;
        cout<<"Home Phone: "<<Ob[i].A[5]<<endl;
        cout<<"Work Phone: "<<Ob[i].A[6]<<endl;
        cout<<"Campus Box: "<<Ob[i].A[7]<<endl;
    }
    
    
    
    return 0;
}
