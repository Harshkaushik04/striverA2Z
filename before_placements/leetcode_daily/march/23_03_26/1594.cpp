#include<bits/stdc++.h>
using namespace std;

long long f(int i,int j,int whether_positive,vector<vector<int>>& grid,vector<vector<vector<long long>>>& dp,int m,int n){
    if(i==m-1 && j==n-1){
        if(whether_positive){
            if(grid[i][j]<0) dp[i][j][whether_positive]=-1;
            else dp[i][j][whether_positive]=grid[i][j];
        }
        else{
            if(grid[i][j]<0) dp[i][j][whether_positive]=grid[i][j];
            else dp[i][j][whether_positive]=1;
        }
        return dp[i][j][whether_positive];
    }
    if(i==m || j==n){
        if(whether_positive) return -1;
        else return 1;
    }
    if(dp[i][j][whether_positive]!=LONG_LONG_MAX) return dp[i][j][whether_positive];
    long long right_one=1;
    long long down_one=1;
    if(whether_positive){
        if(grid[i][j]<0){
            right_one=f(i,j+1,false,grid,dp,m,n);
            down_one=f(i+1,j,false,grid,dp,m,n);
        }
        else{
            right_one=f(i,j+1,true,grid,dp,m,n);
            down_one=f(i+1,j,true,grid,dp,m,n);
        }
        long long maxi=max((long long)grid[i][j]*right_one,(long long)grid[i][j]*down_one);
        if(maxi<0) dp[i][j][whether_positive]=-1;
        else dp[i][j][whether_positive]=maxi;
    }
    else{
        if(grid[i][j]<0){
            right_one=f(i,j+1,true,grid,dp,m,n);
            down_one=f(i+1,j,true,grid,dp,m,n);
        }
        else{
            right_one=f(i,j+1,false,grid,dp,m,n);
            down_one=f(i+1,j,false,grid,dp,m,n);
        }
        long long mini=min((long long)grid[i][j]*right_one,(long long)grid[i][j]*down_one);
        if(mini>=0) dp[i][j][whether_positive]=1;
        else dp[i][j][whether_positive]=mini;
    }
    return dp[i][j][whether_positive];
}

int maxProductPath(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int MOD=1e9+7;
    vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(2,LONG_LONG_MAX)));
    long long ans=f(0,0,true,grid,dp,m,n);
    if(ans<0){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) return 0;
            }
        }
        return -1;
    }
    ans%=MOD;
    return ans;
};