#include<bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(int n, vector<int> &nums) {
    // code here
    pair<int,int> p=make_pair(1,0); // first one for increase count 2nd for decrease
    vector<pair<int,int>> dp(n,p); //increase length,decrease length
    int totalMax=1,maxi1,maxi2;
    int temp;
    for(int i=1;i<n;i++){
        maxi1=1,maxi2=0;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                if(dp[j].first+1>maxi1) maxi1=max(1+dp[j].first,maxi1);
            } 
            else if(nums[j]>nums[i]) {
                if(dp[j].first>1) maxi2=max(1+dp[j].first,maxi2);
                if(dp[j].second>1) maxi2=max(maxi2,1+dp[j].second);
            }
        }
        dp[i].first=maxi1;
        dp[i].second=maxi2;
        if(maxi2>totalMax) totalMax=maxi2;
    }
    if(totalMax==1) return 0;
    return totalMax;
}