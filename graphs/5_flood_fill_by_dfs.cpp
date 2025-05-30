#include<bits/stdc++.h>
using namespace std;

//can be implemented both by bfs/dfs
vector<vector<int>> floodFill(vector<vector<int>> mat,pair<int,int> start,int change){
    int rowNum=mat.size();
    int colNum=mat[0].size();
    vector<vector<int>> vis(rowNum,vector<int>(colNum,0));
    int initialColor=mat[start.first][start.second];
    if(change==initialColor) return mat;
    if(vis[start.first][start.second]==0){
        dfsTraversal(start,rowNum,colNum,&mat,&vis,initialColor,change);
    }
    return mat;
}

void dfsTraversal(pair<int,int> starting_pair,int rowNum,int colNum,vector<vector<int>>* mat,
    vector<vector<int>>* vis,int initialColor,int change){
    vector<pair<int,int>> neighbors=findNeighbors(starting_pair,mat);
    int neighborsSize=neighbors.size();
    (*vis)[starting_pair.first][starting_pair.second]=1;
    (*mat)[starting_pair.first][starting_pair.second]=change;
    for(int i=0;i<neighborsSize;i++){
        if((*vis)[neighbors[i].first][neighbors[i].second]==0 && 
        (*mat)[neighbors[i].first][neighbors[i].second]==initialColor){
            dfsTraversal(neighbors[i],rowNum,colNum,mat,vis,initialColor,change);
        }
    }
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