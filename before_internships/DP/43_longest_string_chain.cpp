#include<bits/stdc++.h>
using namespace std;

static bool cmp(string s1,string s2){
    if(s1.size()<s2.size()) return true;
    return false;
}

bool condition_strings(string s1,string s2){ //s1 is smaller one and s2 is bigger by 1
    int size1=s1.size();
    int size2=s2.size();
    // if(size1+1!=size2) return false; //already checked=>no need
    int diff=0;
    for(int i=0;i<size1;i++){
        if(s1[i]==s2[i+diff]) continue;
        else{
            if(diff==0 && s2[i+1]==s1[i]){
                diff++;
            }
            else return false;
        }
    }
    return true;
}

int longestStrChain(vector<string>& nums) {
    sort(nums.begin(),nums.end(),cmp);
    int n=nums.size();
    vector<int> dp(n,1); 
    int totalMax=1;
    int maxi=1;
    for(int i=1;i<n;i++){
        maxi=1;
        for(int j=0;j<i;j++){
            if(nums[i].size()==nums[j].size()+1){
                if(condition_strings(nums[j],nums[i]) && maxi<dp[j]+1){
                    maxi=dp[j]+1;
                }
            }
        }
        if(maxi>1){
            dp[i]=maxi;
        }
        if(totalMax<maxi){
            totalMax=maxi;
        }
    }       
    return totalMax;
}