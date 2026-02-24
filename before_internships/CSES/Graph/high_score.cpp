#include<bits/stdc++.h>
using namespace std;

int main(){
    const long long INF=1e14;
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> edges;
    vector<vector<pair<long long,long long>>> adj(n+1,vector<pair<long long,long long>>());
    long long temp1,temp2,temp3;
    for(long long i=0;i<m;i++){
        cin>>temp1>>temp2>>temp3;
        edges.emplace_back(vector<long long>{temp1,temp2,temp3});
        adj[temp1].emplace_back(make_pair(temp2,temp3));
    }
    vector<long long> distance_arr(n+1,-INF);
    distance_arr[1]=0;
    for(int i=0;i<n-1;i++){
        for(vector<long long> edge:edges){
            if(distance_arr[edge[1]]<distance_arr[edge[0]]+edge[2] && distance_arr[edge[0]]!=-INF){
                distance_arr[edge[1]]=max(distance_arr[edge[1]],distance_arr[edge[0]]+edge[2]);
            }
        }
    }
    queue<long long> in_positive_cycle;
    for(vector<long long> edge:edges){
        if(distance_arr[edge[1]]<distance_arr[edge[0]]+edge[2] && distance_arr[edge[0]]!=-INF){
            distance_arr[edge[1]]=max(distance_arr[edge[1]],distance_arr[edge[0]]+edge[2]);
            in_positive_cycle.push(edge[1]);
        }
    }
    vector<long long> visited_arr(n+1,-1);
    bool impossible_flag=false;
    while(!in_positive_cycle.empty()){
        if(impossible_flag) break;
        int qSize=in_positive_cycle.size();
        for(int i=0;i<qSize;i++){
            if(impossible_flag) break;
            long long current=in_positive_cycle.front();
            in_positive_cycle.pop();
            for(pair<long long,long long> neighbor:adj[current]){
                if(visited_arr[neighbor.first]==-1){
                    visited_arr[neighbor.first]=1;
                    in_positive_cycle.push(neighbor.first);
                    if(neighbor.first==n){
                        impossible_flag=true;
                        break;
                    }
                }
            }
        }
    }
    if(impossible_flag) cout<<-1<<endl;
    else{
        cout<<distance_arr[n]<<endl;
    }
    return 0;
}