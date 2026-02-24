#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> distance_arr(V,1e8);
    distance_arr[src]=0;
    for(int i=0;i<V-1;i++){
        for(vector<int> edge:edges){
            if((distance_arr[edge[1]]>distance_arr[edge[0]]+edge[2]) && distance_arr[edge[0]]!=1e8) distance_arr[edge[1]]=distance_arr[edge[0]]+edge[2];
        }
    }
    for(vector<int> edge:edges){
        if((distance_arr[edge[1]]>distance_arr[edge[0]]+edge[2]) && distance_arr[edge[0]]!=1e8) return vector<int>{-1};
    }
    return distance_arr;
}