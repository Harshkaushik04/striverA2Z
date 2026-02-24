#include<bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.emplace_back(n);
    int r=cuts.size();
    vector<vector<int>> dp(r,vector<int>(r,-1));
    int mini=INT32_MAX;
    for(int i=r-2;i>=0;i--){
        for(int j=i+1;j<r;j++){
            mini=INT32_MAX;
            for(int k=i+1;k<j;k++){
                mini=min(mini,cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
            }
            if(mini!=INT32_MAX) dp[i][j]=mini;
            else dp[i][j]=0;
        }
    }
    return dp[0][r-1];
}
