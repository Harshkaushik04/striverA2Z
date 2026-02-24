#include<bits/stdc++.h>
using namespace std;

int findUp(vector<int>& parent,vector<int>& size_arr,int u){
    if(u==parent[u]) return u;
    int up=findUp(parent,size_arr,parent[u]);
    parent[u]=up;
    return up;
}

int largestIsland(vector<vector<int>>& grid) {
    int maxi=0;
    int n=grid.size();
    vector<int> parents;
    for(int i=0;i<n*n;i++){
        parents.emplace_back(i);
    }
    vector<int> size_arr(n*n,1);
    int currentIndex,neighborIndex;
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int up1,up2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            currentIndex=i*n+j;
            if(grid[i][j]==0) continue;
            for(int k=0;k<4;k++){
                neighborIndex=(i+dx[k])*n+j+dy[k];
                if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<n && grid[i+dx[k]][j+dy[k]]==1){
                    up1=findUp(parents,size_arr,currentIndex);
                    up2=findUp(parents,size_arr,neighborIndex);
                    if(up1!=up2){
                        if(size_arr[up1]>=size_arr[up2]){
                            parents[up2]=up1;
                            size_arr[up1]+=size_arr[up2];
                            maxi=max(maxi,size_arr[up1]);
                        }
                        else{
                            parents[up1]=up2;
                            size_arr[up2]+=size_arr[up1];
                            maxi=max(maxi,size_arr[up2]);
                        }
                    }
                }
            }
        }
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            currentIndex=i*n+j;
            if(grid[i][j]==1) continue;
            temp=0;
            set<int> s;
            for(int k=0;k<4;k++){
                neighborIndex=(i+dx[k])*n+j+dy[k];
                if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<n && grid[i+dx[k]][j+dy[k]]==1){
                    up2=findUp(parents,size_arr,neighborIndex);
                    if(s.find(up2)==s.end()){
                        temp+=size_arr[up2];
                        s.insert(up2);
                    }
                }
            }
            maxi=max(maxi,temp+1);
        }
    }
    if(maxi==0) return 1;
    return maxi;
}