#include<bits/stdc++.h>
using namespace std;

int findUp(vector<int>& parent,vector<int>& rank_arr,int i){
    if(i==parent[i]) return i;
    int up=findUp(parent,rank_arr,parent[i]);
    parent[i]=up;
    return up;
}

int removeStones(vector<vector<int>>& stones) {
    unordered_map<int,int> x_mpp;
    unordered_map<int,int> y_mpp;
    int n=stones.size();
    vector<int> parent;
    for(int i=0;i<n;i++){
        parent.emplace_back(i);
    }
    vector<int> rank_arr(n,1);
    for(int i=0;i<n;i++){
        auto it=x_mpp.find(stones[i][0]);
        if(it==x_mpp.end()) x_mpp[stones[i][0]]=i;
        else{
            int up1=findUp(parent,rank_arr,x_mpp[stones[i][0]]);
            int up2=findUp(parent,rank_arr,i);
            if(rank_arr[up1]>rank_arr[up2]){
                parent[up2]=up1;
            }
            else if(rank_arr[up1]<rank_arr[up2]){
                parent[up1]=up2;
            }
            else{
                parent[up2]=up1;
                rank_arr[up1]+=rank_arr[up2];
            }
        }
        it=y_mpp.find(stones[i][1]);
        if(it==y_mpp.end()) y_mpp[stones[i][1]]=i;
        else{
            int up1=findUp(parent,rank_arr,y_mpp[stones[i][1]]);
            int up2=findUp(parent,rank_arr,i);
            if(rank_arr[up1]>rank_arr[up2]){
                parent[up2]=up1;
            }
            else if(rank_arr[up1]<rank_arr[up2]){
                parent[up1]=up2;
            }
            else{
                parent[up2]=up1;
                rank_arr[up1]+=rank_arr[up2];
            }
        }
    }
    int num_parents=0;
    unordered_map<int,int> unique;
    for(int i=0;i<n;i++){
        if(unique.find(parent[i])==unique.end()){
            unique[parent[i]]=1;
            num_parents++;
        }
    }
    return(n-num_parents);
}