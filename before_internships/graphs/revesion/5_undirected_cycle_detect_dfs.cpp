#include<bits/stdc++.h>
using namespace std;

void modifiedDfs(int current,int parent,int grandParent,vector<vector<int>>& adj,vector<int>& visited_arr,int V,bool& ans){
    if(!ans) return;
    if(visited_arr[current]==0){
        visited_arr[current]=1;
        for(int neighbor:adj[current]){
            modifiedDfs(neighbor,current,parent,adj,visited_arr,V,ans);
        }
    }
    else if(visited_arr[current]==1 && grandParent!=current) ans=false;
}


bool isCycle(int V, vector<vector<int>>& edges){
    // Code here
    vector<int> visited_arr(V,0);
    vector<vector<int>> adj(V,vector<int>());
    int m=edges.size();
    for(int i=0;i<m;i++){
        adj[edges[i][0]].emplace_back(edges[i][1]);
        adj[edges[i][1]].emplace_back(edges[i][0]);
    }
    bool ans=true;
    for(int i=0;i<V;i++){
        if(visited_arr[i]==0){
            modifiedDfs(i,-1,-1,adj,visited_arr,V,ans);
        }
    }
    return !ans;
}