#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses,vector<int>());
    for(vector<int> pre:prerequisites){
        adj[pre[1]].emplace_back(pre[0]);
    }
    queue<int> q;
    vector<int> indegree_arr(numCourses,0);
    for(int i=0;i<numCourses;i++){
        for(int num:adj[i]){
            indegree_arr[num]++;
        }
    }
    vector<int> ans;
    for(int i=0;i<numCourses;i++){
        if(indegree_arr[i]==0) q.push(i);
    }
    int count=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        count++;
        ans.emplace_back(current);
        for(int num:adj[current]){
            indegree_arr[num]--;
            if(indegree_arr[num]==0){
                q.push(num);
            }
        }
    }
    if(count!=numCourses) return vector<int>();
    return ans;
}