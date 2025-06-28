#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>& vec1,vector<int>& vec2){
    if(vec2[2]<vec1[2]) return false;
    else if(vec2[2]>vec1[2]) return true;
    else{
        if(vec2[0]<vec1[0]) return false;
        else if(vec2[0]>vec1[0]) return true;
        else{
            if(vec2[1]<=vec2[1]) return false;
            else return true;
        }
    }
    return true;
}

int findUp(vector<int>& size_arr,vector<int>& parent,int u){
    if(u==parent[u]) return u;
    int up=findUp(size_arr,parent,parent[u]);
    parent[u]=up;
    return up;
}

int spanningTree(int V, vector<vector<int>> adj[]){
    vector<int> size_arr(V,1);
    vector<int> parent(V,0);
    for(int i=0;i<V;i++) parent[i]=i;
    vector<vector<int>> sortedOrder;
    for(int i=0;i<V;i++){
        for(vector<int> edge:adj[i]){
            sortedOrder.emplace_back(vector<int>{i,edge[0],edge[1]});
        }
    }
    sort(sortedOrder.begin(),sortedOrder.end(),comp);
    int sum=0;
    int tempSize=sortedOrder.size();
    int up1,up2;
    for(int i=0;i<tempSize;i++){
        up1=findUp(size_arr,parent,sortedOrder[i][0]);
        up2=findUp(size_arr,parent,sortedOrder[i][1]);
        if(up1==up2) continue;
        if(size_arr[up1]>=size_arr[up2]){
            parent[up2]=up1;
            size_arr[up1]+=size_arr[up2];
            sum+=sortedOrder[i][2];
        }
        else{ //size_arr[up1]<size_arr[up2]
            parent[up1]=up2;
            size_arr[up2]+=size_arr[up1];
            sum+=sortedOrder[i][2];
        }
    }
    return sum;
}