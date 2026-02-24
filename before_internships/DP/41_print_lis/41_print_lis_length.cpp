#include<bits/stdc++.h>
using namespace std;

vector<int> getLIS(vector<int>& arr) {
    // Code here
    vector<pair<int,vector<int>>> dp;
    int n=arr.size();
    int totalMax=1,totalMaxIndex=0;
    int maxi=1,temp;
    for(int i=0;i<n;i++){
        vector<int> temp={arr[i]};
        dp.emplace_back(make_pair(1,temp));
    }
    for(int i=1;i<n;i++){
        maxi=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && maxi<dp[j].first+1){
                maxi=dp[j].first+1;
                temp=j;
            }
        }
        if(maxi>1){
            dp[i].second=dp[temp].second;
            dp[i].second.emplace_back(arr[i]);
            dp[i].first=maxi;
        }
        if(maxi>totalMax) {
            totalMax=maxi;
            totalMaxIndex=i;
        }
    }
    return dp[totalMaxIndex].second;
}