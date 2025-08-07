#include<bits/stdc++.h>
using namespace std;

vector<string> queens_location_to_board(vector<pair<int,int>>& queens_location,int n,const vector<string>& clear_board){
    vector<string> board=clear_board;
    for(pair<int,int>& p:queens_location) board[p.first][p.second]='Q';
    return board;
}

void cover_and_check(int x,int y,int n,bool& flag,vector<vector<int>>& vis){
    vector<pair<int,int>> changes={{1,1},{1,-1},{-1,1},{-1,-1}};
    vector<pair<int,int>> checked;
    for(int i=0;i<n;i++){
        if((vis[x][i]==1||vis[i][y]==1) && (i!=x) && (i!=y)){
            flag=false;
            break;
        }
        vis[x][i]=1;
        vis[i][y]=1;
        checked.emplace_back(make_pair(x,i));
        checked.emplace_back(make_pair(i,y));
        for(int j=0;j<4;j++){
            int x1=x+i*changes[j].first;
            int y1=y+i*changes[j].second;
            if(x1>=0 && x1<n && y1>=0 && y1<n){
                if(vis[x1][y1]==1){
                    flag=false;
                    break;
                }
                vis[x1][y1]=1;
            }
        }
        if(!flag) break;
    }
    if(!flag){
        for(pair<int,int>& p:checked) vis[p.first][p.second]=0;
    }
}

void uncover(int x,int y,int n,vector<vector<int>>& vis){
    vector<pair<int,int>> changes={{1,1},{1,-1},{-1,1},{-1,-1}};
    for(int i=0;i<n;i++){
        vis[x][i]=0;
        vis[i][y]=0;
        for(int j=0;j<4;j++){
            int x1=x+i*changes[j].first;
            int y1=y+i*changes[j].second;
            if(x1>=0 && x1<n && y1>=0 && y1<n) vis[x1][y1]=0;
        }
    }
}

void f(int x,int y,int n,int queens_rem,vector<pair<int,int>>& queens_location,vector<vector<int>>& vis,vector<vector<string>>& ans,const vector<string>& clear_board){
    vector<string> board=clear_board;
    if(queens_rem==0){
        ans.emplace_back(queens_location_to_board(queens_location,n,board));
        return;
    }
    if(x==-1||y==-1) return;
    bool flag=true;
    if(vis[x][y]==1){
        if(x==0) f(n-1,y-1,n,queens_rem,queens_location,vis,ans,board);
        else f(x-1,y,n,queens_rem,queens_location,vis,ans,board);
    }
    else{
        cover_and_check(x,y,n,flag,vis);
        if(flag){
            if(x==0){
                queens_location.emplace_back(make_pair(x,y));
                f(n-1,y-1,n,queens_rem-1,queens_location,vis,ans,board);
                uncover(x,y,n,vis);
                queens_location.pop_back();
                f(n-1,y-1,n,queens_rem,queens_location,vis,ans,board);
            }
            else{
                queens_location.emplace_back(make_pair(x,y));
                f(x-1,y,n,queens_rem-1,queens_location,vis,ans,board);
                uncover(x,y,n,vis);
                queens_location.pop_back();
                f(x-1,y,n,queens_rem,queens_location,vis,ans,board);
            }
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> clear_board(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            clear_board[i]+='.';
        }
    }
    vector<pair<int,int>> queens_location;
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<string>> ans;
    f(n-1,n-1,n,n,queens_location,vis,ans,clear_board);
    return ans;
}