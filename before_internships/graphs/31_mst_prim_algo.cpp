#include<bits/stdc++.h>
using namespace std;
struct comp{
    bool operator()(vector<int>& vec1,vector<int>& vec2){
        if(vec2[2]>vec1[2]) return false;
        return true;
    }
};

int spanningTree(int V, vector<vector<int>> adj[]) {
    // code here
    priority_queue<vector<int>,vector<vector<int>>,comp> pq;
    vector<int> visited_arr(V,-1);
    pq.push(vector<int>{0,-1,0});
    int sum=0;
    while(!pq.empty()){
        while(!pq.empty() && visited_arr[pq.top()[0]]!=-1){
            pq.pop();
        }
        if(pq.empty()) break;
        vector<int> current=pq.top();
        visited_arr[current[0]]=1;
        sum+=current[2];
        pq.pop();
        for(vector<int> neighbor:adj[current[0]]){
            if(visited_arr[neighbor[0]]==-1){
                pq.push(vector<int>{neighbor[0],current[0],neighbor[1]});
            }
        }
    }
    return sum;
}