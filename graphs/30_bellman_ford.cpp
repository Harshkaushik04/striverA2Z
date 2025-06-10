#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> distance_arr(V,INT32_MAX);
    distance_arr[src]=0;
    int flag=false;
    for(int i=0;i<V-1;i++){
        flag=false;
        for(vector<int> edge:edges){
            if(distance_arr[edge[0]]!=INT32_MAX && distance_arr[edge[0]]+edge[2]<distance_arr[edge[1]]){
                distance_arr[edge[1]]=distance_arr[edge[0]]+edge[2];
                flag=true;
            }
        }
        if(!flag) break;
    }
    if(flag){
        for(vector<int> edge:edges){
            if(distance_arr[edge[0]]!=INT32_MAX && distance_arr[edge[0]]+edge[2]<distance_arr[edge[1]]){
                return {-1};
            }
        }
    }
    return distance_arr;
}