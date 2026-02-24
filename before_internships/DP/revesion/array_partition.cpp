#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& arr){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++) sum+=arr[i];
    if(sum%2==1) return false;
    vector<int> prev(sum/2+1,-1);
    int take,not_take;
    for(int j=1;j<=sum/2;j++) prev[j]=0;
    vector<int> dp(sum/2+1,-1);
    for(int i=n-2;i>=0;i--){
        dp[0]=1;
        for(int j=0;j<=sum/2;j++){
            take=0;
            if(j>=arr[i]) take=prev[j-arr[i]];
            not_take=prev[j];
            dp[j]=take||not_take;
        }
        prev=dp;
    }
    return dp[sum/2];
}