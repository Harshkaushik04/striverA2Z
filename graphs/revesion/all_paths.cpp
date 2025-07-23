#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int dest,vector<vector<int>>& graph,vector<int>& visited_arr,vector<int>& path,vector<vector<int>>& all_paths){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        path.emplace_back(i);
        if(i==dest){
            all_paths.emplace_back(path);
        }
        else{
            for(int neighbor:graph[i]){
                dfs(neighbor,dest,graph,visited_arr,path,all_paths);
            }
        }
        path.pop_back();
        visited_arr[i]=-1;
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> visited_arr(n,-1);
    vector<vector<int>> all_paths;
    vector<int> path;
    dfs(0,n-1,graph,visited_arr,path,all_paths);
    return all_paths;
}