#include<bits/stdc++.h>
using namespace std;
//unit weight dag
//start from 0
//bfs
vector<int> shortestPath(vector<vector<int>>& adj){
    int V=adj.size();
    queue<int> q;
    vector<int> distance_arr(V,-1);
    vector<int> visited_arr(V,0);
    q.push(0);
    distance_arr[0]=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int neighbor:adj[current]){
            if(distance_arr[neighbor]==-1){
                distance_arr[neighbor]=distance_arr[current]+1;
                q.push(neighbor);
            }
        }
    }
    return distance_arr;
}