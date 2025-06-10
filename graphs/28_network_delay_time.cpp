#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int V, int S) {
    vector<vector<pair<int,int>>> adj(V+1,vector<pair<int,int>>());
    for(vector<int> edge:times){
        adj[edge[0]].emplace_back(make_pair(edge[1],edge[2]));
    }
    vector<int> distance_arr(V+1,INT32_MAX);
    distance_arr[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,S));
    while(!pq.empty()){
        pair<int,int> current=pq.top();
        pq.pop();
        if(current.first>distance_arr[current.second]) continue;
        for(pair<int,int> neighbor_vec:adj[current.second]){
            int edge_distance=neighbor_vec.second;
            int neighbor=neighbor_vec.first;
            int new_distance=edge_distance+current.first;
            if(distance_arr[neighbor]>new_distance){
                distance_arr[neighbor]=new_distance;
                pq.push(make_pair(new_distance,neighbor));
            }
        }
    }
    int ans=-1;
    for(int i=1;i<V+1;i++){
        if(distance_arr[i]==INT32_MAX) return -1;
        if(distance_arr[i]>ans) ans=distance_arr[i];
    }
    return ans;
}