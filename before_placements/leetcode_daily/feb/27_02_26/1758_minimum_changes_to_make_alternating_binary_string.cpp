#include<bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    int len=s.size();
    int ans=INT32_MAX;
    int temp=0;
    for(int i=0;i<len;i++){
        if(i%2==0 && s[i]=='0'){
            temp++;
        }
        else if(i%2==1 && s[i]=='1'){
            temp++;
        }
    }        
    ans=min(ans,temp);
    temp=0;
    for(int i=0;i<len;i++){
        if(i%2==0 && s[i]=='1'){
            temp++;
        }
        else if(i%2==1 && s[i]=='0'){
            temp++;
        }
    }      
    ans=min(ans,temp);
    return ans;
}