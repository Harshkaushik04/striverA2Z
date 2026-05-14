#include<bits/stdc++.h>
using namespace std;
bool containsCycle(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    bool done=false;
    for(int curr_alphabet='a';curr_alphabet<='z';curr_alphabet++){
        vector<vector<char>> visited_arr(n,vector<char>(m,'-1'));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited_arr[i][j]==curr_alphabet) continue;
                q.push(pair<pair<int,int>,pair<int,int>>{pair<int,int>{i,j},pair<int,int>{-1,1}});
                visited_arr[i][j]=curr_alphabet;
                while(!q.empty()){
                    pair<pair<int,int>,pair<int,int>> curr_complete=q.front();
                    q.pop();
                    pair<int,int> curr=curr_complete.first;
                    pair<int,int> parent=curr_complete.second;
                    if(grid[curr.first][curr.second]!=curr_alphabet) break;
                    vector<pair<int,int>> vec={{0,1},{1,0},{-1,0},{0,-1}};
                    for(pair<int,int>& p:vec){
                        int x1=p.first;
                        int y1=p.second;
                        pair<int,int> neighbor={curr.first+x1,curr.second+y1};
                        if(neighbor!=parent && neighbor.first<n && neighbor.first>=0 && neighbor.second<m && neighbor.second>=0){
                            if(grid[neighbor.first][neighbor.second]!=curr_alphabet) continue;
                            else if(visited_arr[neighbor.first][neighbor.second]==curr_alphabet){
                                done=true;
                                return true;
                            }
                            else{
                                q.push(pair<pair<int,int>,pair<int,int>>{neighbor,curr});
                                visited_arr[neighbor.first][neighbor.second]=curr_alphabet;
                            }
                        }
                    }
                }
            }
            
        }
    }
    return false;
}

int main(){
    return 0;
}