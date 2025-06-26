#include<bits/stdc++.h>
using namespace std;

void modifiedDfs(int i,int N,vector<vector<pair<int,int>>>& adj,vector<int>& visited_arr,vector<int>& ans){
    if(visited_arr[i]==0){
        visited_arr[i]=1;
        for(pair<int,int> neighbor:adj[i]){
            modifiedDfs(neighbor.first,N,adj,visited_arr,ans);
        }
        ans.emplace_back(i);
    }
}

vector<int> topoSort(int V, vector<vector<pair<int,int>>> adj) {
    // code here
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

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
    for(int i=0;i<E;i++){
        adj[edges[i][0]].emplace_back(make_pair(edges[i][1],edges[i][2]));
    }
    vector<int> order=topoSort(V,adj);
    vector<int> distance_arr(V,INT32_MAX);
    distance_arr[0]=0;
    bool flag=false;
    for(int i=0;i<V;i++){
        if(order[i]==0 && !flag) flag=true;
        if(!flag) continue;
        for(pair<int,int> p:adj[order[i]]){
            distance_arr[p.first]=min(distance_arr[p.first],distance_arr[order[i]]+p.second);
        }
    }
    for(int i=0;i<V;i++){
        if(distance_arr[i]==INT32_MAX) distance_arr[i]=-1;
    }
    return distance_arr;
}