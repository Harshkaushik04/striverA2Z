#include<bits/stdc++.h>
using namespace std;

//no need of dijkstra, simple bfs would work because its like unit weight graph
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]!=0) return -1;
    int row=grid.size();
    int col=grid[0].size();
    vector<vector<int>> visited_arr(row,vector<int>(col,0));
    vector<vector<int>> distance_arr(row,vector<int>(col,INT32_MAX));
    distance_arr[0][0]=1;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited_arr[0][0]=1;
    while(!q.empty()){
        pair<int,int> current=q.front();
        q.pop();
        vector<int> rx={-1,0,1,1,1,0,-1,-1};
        vector<int> ry={1,1,1,0,-1,-1,-1,0};
        for(int j=0;j<8;j++){
            int x=current.first+rx[j];
            int y=current.second+ry[j];
            if(x>=0 && x<row && y>=0 && y<col){
                if(grid[x][y]==0 && visited_arr[x][y]==0){ //value of neighbor=0
                    visited_arr[x][y]=1;
                    distance_arr[x][y]=distance_arr[current.first][current.second]+1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }  
    if(distance_arr[row-1][col-1]==INT32_MAX) return -1;
    else return distance_arr[row-1][col-1];
}