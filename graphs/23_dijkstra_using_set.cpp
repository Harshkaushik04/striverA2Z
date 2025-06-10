#include<bits/stdc++.h>
using namespace std;
//adj---->{weight,node}
//s----->{distance,node}
vector<int> dijkstra_algo(int V,vector<vector<int>> adj[],int S){
    set<pair<int,int>> s;
    vector<int> distance_arr(V,INT32_MAX);
    distance_arr[S]=0;
    s.insert(make_pair(0,S));
    while(!s.empty()){
        pair<int,int> current=*s.begin();
        s.erase(current);
        int distance=current.first;
        int node=current.second;
        for(vector<int> vec:adj[node]){
            int weight=vec[0];
            int neighbor=vec[1];
            if(distance+weight<distance_arr[neighbor]){
                if(distance_arr[neighbor]!=INT32_MAX){
                    s.erase(make_pair(distance_arr[neighbor],neighbor));
                }
                s.insert(make_pair(distance+weight,neighbor));
                distance_arr[neighbor]=distance+weight;
            }
        }
    }
    return distance_arr;
}