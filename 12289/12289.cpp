//==============================================================
// Coded by: Huynh Nhat Minh
// Problem Number: 12289 - One-Two-Three
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
#define INF 99999999

using namespace std;

int main()
{
    //freopen("12289.INP","r",stdin);
    //freopen("12289.OUT","w",stdout);
    int n;
    scanf(" %d ",&n);
    for(int i=0;i<n;i++)
    {
        char word[10];
        scanf(" %s ",&word);
        if(strlen(word)==5) printf("3\n");
        else if((word[0]=='o' && word[1]=='n') || (word[0]=='o' && word[2]=='e') || (word[1]=='n' && word[2]=='e')) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
