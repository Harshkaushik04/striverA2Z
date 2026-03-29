#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n=strs.size();
    if(n==1) return strs[0];
    int minLen=INT32_MAX;
    for(int i=0;i<n;i++) minLen=min(minLen,(int)strs[i].size());
    int i=0;
    string ans="";
    while(i<minLen){
        for(int j=0;j<n-1;j++){
            if(strs[j][i]!=strs[j+1][i]) return ans;
        }
        ans+=strs[0][i];
        i++;
    }
    return ans;
}

int main(){
    return 0;
}