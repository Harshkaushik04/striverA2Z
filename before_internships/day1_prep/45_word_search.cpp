#include<bits/stdc++.h>
using namespace std;
void dfs(int x,int y,vector<pair<int,int>>& changes,int target,string& s,vector<vector<int>>& path_vis,
        bool& absolute_flag,int ssize,int m,int n,vector<vector<char>>& board){
    if(path_vis[x][y]!=-1) return;
    if(absolute_flag) return; 
    if(target>=ssize){
        absolute_flag=true;
        return;
    }
    if(path_vis[x][y]==-1){
        path_vis[x][y]=1;
        for(const pair<int,int>& change:changes){
            pair<int,int> co=make_pair(x+change.first,y+change.second);
            if(co.first>=0 && co.first<m && co.second>=0 && co.second<n){
                if(board[co.first][co.second]==s[target]){
                    dfs(co.first,co.second,changes,target+1,s,path_vis,absolute_flag,ssize,m,n,board);
                    if(absolute_flag) return;
                }
            }
            if(absolute_flag) return;
        }
        path_vis[x][y]=-1;
    }
}

bool exist(vector<vector<char>>& board, string word) {
    int ssize=word.size();
    int m=board.size();
    int n=board[0].size();
    vector<pair<int,int>> changes=vector<pair<int,int>>{make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
    vector<vector<int>> path_vis(m,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[0]){
                if(ssize==1) return true;
                int target=1;
                bool absolute_flag=false;
                dfs(i,j,changes,target,word,path_vis,absolute_flag,ssize,m,n,board);
                if(absolute_flag) return true;
            }
        }
    }
    return false;
}