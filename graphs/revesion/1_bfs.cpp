#include<bits/stdc++.h>
using namespace std;

void traversal(int i,int n,vector<vector<int>>& adj,vector<int>& visited_arr,vector<int>& ans){
    queue<int> q;
    visited_arr[i]=1;
    q.push(i);
    int current,tempSize;
    while(!q.empty()){
        current=q.front();
        tempSize=adj[current].size();
        ans.emplace_back(current);
        q.pop();
        for(int j=0;j<tempSize;j++){
            if(visited_arr[adj[current][j]]==0){
                q.push(adj[current][j]);
                visited_arr[adj[current][j]]=1;
            }
        }
    }
}

vector<int> bfs(vector<vector<int>> &adj) {
    // Code here
    int n=adj.size();
    vector<int> visited_arr(n,0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(visited_arr[i]==0) traversal(i,n,adj,visited_arr,ans);
    }
    return ans;
}