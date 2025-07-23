#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int parent,vector<vector<int>>& adj,vector<int>& visited_arr,vector<int>& disc_arr,vector<int>& best_arr,int time,vector<vector<int>>& ans){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        disc_arr[i]=time;
        best_arr[i]=time;
        time++;
        for(int neighbor:adj[i]){
            dfs(neighbor,i,adj,visited_arr,disc_arr,best_arr,time,ans);
            if(best_arr[neighbor]!=-1 && neighbor!=parent){
                best_arr[i]=min(best_arr[i],best_arr[neighbor]);
            }
        }
        if(parent>=0 && best_arr[i]>disc_arr[parent]) ans.emplace_back(vector<int>{parent,i});
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
    vector<int> visited_arr(n,-1);
    vector<int> disc_arr(n,-1);
    vector<int> best_arr(n,-1);
    vector<vector<int>> adj(n,vector<int>());
    for(vector<int>& vec:connections){
        adj[vec[0]].emplace_back(vec[1]);
        adj[vec[1]].emplace_back(vec[0]);
    }
    int time=1;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(visited_arr[i]==-1){
            dfs(i,-1,adj,visited_arr,disc_arr,best_arr,time,ans);
        }
    }
    return ans;
}