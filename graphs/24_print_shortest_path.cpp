#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<int> distance_arr(n+1,INT32_MAX);
    vector<int> x(n+1,-1);
    distance_arr[1]=0;
    vector<vector<pair<int,int>>> adj=undirected_edges_to_weighted_adj(n,edges);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //distance,node
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        pair<int,int> current=pq.top();
        pq.pop();
        int distance=current.first;
        int node=current.second;
        for(pair<int,int> p:adj[node]){
            int neighbor=p.first;
            int weight=p.second;
            if(weight+distance<distance_arr[neighbor]){
                distance_arr[neighbor]=weight+distance;
                pq.push(make_pair(distance+weight,neighbor));
                x[neighbor]=node;
            }
        }
    }
    if(distance_arr[n]==INT32_MAX) return {-1};
    int next=n;
    vector<int> ansPath;
    while(next!=-1){
        ansPath.emplace_back(next);
        next=x[next];
    }
    reverse(ansPath.begin(), ansPath.end());
    return ansPath;
}

//{a,b,weight}
//vertices from 1 to n
vector<vector<pair<int,int>>> undirected_edges_to_weighted_adj(int n,vector<vector<int>> edges){
    vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
    for(vector<int> edge:edges){
        int edge1=edge[0],edge2=edge[1],weight=edge[2];
        adj[edge1].emplace_back(make_pair(edge2,weight)); //node,weight
        adj[edge2].emplace_back(make_pair(edge1,weight));
    }
    return adj;
}