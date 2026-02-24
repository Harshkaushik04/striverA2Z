#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int i,int n,vector<vector<pair<int,int>>>& adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int INF=1e9;
    vector<int> distance_arr(n,INF);
    distance_arr[i]=0;
    pq.push(make_pair(0,i));
    while(!pq.empty()){
        pair<int,int> current=pq.top();
        pq.pop();
        if(current.first>distance_arr[current.second]) continue;
        for(pair<int,int>& neighbor:adj[current.second]){
            if(distance_arr[current.second]+neighbor.second<distance_arr[neighbor.first] && distance_arr[current.second]!=INF){
                distance_arr[neighbor.first]=distance_arr[current.second]+neighbor.second;
                pq.push(make_pair(distance_arr[neighbor.first],neighbor.first));
            }
        }
    }
    return distance_arr;
}

int f(vector<vector<pair<int,int>>>& adj,int node,int target,vector<vector<int>>& dp,int n,int MOD,int max_target){
    if(target>max_target ||target<0) return 0;
    if(node==n-1){
        if(target==0) return 1;
        else return 0;
    }
    if(dp[node][target]!=-1) return dp[node][target];
    long long ans=0;
    for(pair<int,int>& neighbor:adj[node]){
        long long temp=f(adj,neighbor.first,target-neighbor.second,dp,n,MOD,max_target);
        ans+=temp;
        ans%=MOD;
    }
    dp[node][target]=ans;
    return dp[node][target];
}

int countPaths(int n, vector<vector<int>>& roads) {
    vector<int> visited_arr(n,-1);
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    for(vector<int>& edge:roads){
        adj[edge[0]].emplace_back(make_pair(edge[1],edge[2]));
        adj[edge[1]].emplace_back(make_pair(edge[0],edge[2]));
    }
    int distance=0;
    vector<int> distance_arr=dijkstra(0,n,adj);
    int target=distance_arr[n-1];
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int MOD=1000000007;
    f(adj,0,target,dp,n,MOD,target);
    return dp[0][target];
}