#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Code here
    vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
    for(vector<int> vec:edges){
        adj[vec[0]].emplace_back(make_pair(vec[1],vec[2]));
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance_arr(V,INT32_MAX);
    distance_arr[src]=0;
    pq.push(make_pair(src,0));
    while(!pq.empty()){
        pair<int,int> current=pq.top();
        pq.pop();
        for(pair<int,int> neighbor:adj[current.first]){
            if(distance_arr[neighbor.first]>distance_arr[current.first]+neighbor.second){
                distance_arr[neighbor.first]=distance_arr[current.first]+neighbor.second;
                pq.push(make_pair(neighbor.first,distance_arr[neighbor.first]));
            }
        }
    }
    for(int i=0;i<V;i++){
        if(distance_arr[i]==INT32_MAX) distance_arr[i]=-1;
    }
    return distance_arr;
}