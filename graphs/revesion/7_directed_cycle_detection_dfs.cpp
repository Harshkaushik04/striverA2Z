#include<bits/stdc++.h>
using namespace std;

void modifiedDfs(int i,int N,vector<int>& visited_arr,vector<int>& path_visited,int& ans,vector<vector<int>>& adj){
    if(ans) return;
    if(path_visited[i]==1){
        ans=true;
        return;
    }
    if(visited_arr[i]==0){
        path_visited[i]=1;
        visited_arr[i]=1;
        for(int neighbor:adj[i]){
            modifiedDfs(neighbor,N,visited_arr,path_visited,ans,adj);
        }
        path_visited[i]=0;
    }
}

bool isCyclic(int V,vector<vector<int>>& edg){
    vector<vector<int>> adj(V,vector<int>());
    for(vector<int> vec:edg){
        adj[vec[0]].emplace_back(vec[1]);
    }
    int ans=false;
    vector<int> visited_arr(V,0);
    vector<int> path_visited(V,0);
    for(int i=0;i<V;i++){
        if(visited_arr[i]==0){
            modifiedDfs(i,V,visited_arr,path_visited,ans,adj);
            if(ans) return true;
        }
    }
    return false;
}