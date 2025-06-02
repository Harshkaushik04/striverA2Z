#include<bits/stdc++.h>
using namespace std;

//given a dag

vector<int> topo_sort_kahn_algo(vector<vector<int>>& adj){
    queue<int> q;
    int N=adj.size();
    vector<int> indegree_arr(N,0);
    for(int i=0;i<N;i++){
        for(int num:adj[i]){
            indegree_arr[num]++;
        }
    }
    for(int i=0;i<N;i++){
        if(indegree_arr[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        ans.emplace_back(current);
        for(int num:adj[current]){
            indegree_arr[num]--;
            if(indegree_arr[num]==0) q.push(num);
        }
    }
    for(int i=0;i<N;i++){
        if(indegree_arr[i]!=0) return vector<int>();
    }
    return ans;
}