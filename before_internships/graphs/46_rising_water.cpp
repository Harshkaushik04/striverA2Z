#include<bits/stdc++.h>
using namespace std;

int findUp(int i,vector<int>& parent){
    if(i==parent[i]) return i;
    int up=findUp(parent[i],parent);
    parent[i]=up;
    return up;
}

int swimInWater(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> sorted_values;
    vector<int> x_change={-1,0,1,0};
    vector<int> y_change={0,1,0,-1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sorted_values.emplace_back(vector<int>{grid[i][j],i,j});
        }
    }
    sort(sorted_values.begin(),sorted_values.end());
    vector<int> parent(m*n,-1);
    for(int i=0;i<m*n;i++) parent[i]=i;
    vector<int> rank_arr(m*n,0);
    int top_left=grid[0][0];
    int bottom_right=grid[m-1][n-1];
    vector<int> visited_arr(m*n,-1);
    for(vector<int>& value:sorted_values){
        int actual_value=value[0];
        int i=value[1];
        int j=value[2];
        visited_arr[actual_value]=1;
        int up1=findUp(actual_value,parent);
        for(int k=0;k<4;k++){
            int x1=i+x_change[k];
            int y1=j+y_change[k];
            if(x1<m && x1>=0 && y1<n && y1>=0 && visited_arr[grid[x1][y1]]==1){
                int up2=findUp(grid[x1][y1],parent);
                if(up1==up2) continue;
                if(up1!=up2){
                    if(rank_arr[up1]>rank_arr[up2]){
                        parent[up2]=up1;
                    }
                    else if(rank_arr[up1]<rank_arr[up2]){
                        parent[up1]=up2;
                    }
                    else{
                        parent[up2]=up1;
                        rank_arr[up1]+=rank_arr[up2];
                    }
                }
            }
        }
        if(findUp(top_left,parent)==findUp(bottom_right,parent)) return actual_value;
    }
    return -1;
}