#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int V,vector<vector<int>>& adj){
    queue<int> q;
    vector<int> indegree_arr(V,0);
    for(int i=0;i<V;i++){
        for(int num:adj[i]){
            indegree_arr[num]++;
        }
    }
    for(int i=0;i<V;i++){
        if(indegree_arr[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        count++;
        for(int num:adj[current]){
            indegree_arr[num]--;
            if(indegree_arr[num]==0) q.push(num);
        }
    }
    if(count!=V) return true;
    return false;
}
