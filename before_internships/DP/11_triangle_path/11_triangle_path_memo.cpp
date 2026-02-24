#include<bits/stdc++.h>
using namespace std;
//TLE
int minimumTotal(vector<vector<int>>& triangle) {
    int iMax=triangle.size();
    vector<vector<int>> dp;
    for(int i=0;i<iMax;i++){
        vector<int> temp(i+1,-1);
        dp.emplace_back(temp);
    }
    int mini=INT32_MAX;
    for(int index=0;index<iMax;index++){
        int temp=f(index,iMax-1,triangle,dp);
        mini=min(mini,temp);
    }
    return mini;
}

int f(int index,int i,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    if(index==0 && i==0) return triangle[i][index];
    int temp1=INT32_MAX,temp2=INT32_MAX;
    if(index<i){
        if(dp[i-1][index]==-1){
            temp1=triangle[i][index]+f(index,i-1,triangle,dp);
        }
        else{
            temp1=triangle[i][index]+dp[i][index-1];
        }
    }
    if(index>0){
        if(dp[i-1][index-1]==-1){
            temp2=triangle[i][index]+f(index-1,i-1,triangle,dp);
        }
        else{
            temp2=triangle[i][index]+dp[i-1][index-1];
        }
    }
    return min(temp1,temp2);
}