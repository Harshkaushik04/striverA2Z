#include<bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<vector<pair<int,double>>> adj(n,vector<pair<int,double>>()); //{node,probability of edge crossing}
    int num_edges=edges.size();
    for(int i=0;i<num_edges;i++){
        adj[edges[i][0]].emplace_back(make_pair(edges[i][1],succProb[i]));
        adj[edges[i][1]].emplace_back(make_pair(edges[i][0],succProb[i]));
    }
    priority_queue<pair<double,int>,vector<pair<double,int>>> pq; //{probability of reaching that node,that node}
    vector<double> probability_arr(n,0);
    probability_arr[start_node]=1;
    pq.push(make_pair(1,start_node));
    while(!pq.empty()){
        pair<double,int> current_node=pq.top();
        pq.pop();
        if(current_node.first<probability_arr[current_node.second]) continue;
        for(pair<int,double> neighbor_node:adj[current_node.second]){
            // if probability of reaching current_node*probability of crossing that node>probability of reaching neighbor_node already =>update
            if(current_node.first*neighbor_node.second>probability_arr[neighbor_node.first]){
                probability_arr[neighbor_node.first]=current_node.first*neighbor_node.second;
                pq.push(make_pair(probability_arr[neighbor_node.first],neighbor_node.first));
            }
        }
    }
    return probability_arr[end_node];
}