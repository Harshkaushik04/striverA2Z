#include<bits/stdc++.h>
using namespace std;

//can be implemented both by bfs/dfs
int num_islands(vector<vector<int>> mat){
    int rowNum=mat.size();
    int colNum=mat[0].size();
    vector<vector<int>> vis(rowNum,vector<int>(colNum,0));
    int ans=0;
    for(int i=0;i<rowNum;i++){
        for(int j=0;j<colNum;j++){
            if(vis[i][j]==0 && mat[i][j]==1){
                pair<int,int> p={i,j};
                bfsTraversal(p,rowNum,colNum,&mat,&vis);
                ans++;
            }
        }
    }
    return ans;
}

void bfsTraversal(pair<int,int> starting_pair,int rowNum,int colNum,vector<vector<int>>* mat,
    vector<vector<int>>* vis){
    queue<pair<int,int>> q;
    pair<int,int> current;
    vector<pair<int,int>> neighbors;
    int neighborsSize;
    q.push(starting_pair);
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            (*vis)[current.first][current.second]=1;
            q.pop();
            neighbors=findNeighbors(current,*mat);
            neighborsSize=neighbors.size();
            for(int j=0;j<neighborsSize;j++){
                if((*vis)[neighbors[j].first][neighbors[j].second]==0){
                    q.push(neighbors[j]);
                }
            }
        }
    }
}

vector<pair<int,int>> findNeighbors(pair<int,int> current,vector<vector<int>> mat){
    int first=current.first;
    int second=current.second;
    int firstLimit=mat.size();
    int secondLimit=mat[0].size();
    vector<pair<int,int>> ans;
    pair<int,int> temp;
    if(second-1>=0){
        temp=make_pair(first,second-1);
        if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        if(first-1>=0){
            temp=make_pair(first-1,second-1);
            if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
        if(first+1<firstLimit){
            temp=make_pair(first+1,second-1);
            if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
    }
    if(second+1<secondLimit){
        temp=make_pair(first,second+1);
        if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        if(first+1<firstLimit){
            temp=make_pair(first+1,second+1);
            if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
        if(first-1>=0){
            temp=make_pair(first-1,second+1);
            if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
    }
    if(first-1>=0){
        temp=make_pair(first-1,second);
        if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
    }
    if(first+1<firstLimit){
        temp=make_pair(first+1,second);
        if(mat[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
    }
    return ans;
}