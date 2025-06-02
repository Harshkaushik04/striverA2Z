#include<bits/stdc++.h>
using namespace std;

//can be implemented both by bfs/dfs
vector<vector<int>> floodFill(vector<vector<int>> mat,pair<int,int> start,int change){
    int rowNum=mat.size();
    int colNum=mat[0].size();
    //no need of visited_arr
    int initialColor=mat[start.first][start.second];
    if(change==initialColor) return mat;
    dfsTraversal(start,rowNum,colNum,&mat,initialColor,change);
    return mat;
}

void dfsTraversal(pair<int,int> starting_pair,int rowNum,int colNum,vector<vector<int>>* mat,int initialColor,int change){
    vector<pair<int,int>> neighbors=findNeighbors(starting_pair,mat);
    int neighborsSize=neighbors.size();
    (*mat)[starting_pair.first][starting_pair.second]=change;
    for(int i=0;i<neighborsSize;i++){
        if((*mat)[neighbors[i].first][neighbors[i].second]==initialColor){
            dfsTraversal(neighbors[i],rowNum,colNum,mat,initialColor,change);
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