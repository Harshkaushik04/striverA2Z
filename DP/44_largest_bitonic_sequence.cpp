#include<bits/stdc++.h>
using namespace std;
//not done
int LongestBitonicSequence(int n, vector<int> &nums) {
    // code here
    int n=nums.size();
    pair<int,int> p=make_pair(1,0); // first one for increase count 2nd for decrease
    vector<pair<int,int>> dp(n,p); //increase length,decrease length
    int totalMax=1,maxi;
    char temp;
    for(int i=1;i<n;i++){
        maxi=1;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i] && dp[j].second='i'){
                if(dp[j]+dp[i]>maxi) maxi=1+dp[j];
                temp='i';
            } 
            else if(nums[j]<nums[i] && dp[j].second='d') continue;
            else if(nums[j]>nums[i] && dp[j].second='i') continue;
            else if(nums[j]>nums[i] && dp[j].second='d'){
                if(dp[j]+dp[i]>maxi) maxi=1+dp[j];
                temp='i';
            }
        }
        dp[i]=maxi;
        if(dp[i]>totalMax) totalMax=dp[i];
    }
    return totalMax;
}