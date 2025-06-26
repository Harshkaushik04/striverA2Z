#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<int> visited_arr(V,0);
    vector<vector<int>> adj(V,vector<int>());
    int m=edges.size();
    for(int i=0;i<m;i++){
        adj[edges[i][0]].emplace_back(edges[i][1]);
        adj[edges[i][1]].emplace_back(edges[i][0]);
    }
    for(int i=0;i<V;i++){
        if(visited_arr[i]==0){
            queue<pair<int,int>> q;
            q.push(make_pair(i,-1));
            visited_arr[i]=1;
            while(!q.empty()){
                int tempSize=q.size();
                for(int j=0;j<tempSize;j++){
                    pair<int,int> current=q.front();
                    q.pop();
                    for(int neighbor:adj[current.first]){
                        if(visited_arr[neighbor]==0){
                            visited_arr[neighbor]=1;
                            q.push(make_pair(neighbor,current.first));
                        }
                        else if(visited_arr[neighbor]==1 && neighbor!=current.second){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}