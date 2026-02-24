#include<bits/stdc++.h>
using namespace std;

void modifiedDfs(int i,int N,vector<vector<int>>& adj,vector<int>& visited_arr,vector<int>& ans){
    if(visited_arr[i]==0){
        visited_arr[i]=1;
        for(int neighbor:adj[i]){
            modifiedDfs(neighbor,N,adj,visited_arr,ans);
        }
        ans.emplace_back(i);
    }
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<vector<int>> adj(V,vector<int>());
    for(vector<int> vec:edges){
        adj[vec[0]].emplace_back(vec[1]);
    }
    vector<int> visited_arr(V,0);
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(visited_arr[i]==0){
            modifiedDfs(i,V,adj,visited_arr,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}