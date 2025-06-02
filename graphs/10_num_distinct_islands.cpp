#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> findNeighbors(vector<vector<int>>* gridP,pair<int,int> node){
    vector<pair<int,int>> ans;
    int rowNum=(*gridP).size();
    int colNum=(*gridP)[0].size();
    int row=node.first,col=node.second;
    if(row-1>=0) ans.emplace_back(make_pair(row-1,col));
    if(row+1<rowNum) ans.emplace_back(make_pair(row+1,col));
    if(col-1>=0) ans.emplace_back(make_pair(row,col-1));
    if(col+1<colNum) ans.emplace_back(make_pair(row,col+1));
    return ans;
}

vector<pair<int,int>> bfsTraversal(pair<int,int> starting_pair,int rowNum,int colNum,vector<vector<int>>* grid,
    vector<vector<int>>* vis,set<vector<pair<int,int>>>* traversalsP){
    queue<pair<int,int>> q;
    pair<int,int> current;
    vector<pair<int,int>> neighbors;
    int neighborsSize;
    (*vis)[starting_pair.first][starting_pair.second]=1;
    q.push(starting_pair);
    vector<pair<int,int>> thisTraversal;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            thisTraversal.emplace_back(make_pair(current.first-starting_pair.first,current.second-starting_pair.second));
            neighbors=findNeighbors(grid,current);
            neighborsSize=neighbors.size();
            for(int j=0;j<neighborsSize;j++){
                if((*vis)[neighbors[j].first][neighbors[j].second]==0 && (*grid)[neighbors[j].first][neighbors[j].second]==1){
                    (*vis)[neighbors[j].first][neighbors[j].second]=1;
                    q.push(neighbors[j]);
                }
            }
        }
    }
    (*traversalsP).insert(thisTraversal);
    return thisTraversal;
}

int num_distinct_islands(vector<vector<int>>& grid){
    int rowNum=grid.size();
    int colNum=grid[0].size();
    vector<vector<int>> vis(rowNum,vector<int>(colNum,0));
    set<vector<pair<int,int>>> traversals;
    int ans=0;
    for(int i=0;i<rowNum;i++){
        for(int j=0;j<colNum;j++){
            if(vis[i][j]==0 && grid[i][j]==1){
                pair<int,int> p={i,j};
                vector<pair<int,int>> thisTraversal=bfsTraversal(p,rowNum,colNum,&grid,&vis,&traversals);
                int traversalsSize=traversals.size();
                bool flag=false;
                traversals.insert(thisTraversal);
            }
        }
    }
    ans=traversals.size();
    return ans;
}

int main(){
    return 0;
}