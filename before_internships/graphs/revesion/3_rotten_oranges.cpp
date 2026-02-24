#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int totalOrangesNum=0;
    int ans=0;
    int m=grid.size(),n=grid[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push(make_pair(i,j));
                ans++;
                totalOrangesNum++;
            }
            else if(grid[i][j]==1) totalOrangesNum++;
        }
    }
    int sourceNum=q.size();
    if(sourceNum==0){
        if(totalOrangesNum==0) return 0;
        else return -1;
    }
    vector<int> deltaX={-1,0,1,0};
    vector<int> deltaY={0,1,0,-1};
    int maxi=0;
    int actual_ans=0;
    while(!q.empty()){
        int qSize=q.size();
        for(int l=0;l<qSize;l++){
            pair<int,int> current=q.front();
            q.pop();
            for(int j=0;j<4;j++){
                if(current.first+deltaX[j]>=0 && current.first+deltaX[j]<m && current.second+deltaY[j]>=0 && current.second+deltaY[j]<n){
                    if(grid[current.first+deltaX[j]][current.second+deltaY[j]]==1){
                        grid[current.first+deltaX[j]][current.second+deltaY[j]]=2;
                        q.push(make_pair(current.first+deltaX[j],current.second+deltaY[j]));
                        ans++;
                    }
                }
            }
        }
        actual_ans++;
    }
    if(actual_ans>maxi) maxi=actual_ans;
    if(ans!=totalOrangesNum) return -1;
    return maxi-1;
}