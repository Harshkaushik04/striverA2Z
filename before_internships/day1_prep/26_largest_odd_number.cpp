#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int m=num.size();
    int target=-1;
    for(int i=m-1;i>=0;i--){
        int n=num[i]-'0';
        if(n%2==1){
            target=i;
            break;
        }
    }
    if(target==-1) return "";
    string ans=num.substr(0,target+1);
    return ans;
}