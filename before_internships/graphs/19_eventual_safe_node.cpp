#include<bits/stdc++.h>
using namespace std;
//using kahn algo
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int N=graph.size();
    //make opoosite graph
    vector<vector<int>> oppGraph(N,vector<int>());
    vector<int> indegree(N,0);
    for(int i=0;i<N;i++){
        for(int num:graph[i]){
            oppGraph[num].emplace_back(i);
        }
    }
    for(int i=0;i<N;i++){
        for(int num:oppGraph[i]){
            indegree[num]++;
        }
    }
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
            ans.emplace_back(i);
        }
    }
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int neighbor:oppGraph[current]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0) q.push(neighbor);
        }
    }
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            ans.emplace_back(i);
        }
    }
    return ans;
}