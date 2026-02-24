#include<bits/stdc++.h>
using namespace std;
//not completed
// int countPaths(int n, vector<vector<int>>& roads) {
//     vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
//     for(vector<int> edge:roads){
//         adj[edge[0]].emplace_back(make_pair(edge[1],edge[2]));
//         adj[edge[1]].emplace_back(make_pair(edge[0],edge[2]));
//     }
//     vector<pair<int,int>> distance_arr;
//     for(int i=0;i<n;i++){
//         if(i!=0) distance_arr[i]=make_pair(INT32_MAX,1); //distance,number of times
//         else distance_arr[i]=make_pair(0,1);
//     }
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//     vector<int> x(n,-1); //predecessor
//     pq.push(make_pair(0,0)); //distance,node

// }