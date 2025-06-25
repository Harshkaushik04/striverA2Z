#include<bits/stdc++.h>
using namespace std;

void traversal(int i,int n,vector<vector<int>>& adj,vector<int>& visited_arr,vector<int>& ans){
    if(visited_arr[i]==0){
        visited_arr[i]=1;
        ans.emplace_back(i);
        for(int neighbor:adj[i]){
            traversal(neighbor,n,adj,visited_arr,ans);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    int n=adj.size();
    vector<int> visited_arr(n,0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(visited_arr[i]==0) traversal(i,n,adj,visited_arr,ans);
    }
    return ans;
}