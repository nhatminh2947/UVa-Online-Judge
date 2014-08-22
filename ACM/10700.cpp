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
vector<long long> val;
void trait(char *str){
    val.clear();
    int len = strlen(str);
    for(int i = 0 ; i < len ; i++){
        if ( str[i] >= '0' && str[i] <= '9' ){
            int j = i, num = 0;
            while(j<len && str[j] >= '0' && str[j] <= '9'){
                num = num * 10 + str[j] - '0';
                j++;
            }
            val.push_back(num);
            i = --j;
        }else if ( str[i] == '*' ) {
            val.push_back(-1);
        }else{
            val.push_back(-2);
        }
    }
}
long long findMax(){
    vector<long long> tmp;
    for(int i = 0 ; i < val.size(); i++){
        if ( val[i] == -1 ){
            continue;
        }else if ( val[i] == -2 ){
            tmp.back() = tmp.back() + val[++i];
        }else{
            tmp.push_back(val[i]);
        }
    }
    long long product = 1;
    for(int i = 0 ; i < tmp.size() ; i++){
        product *= tmp[i];
    }
    return product;
}
long long findMin(){
    vector<long long> tmp;
    for(int i = 0 ; i < val.size(); i++){
        if ( val[i] == -2 ){
            continue;
        }else if ( val[i] == -1 ){
            tmp.back() = tmp.back() * val[++i];
        }else{
            tmp.push_back(val[i]);
        }
    }
    long long sum = 0;
    for(int i = 0 ; i < tmp.size() ; i++){
        sum += tmp[i];
    }
    return sum;
}
int main()
{
    int T; scanf("%d",&T); getchar();
    char line[1000];
    while(T--){
        gets(line);
        trait(line);
        printf("The maximum and minimum are %lld and %lld.\n",findMax(),findMin());
    }
    return 0;
}
