#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int parent,vector<int>& visited_arr,vector<int>& starting_time,vector<int>& end_time,
    vector<vector<int>>& adj,vector<vector<int>>& ans,int& currentTime){
        if(visited_arr[i]==-1){
            visited_arr[i]=1;
            starting_time[i]=currentTime;
            currentTime++;
            //time to spread
            for(int neighbor:adj[i]){
                dfs(neighbor,i,visited_arr,starting_time,end_time,adj,ans,currentTime);
                if(neighbor!=parent){
                    end_time[i]=min(end_time[i],starting_time[neighbor]);
                    end_time[i]=min(end_time[i],end_time[neighbor]);
                }
            }
            if(parent>=0 && end_time[i]>starting_time[parent]) ans.emplace_back(vector<int>{parent,i});
        }
    }
    
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n,vector<int>());
    for(vector<int>& edge:connections){
        adj[edge[0]].emplace_back(edge[1]);
        adj[edge[1]].emplace_back(edge[0]);
    }
    vector<int> visited_arr(n,-1);
    vector<int> starting_time(n,INT32_MAX);
    vector<int> end_time(n,INT32_MAX);
    vector<vector<int>> ans;
    //assuming number of connected components=1
    int currentTime=0;
    dfs(0,-1,visited_arr,starting_time,end_time,adj,ans,currentTime);
    return ans;
}