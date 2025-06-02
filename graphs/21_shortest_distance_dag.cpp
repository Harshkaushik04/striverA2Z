#include<bits/stdc++.h>
using namespace std;

// Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());
    for(vector<int> edge:edges){
        adj[edge[0]].emplace_back(make_pair(edge[1],edge[2]));
    }
    //topo sort using dfs
    stack<int> st;
    vector<int> visited_arr(V,0);
    for(int i=0;i<V;i++){
        if(visited_arr[i]==0){
            traversal(i,visited_arr,adj,st);
        }
    }
    vector<int> topo;
    while(!st.empty()){
        topo.emplace_back(st.top());
        st.pop();
    }
    vector<int> distance_arr(V,INT32_MAX);
    distance_arr[0]=0;
    for(int i:topo){
        if(distance_arr[i]==INT32_MAX) distance_arr[i]=-1;
        else{
            for(pair<int,int> p:adj[i]){
                distance_arr[p.first]=min(distance_arr[p.first],distance_arr[i]+p.second);
            }
        }
    }
    return distance_arr;
}

void traversal(int start,vector<int>& visited_arr,vector<vector<pair<int,int>>>& adj,stack<int>& st){
    visited_arr[start]=1;
    for(pair<int,int> neighbor:adj[start]){
        if(visited_arr[neighbor.first]==0){
            traversal(neighbor.first,visited_arr,adj,st);
        }
    }
    st.push(start);
}