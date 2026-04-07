#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,int ability,vector<vector<int>>& coins,vector<vector<vector<int>>>& dp,int m,int n){
    if(i==m-1 && j==n-1){
        if(coins[i][j]<0 && ability>0) return 0;
        else return coins[i][j];
    }
    if(dp[i][j][ability]!=INT32_MIN) return dp[i][j][ability];
    if(i==m-1){
        int ability_not_use=coins[i][j]+f(i,j+1,ability,coins,dp,m,n);
        if(coins[i][j]<0){
            if(ability>0){
                int ability_use=f(i,j+1,ability-1,coins,dp,m,n);
                dp[i][j][ability]=max(ability_use,ability_not_use);
            }
            else dp[i][j][ability]=ability_not_use;
        }
        else dp[i][j][ability]=ability_not_use;
    }
    else if(j==n-1){
        int ability_not_use=coins[i][j]+f(i+1,j,ability,coins,dp,m,n);
        if(coins[i][j]<0){
            if(ability>0){
                int ability_use=f(i+1,j,ability-1,coins,dp,m,n);
                dp[i][j][ability]=max(ability_use,ability_not_use);
            }
            else dp[i][j][ability]=ability_not_use;
        }
        else dp[i][j][ability]=ability_not_use;
    }
    else{
        int ability_not_use_down=coins[i][j]+f(i+1,j,ability,coins,dp,m,n);
        int ability_not_use_right=coins[i][j]+f(i,j+1,ability,coins,dp,m,n);
        int ability_not_use=max(ability_not_use_down,ability_not_use_right);
        if(coins[i][j]<0){
            if(ability>0){
                int ability_use_down=f(i+1,j,ability-1,coins,dp,m,n);
                int ability_use_right=f(i,j+1,ability-1,coins,dp,m,n);
                int ability_use=max(ability_use_down,ability_use_right);
                dp[i][j][ability]=max(ability_not_use,ability_use);
            }
            else dp[i][j][ability]=ability_not_use;
        }
        else dp[i][j][ability]=ability_not_use;
    }
    return dp[i][j][ability];
}

int maximumAmount(vector<vector<int>>& coins) {
    int m=coins.size();
    int n=coins[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT32_MIN)));
    return f(0,0,2,coins,dp,m,n);
}