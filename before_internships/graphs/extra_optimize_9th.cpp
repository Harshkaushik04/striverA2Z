#include<bits/stdc++.h>
using namespace std;

//grid of 'o' and 'x' and fill all 'o' with 'x' who are surrounded by 'x' on all 4 sides
/*
xxxx       xxxx
xoox  =>   xxxx
xoox       xxxx   
xxxx       xxxx
*/
void fill(vector<vector<char>> grid){
    int rowNum=grid.size();
    int colNum=grid[0].size();
    vector<pair<int,int>> cornerO,keepO;
    vector<vector<char>> ans(rowNum,vector<char>(colNum,'X'));
    vector<vector<char>> visited_arr(rowNum,vector<char>(colNum,0));
    for(int i=0;i<rowNum;i++){
        if(grid[i][0]=='O') cornerO.emplace_back(make_pair(i,0));
        if(grid[i][colNum-1]=='O') cornerO.emplace_back(make_pair(i,colNum-1));
    }
    for(int i=0;i<colNum;i++){
        if(grid[0][i]=='O') cornerO.emplace_back(make_pair(0,i));
        if(grid[rowNum-1][i]=='O') cornerO.emplace_back(make_pair(rowNum-1,i));
    }
    int cornerOsize=cornerO.size();
    for(int i=0;i<cornerOsize;i++){
        if(visited_arr[cornerO[i].first][cornerO[i].second]==0) traversal(cornerO[i],&ans,&grid,&keepO,&visited_arr);
    }
    grid=ans;
}

void traversal(pair<int,int> start,vector<vector<char>>* ansP,vector<vector<char>>* gridP,vector<pair<int,int>>* keepO,vector<vector<char>>* visited_arrP){
    (*keepO).emplace_back(start);
    (*ansP)[start.first][start.second]='O';
    (*visited_arrP)[start.first][start.second]=1;
    vector<pair<int,int>> neighbors=findNeighbors(gridP,start);
    for(pair<int,int> neighbor:neighbors){
        if((*gridP)[neighbor.first][neighbor.second]=='O' && (*visited_arrP)[neighbor.first][neighbor.second]==0){
            traversal(neighbor,ansP,gridP,keepO,visited_arrP);
        }
    }
}

vector<pair<int,int>> findNeighbors(vector<vector<char>>* gridP,pair<int,int> node){
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