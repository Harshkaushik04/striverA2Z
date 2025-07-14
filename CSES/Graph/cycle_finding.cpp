// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void modifiedDfs(vector<vector<pair<ll,ll>>>& adj,ll node,vector<ll> visited_arr,vector<ll> path_visited,vector<int>& ans,bool ansFlag){
//     if(visited_arr[node]==-1){
//         path_visited[node]=1;
//         visited_arr[node]=1;
//         for(pair<ll,ll> neighbor:adj[node]){
//             modifiedDfs(adj,neighbor,visited_arr,path_visited);
//             if
//         }
//         path_visited=-1;
//     }
//     else if(path_visited[node]!=-1){

//     }
// }

// vector<ll> negative_cycle_path(vector<vector<ll>>& adj,ll node,int n){
//     vector<ll> visited_arr(n+1,-1);
//     vector<ll> path_visited(n+1,-1);
//     modifiedDfs()
// }

// int main(){
//     ll n,m;
//     cin>>n>>m;
//     vector<vector<ll>> edges;
//     ll temp1,temp2,temp3;
//     for(int i=0;i<m;i++){
//         cin>>temp1>>temp2>>temp3;
//         edges.emplace_back(vector<ll>{temp1,temp2,temp3});
//     }
//     vector<ll> distance_arr(n+1,1e14);
//     distance_arr[1]=0;
//     for(int i=0;i<n-1;i++){
//         for(vector<ll> edge:edges){
//             if((distance_arr[edge[1]]>distance_arr[edge[0]]+edge[2]) && distance_arr[edge[0]]!=1e14) distance_arr[edge[1]]=distance_arr[edge[0]]+edge[2];
//         }
//     }
//     ll node=-1;
//     for(vector<ll> edge:edges){
//         if((distance_arr[edge[1]]>distance_arr[edge[0]]+edge[2]) && distance_arr[edge[0]]!=1e14){
//             node=edge[1];
//             break;
//         }
//     }
//     return 0;
// }