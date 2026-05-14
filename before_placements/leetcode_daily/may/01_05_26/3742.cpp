#include<bits/stdc++.h>
using namespace std;

pair<int,int> g(int grid_value){ //score,cost
    if(grid_value==0) return pair<int,int>{0,0};
    else if(grid_value==1) return pair<int,int>{1,1};
    return pair<int,int>{2,1}; 
}

int f(int i,int j,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int m,int n,int k){
    if(k<0) return -2;
    if(k==0 && grid[i][j]!=0) return -2;
    pair<int,int> sac=g(grid[i][j]);
    if(i==m-1 && j==n-1) return sac.first;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(i==m-1){
        int more_score=f(i,j+1,grid,dp,m,n,k-sac.second);
        if(more_score==-2) dp[i][j][k]=-2;
        else dp[i][j][k]=more_score+sac.first;
    }
    else if(j==n-1){
        int more_score=f(i+1,j,grid,dp,m,n,k-sac.second);
        if(more_score==-2) dp[i][j][k]=-2;
        else dp[i][j][k]=more_score+sac.first;
    }
    else{
        int more_score=max(f(i,j+1,grid,dp,m,n,k-sac.second),f(i+1,j,grid,dp,m,n,k-sac.second));
        if(more_score==-2) dp[i][j][k]=-2;
        else dp[i][j][k]=more_score+sac.first;
    }
    return dp[i][j][k];
}
 
int maxPathScore(vector<vector<int>>& grid, int k) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
    int ans=f(0,0,grid,dp,m,n,k);
    if(ans==-2) return -1;
    return ans;
}