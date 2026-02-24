#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int V,vector<vector<int>>& edg){
    vector<vector<int>> adj(V,vector<int>());
    for(vector<int> vec:edg){
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
    while(!q.empty()){
        int qSize=q.size();
        for(int j=0;j<qSize;j++){
            int current=q.front();
            q.pop();
            for(int neighbor:adj[current]) {
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
    }
    for(int i=0;i<V;i++){
        if(indegree[i]!=0) return true;
    }
    return false;
}