#include<bits/stdc++.h>
using namespace std;


int num_distinct_islands(vector<vector<int>> mat){
    int rowNum=mat.size();
    int colNum=mat[0].size();
    vector<vector<int>> vis(rowNum,vector<int>(colNum,0));
    vector<vector<pair<int,int>>> traversals;
    int ans=0;
    for(int i=0;i<rowNum;i++){
        for(int j=0;j<colNum;j++){
            if(vis[i][j]==0 && mat[i][j]==1){
                pair<int,int> p={i,j};
                vector<pair<int,int>> thisTraversal=bfsTraversal(p,rowNum,colNum,&mat,&vis,&traversals);
                int traversalsSize=traversals.size();
                bool flag=false;
                for(int k=0;k<traversalsSize-1;k++){
                    if(traversals[k]==thisTraversal){
                        flag=true;
                        break;
                    }
                }
                if(!flag) ans++;
            }
        }
    }
    return ans;
}

vector<pair<int,int>> bfsTraversal(pair<int,int> starting_pair,int rowNum,int colNum,vector<vector<int>>* mat,
    vector<vector<int>>* vis,vector<vector<pair<int,int>>>* traversalsP){
    queue<pair<int,int>> q;
    pair<int,int> current;
    vector<pair<int,int>> neighbors;
    int neighborsSize;
    q.push(starting_pair);
    vector<pair<int,int>> thisTraversal;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            (*vis)[current.first][current.second]=1;
            q.pop();
            thisTraversal.emplace_back(make_pair(current.first-starting_pair.first,current.second-starting_pair.second));
            neighbors=findNeighbors(mat,current);
            neighborsSize=neighbors.size();
            for(int j=0;j<neighborsSize;j++){
                if((*vis)[neighbors[j].first][neighbors[j].second]==0 && (*mat)[neighbors[j].first][neighbors[j].second]==1){
                    q.push(neighbors[j]);
                }
            }
        }
    }
    (*traversalsP).emplace_back(thisTraversal);
    return thisTraversal;
}

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