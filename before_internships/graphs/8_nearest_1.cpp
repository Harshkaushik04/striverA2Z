#include<bits/stdc++.h>
using namespace std;
//nearest 1 from each cell
vector<vector<int>> nearest(vector<vector<int>> grid){
    int rowNum=grid.size();
    int colNum=grid[0].size();
    vector<vector<int>> visited_grid(rowNum,vector<int>(colNum,0));
    vector<vector<int>> ans(rowNum,vector<int>(colNum,INT32_MAX));
    vector<pair<int,int>> one_arr;
    for(int i=0;i<rowNum;i++){
        for(int j=0;j<colNum;j++){
            if(grid[i][j]==1){
                one_arr.emplace_back(make_pair(i,j));
            }
        }
    }
    queue<pair<pair<int,int>,int>> q; //co ordinate at grid,steps away from 1
    pair<pair<int,int>,int> current;
    //this is not bfs
    for(pair<int,int>p:one_arr){
        q.push(make_pair(p,0));
        visited_grid[p.first][p.second]=1;
        ans[p.first][p.second]=0;
    }
    while(!q.empty()){
        int qSize=q.size();
        current=q.front();
        q.pop();
        vector<pair<int,int>> neighbors=findNeighbors(current.first,&grid);
        int neighborsSize=neighbors.size();
        for(int i=0;i<neighborsSize;i++){
            if(visited_grid[neighbors[i].first][neighbors[i].second]==0){
                q.push(make_pair(neighbors[i],current.second+1));
                ans[neighbors[i].first][neighbors[i].second]=current.second+1;
                visited_grid[neighbors[i].first][neighbors[i].second]=1;
            }
        }
    }
    return ans;
}


vector<pair<int,int>> findNeighbors(pair<int,int> current,vector<vector<int>>* mat){
    int first=current.first;
    int second=current.second;
    int firstLimit=(*mat).size();
    int secondLimit=(*mat)[0].size();
    vector<pair<int,int>> ans;
    pair<int,int> temp;
    if(second-1>=0){
        ans.emplace_back(make_pair(first,second-1));
    }
    if(second+1<secondLimit){
        ans.emplace_back(make_pair(first,second+1));
    }
    if(first-1>=0){
        ans.emplace_back(make_pair(first-1,second));
    }
    if(first+1<firstLimit){
        ans.emplace_back(make_pair(first+1,second));
    }
    return ans;
}

int main(){
    return 0;
}