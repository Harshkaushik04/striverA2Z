#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void modified_dijkstra(int i,int n,vector<vector<pair<int,int>>>& adj,vector<ll>& distance_arr,vector<int>& ways,int MOD){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    ll INF=1e15;
    distance_arr[i]=0;
    ways[i]=1;
    pq.push(make_pair(0,i));
    while(!pq.empty()){
        pair<int,int> current=pq.top();
        pq.pop();
        if(current.first>distance_arr[current.second]) continue;
        for(pair<int,int>& neighbor:adj[current.second]){
            if(distance_arr[current.second]+neighbor.second<distance_arr[neighbor.first] && distance_arr[current.second]!=INF){
                distance_arr[neighbor.first]=distance_arr[current.second]+neighbor.second;
                pq.push(make_pair(distance_arr[neighbor.first],neighbor.first));
                ways[neighbor.first]=ways[current.second];
            }
            else if(distance_arr[current.second]+neighbor.second==distance_arr[neighbor.first] && distance_arr[current.second]!=INF){
                ways[neighbor.first]+=ways[current.second];
                ways[neighbor.first]%=MOD;
            }
        }
    }
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    for(vector<int>& edge:roads){
        adj[edge[0]].emplace_back(make_pair(edge[1],edge[2]));
        adj[edge[1]].emplace_back(make_pair(edge[0],edge[2]));
    }
    ll INF=1e15;
    int MOD=1000000007;
    vector<ll> distance_arr(n,INF);
    vector<int> ways(n,0);
    modified_dijkstra(0,n,adj,distance_arr,ways,MOD);
    return ways[n-1];
}