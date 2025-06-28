#include<bits/stdc++.h>
using namespace std;

int findUp(vector<int>& size_arr,vector<int>& parent,int u){
    if(u==parent[u]) return u;
    int up=findUp(size_arr,parent,parent[u]);
    parent[u]=up;
    return up;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> size_arr(n,1);
    vector<int> parent;
    for(int i=0;i<n;i++){
        parent.emplace_back(i);
    }
    int up1,up2;
    int extraCables=0;
    for(vector<int> connection:connections){
        up1=findUp(size_arr,parent,connection[0]);
        up2=findUp(size_arr,parent,connection[1]);
        if(up1==up2){
            extraCables++;
            continue;
        }
        if(size_arr[up1]>=size_arr[up2]){
            parent[up2]=up1;
            size_arr[up1]+=size_arr[up2];
        }
        else if(size_arr[up1]<size_arr[up2]){
            parent[up1]=up2;
            size_arr[up2]+=size_arr[up1];
        }
    }
    int cablesNeeded=0;
   for(int i=0;i<n;i++){
    if(parent[i]==i) cablesNeeded++;
   }
   if(extraCables<cablesNeeded) return -1;
   return cablesNeeded;
}