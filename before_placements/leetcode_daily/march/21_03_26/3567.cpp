#include<bits/stdc++.h>
using namespace std;

void calculateInSubSubMatrix(int i,int j,int i1,int j1,int& ans,int curr,vector<vector<int>>& grid,int k){
    for(int x=j1+1;x<j+k;x++){
        if(abs(curr-grid[i1][x])!=0) ans=min(ans,abs(curr-grid[i1][x]));
    }
    for(int y=i1+1;y<i+k;y++){
        for(int x=j;x<j+k;x++){
            if(abs(curr-grid[y][x])!=0) ans=min(ans,abs(curr-grid[y][x]));
        }
    }
}

int calculateAnsInSubMatrix(vector<vector<int>>& grid,int i,int j,int k){ //assuming i+k<n and j+k<m
    int n=grid.size();
    int m=grid[0].size();
    int ans=INT32_MAX;
    for(int y=i;y<i+k;y++){
        for(int x=j;x<j+k;x++){
            int curr=grid[y][x];
            calculateInSubSubMatrix(i,j,y,x,ans,curr,grid,k);
        }
    }
    return ans;
}

vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vec(k,vector<int>(k,0));
    vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,0));        
    for(int i=0;i<n-k+1;i++){
        for(int j=0;j<m-k+1;j++){
            ans[i][j]=calculateAnsInSubMatrix(grid,i,j,k);
            if(ans[i][j]==INT32_MAX) ans[i][j]=0;
        }
    }
    return ans;
}