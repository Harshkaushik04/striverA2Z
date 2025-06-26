#include<bits/stdc++.h>
using namespace std;
//using kahn algo,assuming dag (no cycle)
vector<int> topoSort(int V, vector<vector<int>>& edges){
    vector<vector<int>> adj(V,vector<int>());
    for(vector<int> vec:edges){
        adj[vec[0]].emplace_back(vec[1]);
    }
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(int j:adj[i]){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int qSize=q.size();
        for(int j=0;j<qSize;j++){
            int current=q.front();
            q.pop();
            ans.emplace_back(current);
            for(int neighbor:adj[current]) {
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
    }
    return ans;
}