#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int parent,int grand_parent,vector<vector<int>>& adj,vector<int>& visited_arr,vector<int>& path_visited,vector<int>& path,bool& flag){
    if(flag) return;
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        path_visited[i]=1;
        path.emplace_back(i);
        for(int neighbor:adj[i]){
            if(flag) return;
            dfs(neighbor,i,parent,adj,visited_arr,path_visited,path,flag);
        }
        if(flag) return;
        path.pop_back();
        path_visited[i]=-1;
    }
    else if(path_visited[i]!=-1 && i!=grand_parent){
        flag=true;
        path.emplace_back(i);
        return;
    }
}

int number_ways(int tree_nodes,vector<int>& tree_from,vector<int>& tree_to,vector<int>& colors){
    vector<vector<int>> adj(tree_nodes+1,vector<int>());
    int n=tree_from.size();
    for(int i=0;i<n;i++){
        adj[tree_from[i]].emplace_back(tree_to[i]);
        adj[tree_to[i]].emplace_back(tree_from[i]);
    }
    int ans=0;
    for(int i=1;i<=tree_nodes;i++){
        for(int j=i+1;j<=tree_nodes;j++){
            bool flag=true;
            for(int adj_node:adj[i]){
                if(adj_node==j){
                    flag=false;
                    break;
                }
            }
            if(!flag) continue;
            adj[i].emplace_back(j);
            adj[j].emplace_back(i);
            //code
            vector<int> visited_arr(tree_nodes+1,-1);
            vector<int> path_visited(tree_nodes+1,-1);
            vector<int> path;
            flag=false;
            dfs(1,-1,-1,adj,visited_arr,path_visited,path,flag);
            int m=path.size();
            int to_find=path[m-1];
            int cycle_start=-1;
            int cycle_color=-1;
            for(int k=0;k<m-1;k++){
                if(path[k]==to_find){
                    cycle_start=k;
                    cycle_color=colors[path[k]-1];
                    break;
                }
            }
            flag=true;
            for(int k=cycle_start;k<m-1;k++){
                if(colors[path[k]-1]!=cycle_color){
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
            auto it=find(adj[i].begin(),adj[i].end(),j);
            adj[i].erase(it);
            it=find(adj[j].begin(),adj[j].end(),i);
            adj[j].erase(it);
        }
    }
    return ans;
}

int main(){
    int tree_nodes,num_edges,temp;
    vector<int> tree_from,tree_to,colors;
    cin>>tree_nodes>>num_edges;
    for(int i=0;i<num_edges;i++){
        cin>>temp;
        tree_from.emplace_back(temp);
    }
    for(int i=0;i<num_edges;i++){
        cin>>temp;
        tree_to.emplace_back(temp);
    }
    for(int i=0;i<tree_nodes;i++){
        cin>>temp;
        colors.emplace_back(temp);
    }
    cout<<number_ways(tree_nodes,tree_from,tree_to,colors)<<endl;
    return 0;
}