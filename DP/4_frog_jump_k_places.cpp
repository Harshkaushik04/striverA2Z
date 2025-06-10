#include<bits/stdc++.h>
using namespace std;
//0 based indexing
int frogJump(vector<int>& heights, int k) {
    int n=heights.size();
    if(n==1) return 0;
    if(n==2) return abs(heights[1]-heights[0]);
    int temp;
    vector<int> dp(n,INT32_MAX);
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    for(int i=1;i<n;i++){
        for(int j=1;j<=min(k,i);j++){
            dp[i]=min(dp[i],dp[i-j]+abs(heights[i]-heights[i-j]));
        }
    }
    return dp[n-1];
}