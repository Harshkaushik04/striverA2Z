#include<bits/stdc++.h>
using namespace std;

void modifiedDfs(int i,stack<int>& st,vector<vector<int>>& adj,vector<int>& visited_arr){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        for(int neighbor:adj[i]){
            modifiedDfs(neighbor,st,adj,visited_arr);
        }
        st.push(i);
    }
}

void dfs(int i,vector<vector<int>>& adj,vector<int>& visited_arr){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        for(int neighbor:adj[i]){
            dfs(neighbor,adj,visited_arr);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {
    // code here
    int n=adj.size();
    vector<int> visited_arr(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(visited_arr[i]==-1) modifiedDfs(i,st,adj,visited_arr);
    }
    vector<vector<int>> adj1(n,vector<int>());
    for(int i=0;i<n;i++){
        for(int j:adj[i]){
            adj1[j].emplace_back(i);
        }
    }
    visited_arr.assign(n,-1);
    int ans=0;
    while(!st.empty()){
        int current=st.top();
        st.pop();
        if(visited_arr[current]==-1){
            dfs(current,adj1,visited_arr);
            ans++;
        }
    }
    return ans;
}