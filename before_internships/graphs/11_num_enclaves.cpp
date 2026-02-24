#include<bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
    int rowNum=grid.size(),colNum=grid[0].size();
    int total1=0;
    vector<pair<int,int>> corner1;
    for(int i=0;i<rowNum;i++){
        for(int j=0;j<colNum;j++){
            if(grid[i][j]==1) total1++;
            if((i == 0 || i == rowNum - 1 || j == 0 || j == colNum - 1) && grid[i][j] == 1) {
                corner1.emplace_back(make_pair(i, j));
            }
        }
    }
    queue<pair<int,int>> q;
    for(pair<int,int> p:corner1){
        q.push(p);
        grid[p.first][p.second]=0;
        total1--;
    }
    traversal(&total1,&q,&grid);
    return total1;
}

void traversal(int* total1P,queue<pair<int,int>>* qP,vector<vector<int>>* gridP){
    while(!(*qP).empty()){
        pair<int,int> current=(*qP).front();
        vector<pair<int,int>> neighbors=findNeighbors(gridP,current);
        (*qP).pop();
        for(pair<int,int> neighbor:neighbors){
            if((*gridP)[neighbor.first][neighbor.second]==1){
                (*qP).push(neighbor);
                (*gridP)[neighbor.first][neighbor.second]=0;
                (*total1P)--;
            }
        }
    }
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

int main(){
    return 0;
}