#include<bits/stdc++.h>
using namespace std;

//we using queue here because we aint giving priority to cost bu thave to decide according to stops
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //flights----->{node1,node2,weight}
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    for(vector<int> vec:flights){
        adj[vec[0]].emplace_back(make_pair(vec[1],vec[2])); //convert to-->adjacency list containing pair<int,int>{node,weight}
    }
    queue<vector<int>> q; //{node,distance,stops}
    vector<pair<int,int>> distance_stops_arr;
    for(int i=0;i<n;i++){
        distance_stops_arr.emplace_back(make_pair(INT32_MAX,0));
    }
    distance_stops_arr[src]=make_pair(0,0);
    q.push({src,0,0});
    while(!q.empty()){
        vector<int> current=q.front();
        q.pop();
        int currentNode=current[0];
        int currentDistance=current[1];
        int currentStops=current[2];
        if(currentStops==k+1) continue;
        for(pair<int,int> p:adj[currentNode]){
            if(currentStops<k+1){
                if(currentDistance+p.second<distance_stops_arr[p.first].first){
                    int tempStops=currentStops+1;
                    distance_stops_arr[p.first]=make_pair(currentDistance+p.second,tempStops);
                    q.push({p.first,distance_stops_arr[p.first].first,tempStops});
                }
            }
        }
    }
    if(distance_stops_arr[dst].first==INT32_MAX) return -1;
    return distance_stops_arr[dst].first;
}

