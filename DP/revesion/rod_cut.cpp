#include<bits/stdc++.h>
using namespace std;

int f(int length,vector<int>& dp,vector<int>& arr){
    if(length==0) return 0;
    if(length<0) return INT32_MIN;
    if(dp[length]!=-1) return dp[length];
    for(int i=-1;i<length-1;i++){
        int change=f(length-i-2,dp,arr)+arr[i+1];
        if(change!=INT32_MIN) dp[length]=max(dp[length],change);
    }
    return dp[length];
}

int cutRod(vector<int> &price){
    int n=price.size();
    vector<int> dp(n+1,-1);
    return f(n,dp,price);
}