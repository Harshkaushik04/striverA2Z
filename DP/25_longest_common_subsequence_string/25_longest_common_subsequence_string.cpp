#include<bits/stdc++.h>
using namespace std;

int f(int index1,int index2,string& s1,string& s2,vector<vector<int>>& dp){
    if(index1==0 && index2==0){
        if(s1[index1]==s2[index2]){
            dp[0][0]=1;
            return dp[0][0];
        }
        else{
            dp[0][0]=0;
            return dp[0][0];
        }
    }
    else if(index1==0){
        for(int i=0;i<=index2;i++){
            if(s1[0]==s2[i]){
                dp[0][index2]=1;
                return dp[0][index2];
            }
        }
        dp[0][index2]=0;
        return dp[0][index2];
    }
    else if(index2==0){
        for(int i=0;i<=index1;i++){
            if(s1[i]==s2[0]){
                dp[index1][0]=1;
                return dp[index1][0];
            }
        }
        dp[index1][0]=0;
        return dp[index1][0];
    }
    if(dp[index1][index2]!=-1) return dp[index1][index2];
    if(s1[index1]==s2[index2]) {
        dp[index1][index2]=1+f(index1-1,index2-1,s1,s2,dp);
        return dp[index1][index2];
    }
    else{
        dp[index1][index2]=max(f(index1-1,index2,s1,s2,dp),f(index1,index2-1,s1,s2,dp));
        return dp[index1][index2];
    }
    return dp[index1][index2];
}

int longestCommonSubsequence(string text1, string text2) {
    int size1=text1.size();
    int size2=text2.size();
    vector<vector<int>> dp(size1,vector<int>(size2,-1));
    return f(size1-1,size2-1,text1,text2,dp);
}