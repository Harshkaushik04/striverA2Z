#include<bits/stdc++.h>
using namespace std;

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0);
    vector<int> curr(m,0);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) curr[j]=grid[i][j];
            else if(i==0) curr[j]=grid[i][j]+curr[j-1];
            else if(j==0) curr[j]=grid[i][j]+prev[j];
            else curr[j]=grid[i][j]+prev[j]+curr[j-1]-prev[j-1];
            if(curr[j]<=k) {
                ans++;
            }
        }
        prev=curr;
    }        
    return ans;
}