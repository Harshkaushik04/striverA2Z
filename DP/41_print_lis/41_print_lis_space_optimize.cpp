#include<bits/stdc++.h>
using namespace std;

vector<int> getLIS(vector<int>& arr) {
    // Code here
    vector<pair<int,int>> dp;
    int n=arr.size();
    int totalMax=1,totalMaxIndex=0;
    int maxi=1,temp;
    for(int i=0;i<n;i++){
        dp.emplace_back(make_pair(1,-1)); //length,backtrackingIndex
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
            dp[i].second=temp;
            dp[i].first=maxi;
        }
        if(maxi>totalMax) {
            totalMax=maxi;
            totalMaxIndex=i;
        }
    }
    vector<int> ans;
    temp=totalMaxIndex;
    while(dp[temp].second!=-1){
        ans.emplace_back(arr[temp]);
        temp=dp[temp].second;
    }
    ans.emplace_back(arr[temp]);
    reverse(ans.begin(),ans.end());
    return ans;
}