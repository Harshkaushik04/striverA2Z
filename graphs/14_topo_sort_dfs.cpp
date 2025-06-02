#include<bits/stdc++.h>
using namespace std;
//given a dag

void dfs(int start,vector<vector<int>>& adj,vector<int>& visited_arr,stack<int>& st){
    vector<int> neighbors=adj[start];
    visited_arr[start]=1;
    for(int neighbor:neighbors){
        if(visited_arr[neighbor]==0){
            dfs(neighbor,adj,visited_arr,st);
        }
    }
    st.push(start);
}

vector<int> topo_sort_dfs(vector<vector<int>>& adj){
    stack<int> st;
    int N=adj.size();
    vector<int> visited_arr(N,0);
    for(int i=0;i<N;i++){
        if(visited_arr[i]==0){
            dfs(i,adj,visited_arr,st);
        }
    }
    int stSize=st.size();
    vector<int> ans;
    for(int i=0;i<stSize;i++){
        ans.emplace_back(st.top());
        st.pop();
    }
    return ans;
}