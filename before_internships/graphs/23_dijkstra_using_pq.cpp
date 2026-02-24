#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> distance_arr(V,INT32_MAX);
    distance_arr[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,S));
    while(!pq.empty()){
        pair<int,int> current=pq.top();
        pq.pop();
        for(vector<int> neighbor_vec:adj[current.second]){
            int edge_distance=neighbor_vec[1];
            int neighbor=neighbor_vec[0];
            int new_distance=edge_distance+current.first;
            if(distance_arr[neighbor]>new_distance){
                distance_arr[neighbor]=new_distance;
                pq.push(make_pair(new_distance,neighbor));
            }
        }
    }
    return distance_arr;
}