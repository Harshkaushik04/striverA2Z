#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findNeighbors(pair<int,int> current,vector<vector<int>>* isConnected){
    int first=current.first;
    int second=current.second;
    int firstLimit=(*isConnected).size();
    int secondLimit=(*isConnected)[0].size();
    vector<pair<int,int>> ans;
    pair<int,int> temp;
    if(second-1>=0){
        temp=make_pair(first,second-1);
        if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        if(first-1>=0){
            temp=make_pair(first-1,second-1);
            if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
        if(first+1<firstLimit){
            temp=make_pair(first+1,second-1);
            if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
    }
    if(second+1<secondLimit){
        temp=make_pair(first,second+1);
        if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        if(first+1<firstLimit){
            temp=make_pair(first+1,second+1);
            if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
        if(first-1>=0){
            temp=make_pair(first-1,second+1);
            if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
        }
    }
    if(first-1>=0){
        temp=make_pair(first-1,second);
        if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
    }
    if(first+1<firstLimit){
        temp=make_pair(first+1,second);
        if((*isConnected)[temp.first][temp.second]==1){
            ans.emplace_back(temp);
        }
    }
    return ans;
}


void bfsTraversal(pair<int,int> starting_pair,int rowNum,int colNum,vector<vector<int>>* isConnected,
    vector<vector<int>>* vis){
    queue<pair<int,int>> q;
    pair<int,int> current;
    vector<pair<int,int>> neighbors;
    int neighborsSize;
    (*vis)[starting_pair.first][starting_pair.second]=1;
    q.push(starting_pair);
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            neighbors=findNeighbors(current,isConnected);
            neighborsSize=neighbors.size();
            for(int j=0;j<neighborsSize;j++){
                if((*vis)[neighbors[j].first][neighbors[j].second]==0){
                    (*vis)[neighbors[j].first][neighbors[j].second]=1;
                    q.push(neighbors[j]);
                }
            }
        }
    }
}

//can be implemented both by bfs/dfs
int findCircleNum(vector<vector<int>> isConnected){
    int rowNum=isConnected.size();
    int colNum=isConnected[0].size();
    vector<vector<int>> vis(rowNum,vector<int>(colNum,0));
    int ans=0;
    for(int i=0;i<rowNum;i++){
        for(int j=0;j<colNum;j++){
            if(vis[i][j]==0 && isConnected[i][j]==1){
                pair<int,int> p={i,j};
                bfsTraversal(p,rowNum,colNum,&isConnected,&vis);
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}