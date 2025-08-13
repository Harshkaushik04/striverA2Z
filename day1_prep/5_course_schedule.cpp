#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj,vector<int>& visited_arr,vector<int>& path_visited,int node,bool& flag){
    if(visited_arr[node]==-1){
        visited_arr[node]=1;
        path_visited[node]=1;
        for(int neighbor:adj[node]){
            dfs(adj,visited_arr,path_visited,neighbor,flag);
            if(flag) return;
        }
        path_visited[node]=0;
    }
    else if(path_visited[node]==1){
        flag=true;
        return;
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n=numCourses;
    vector<vector<int>> adj(n,vector<int>());
    for(vector<int>& edge:prerequisites) adj[edge[1]].emplace_back(edge[0]);
    vector<int> visited_arr(n,-1);
    vector<int> path_visited_arr(n,-1);
    bool flag=false;
    for(int i=0;i<n;i++){
        if(visited_arr[i]!=-1) continue;
        dfs(adj,visited_arr,path_visited_arr,i,flag);
        if(flag) break;
    }
    if(flag) return false;
    return true;
}