#include<bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<vector<int>> adj(n,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && isConnected[i][j]==1){
                adj[i].emplace_back(j);
            }
        }
    }
    vector<int> visited_arr(n,0);
    int ans=0;
    int current,tempSize;
    for(int i=0;i<n;i++){
        if(visited_arr[i]==0){
            ans++;
            queue<int> q;
            q.push(i);
            visited_arr[i]=1;
            while(!q.empty()){
                current=q.front();
                q.pop();
                for(int neighbor:adj[current]){
                    if(visited_arr[neighbor]==0){
                        visited_arr[neighbor]=1;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    return ans;
}