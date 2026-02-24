#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0]==1) return 0;
    int m=obstacleGrid.size(),n=obstacleGrid[0].size();
    vector<int> current(n,-1);
    vector<int> next(n,-1);
    current[0]=1;
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            if(x+1<n){
                if(obstacleGrid[y][x+1]==0){
                    if(current[x+1]!=-1) current[x+1]+=current[x];
                    else current[x+1]=current[x];
                }
                else current[x+1]=0;
            }
            if(y+1<m){
                if(obstacleGrid[y+1][x]==0){
                    next[x]=current[x];
                }
                else next[x]=0;
            }
        }
        if(y!=m-1) current=next;
    }
    return current[n-1];
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int ans=uniquePathsWithObstacles(arr);
    return 0;
}