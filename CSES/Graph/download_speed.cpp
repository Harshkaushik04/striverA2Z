#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// void printArr1(vector<vector<ll>> arr,string message){
//     ll ssize1=arr.size();
//     cout<<"========================="<<endl;
//     cout<<message<<":"<<endl;
//     for(ll i=0;i<ssize1;i++){
//         for(ll j=0;j<arr[i].size();j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     } 
//     cout<<"========================="<<endl;
// }

// void printArr2(vector<ll> arr,string message){
//     ll ssize=arr.size();
//     cout<<"========================="<<endl;
//     cout<<message<<":"<<endl;
//     for(ll i=0;i<ssize;i++) cout<<arr[i]<<" ";
//     cout<<endl;
//     cout<<"========================="<<endl;
// }

// void printArr3(vector<vector<pair<ll,ll>>> arr,string message){
//     ll ssize1=arr.size();
//     cout<<"========================="<<endl;
//     cout<<message<<":"<<endl;
//     for(ll i=0;i<ssize1;i++){
//         for(ll j=0;j<arr[i].size();j++){
//             cout<<arr[i][j].first<<","<<arr[i][j].second<<"||";
//         }
//         cout<<endl;
//     } 
//     cout<<"========================="<<endl;
// }

vector<ll> make_level_graph(ll n,vector<vector<ll>>& adj,vector<vector<pair<ll,ll>>>& edges){
    ll level=0;
    vector<ll> level_graph(n+1,-1);
    queue<ll> q;
    q.push(1);
    vector<ll> visited_arr(n+1,-1);
    visited_arr[1]=1;
    while(!q.empty()){
        ll qSize=q.size();
        for(ll i=0;i<qSize;i++){
            ll curr=q.front();
            level_graph[curr]=level;
            q.pop();
            for(ll neighbor:adj[curr]){
                if(visited_arr[neighbor]==-1 && edges[curr][neighbor].first>edges[curr][neighbor].second){
                    visited_arr[neighbor]=1;
                    q.push(neighbor);
                }
            }
        }
        level++;
    }
    return level_graph;
}

void dfs(ll i,ll n,ll parent,vector<ll>& level_graph,vector<ll>& visited_arr,vector<ll>& path_visited,bool& flag,vector<vector<ll>>& adj,vector<vector<pair<ll,ll>>>& edges){
    if(i==n){
        path_visited[i]=parent;
        flag=true;
        return;
    }
    else if(visited_arr[i]==-1){
        if(flag) return;
        visited_arr[i]=1;
        path_visited[i]=parent;
        for(ll neighbor:adj[i]){
            if(flag) return;
            if(edges[i][neighbor].first==edges[i][neighbor].second) continue;
            if(level_graph[neighbor]<=level_graph[i]) continue;
            dfs(neighbor,n,i,level_graph,visited_arr,path_visited,flag,adj,edges);
        }
        if(flag) return;
        path_visited[i]=-1;
    }
}

int main(){
    ll n,m;
    ll temp1,temp2,temp3;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1,vector<ll>()); // {node}
    pair<ll,ll> p=make_pair(0,0);
    vector<vector<pair<ll,ll>>> edges(n+1,vector<pair<ll,ll>>(n+1,p)); //{edge weight(max flow),current_flow}
    for(ll i=0;i<m;i++){
        cin>>temp1>>temp2>>temp3;
        adj[temp1].emplace_back(temp2);
        adj[temp2].emplace_back(temp1);
        edges[temp1][temp2].first+=temp3;
        //reverse edges
        edges[temp2][temp1].first+=temp3;
        edges[temp2][temp1].second+=temp3;
    }
    bool done=true;
    ll max_flow=0;
    while(done){
        done=false;
        vector<ll> level_graph=make_level_graph(n,adj,edges);
        bool flag=false;
        vector<ll> path_visited(n+1,-1);
        vector<ll> visited_arr(n+1,-1);
        dfs(1,n,-1,level_graph,visited_arr,path_visited,flag,adj,edges);
        if(flag) {
            done=true;
            ll curr=n;
            ll mini=1e15;
            while(curr!=1){
                ll prev=path_visited[curr];
                mini=min(mini,edges[prev][curr].first-edges[prev][curr].second);
                curr=prev;
            }
            curr=n;
            while(curr!=1){
                ll prev=path_visited[curr];
                edges[prev][curr].second+=mini;
                edges[curr][prev].second-=mini;
                curr=prev;
            }
            max_flow+=mini;
        }
    }
    cout<<max_flow<<endl;
    return 0;
}