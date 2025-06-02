#include<bits/stdc++.h>
using namespace std;
//using dfs
bool directed_cycle_detect(vector<vector<int>>& adj){
    int N=adj.size();
    vector<int> visited_arr(N,0),path_visited_arr(N,0);
    bool ans=false;
    for(int i=0;i<N;i++){
        if(visited_arr[i]==0){
            traversal(i,adj,visited_arr,path_visited_arr,ans);
            if(ans) break;
        }
    }
    return ans;
}

void traversal(int start,vector<vector<int>>& adj,vector<int>& visited_arr,vector<int>& path_visited_arr,bool& ans){
    if(ans) return;
    vector<int> neighbors=adj[start];
    visited_arr[start]=1;
    path_visited_arr[start]=1;
    for(int neighbor:neighbors){
        if(visited_arr[neighbor]==0){
            traversal(neighbor,adj,visited_arr,path_visited_arr,ans);
            if(ans) return;
        }
        else if(path_visited_arr[neighbor]==1){
            ans=true;
            return;
        }
    }
    path_visited_arr[start]=0;
}