#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<vector<int>> &edges) {
    // Code here
    vector<vector<int>> adj(V,vector<int>());
    for(vector<int> vec:edges){
        adj[vec[0]].emplace_back(vec[1]);
        adj[vec[1]].emplace_back(vec[0]);
    }
    vector<int> visited_arr(V,-1);
    int temp;
    for(int i=0;i<V;i++){
        if(visited_arr[i]==-1){
            queue<int> q;
            q.push(i);
            int color=0,diff_color=1;
            visited_arr[i]=color;
            while(!q.empty()){
                int tempSize=q.size();
                for(int j=0;j<tempSize;j++){
                    int current=q.front();
                    q.pop();
                    for(int neighbor:adj[current]){
                        if(visited_arr[neighbor]==-1){
                            visited_arr[neighbor]=diff_color;
                            q.push(neighbor);
                        }
                        else if(visited_arr[neighbor]==diff_color) continue;
                        else return false; //visited_arr[neighbor]==color
                    }
                }
                //interchanging colors
                temp=diff_color;
                diff_color=color;
                color=temp;
            }
        }
    }
    return true;
}