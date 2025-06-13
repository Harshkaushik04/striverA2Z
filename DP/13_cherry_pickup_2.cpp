#include<bits/stdc++.h>
using namespace std;
//wrong
int cherryPickup(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<int> changes={-1,0,1};
    int temp;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(m,-1)));
    dp[0][n-1][0]=grid[0][0]+grid[0][n-1];
    for(int i=0;i<m-1;i++){
        for(int j=0;j<=i;j++){
            for(int k=n-1;k>=n-1-i;k--){
                for(int xchange1=0;xchange1<3;xchange1++){
                    for(int xchange2=0;xchange2<3;xchange2++){
                        if(j+changes[xchange1]>=0 && j+changes[xchange1]<n){
                            if(k+changes[xchange2]>=0 && k+changes[xchange2]<n){
                                if(dp[j+changes[xchange1]][k+changes[xchange2]][i+1]==-1){
                                    if(j+changes[xchange1]==k+changes[xchange2]) dp[j+changes[xchange1]][k+changes[xchange2]][i+1]=dp[j][k][i]+grid[j+changes[xchange1]][i];
                                    else dp[j+changes[xchange1]][k+changes[xchange2]][i+1]=dp[j][k][i]+grid[j+changes[xchange1]][i]+grid[k+changes[xchange2]][i];
                                }
                                else{
                                    if(j+changes[xchange1]==k+changes[xchange2]) dp[j+changes[xchange1]][k+changes[xchange2]][i+1]=max(dp[j+changes[xchange1]][k+changes[xchange2]][i+1],dp[j][k][i]+grid[j+changes[xchange1]][i]);
                                    else dp[j+changes[xchange1]][k+changes[xchange2]][i+1]=max(dp[j+changes[xchange1]][k+changes[xchange2]][i+1],dp[j][k][i]+grid[j+changes[xchange1]][i]+grid[k+changes[xchange2]][i]);
                                }
                            }
                            else continue;
                        }
                        else break;
                    }
                }
            }
        }
    }
    int maxi=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxi=max(maxi,dp[i][j][m-1]);
        }
    }
    return maxi;
}