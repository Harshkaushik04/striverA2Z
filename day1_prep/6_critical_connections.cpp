#include<bits/stdc++.h>
using namespace std;


void dfs(int node,int parent,vector<int>& current,vector<int>& best,vector<vector<int>>& adj,vector<int>& visited_arr
        ,vector<vector<int>>& ans,int& time){
    if(visited_arr[node]==-1){
        visited_arr[node]=1;
        time++;
        current[node]=time;
        best[node]=time;
        for(int neighbor:adj[node]){
            dfs(neighbor,node,current,best,adj,visited_arr,ans,time);
            if(neighbor!=parent) best[node]=min(best[node],best[neighbor]);
        }
        if(parent!=-1 && current[parent]<best[node]){
            ans.emplace_back(vector<int>{parent,node});
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
    vector<int> current(n,-1);
    vector<int> best(n,-1);
    vector<vector<int>> ans;
    vector<int> visited_arr(n,-1);
    vector<vector<int>> adj(n,vector<int>());
    int time=0;
    for(vector<int>& edge:connections){
        adj[edge[0]].emplace_back(edge[1]);
        adj[edge[1]].emplace_back(edge[0]);
    }
    for(int i=0;i<n;i++){
        if(visited_arr[i]!=-1) continue;
        dfs(i,-1,current,best,adj,visited_arr,ans,time);
    }
    return ans;
}